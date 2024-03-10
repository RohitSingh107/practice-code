# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter
import psycopg2


class BookscraperPipeline:
    def process_item(self, item, spider):
        adapter = ItemAdapter(item)

        # Strip white space
        field_names = adapter.field_names()
        for field_name in field_names:
            if field_name != "description":
                val = adapter.get(field_name, "")
                if type(val) == tuple:
                    val = val[0]
                adapter[field_name] = val.strip()

        lowercase_keys = ["category"]
        for lowercase_key in lowercase_keys:
            val = adapter.get(lowercase_key, "")
            adapter[lowercase_key] = val.lower()

        adapter["price"] = float(adapter.get("price", "").replace("£", ""))

        # Availability --> extract number of books in stock
        availability_string = adapter.get("availability", "")
        split_string_array = availability_string.split("(")
        if len(split_string_array) < 2:
            adapter["availability"] = 0
        else:
            availability_array = split_string_array[1].split(" ")
            adapter["availability"] = int(availability_array[0])

        # Stars --> convert text to number
        stars_string = adapter.get("stars", "")
        split_stars_array = stars_string.split(" ")
        stars_text_value = split_stars_array[1].lower()
        if stars_text_value == "zero":
            adapter["stars"] = 0
        elif stars_text_value == "one":
            adapter["stars"] = 1
        elif stars_text_value == "two":
            adapter["stars"] = 2
        elif stars_text_value == "three":
            adapter["stars"] = 3
        elif stars_text_value == "four":
            adapter["stars"] = 4
        elif stars_text_value == "five":
            adapter["stars"] = 5

        return item


class SavingToPostgresPipeline(object):
    def __init__(self):
        self.conn = psycopg2.connect(
            host="localhost", database="booksdb", user="rohit", password="q123"
        )
        
        ## Create cursor, used to execute commands
        self.cur = self.conn.cursor()

        ## Create books table if none exists
        self.cur.execute("""
        CREATE TABLE IF NOT EXISTS books(
            id SERIAL PRIMARY KEY, 
            title TEXT,
            price DECIMAL(10,2),
            category VARCHAR(255),
            description TEXT,
            stars INTEGER,
            availability INTEGER,
            book_url VARCHAR(255)
        );
        """)

    def process_item(self, item, spider):
        # Define insert statement
        self.cur.execute(
            """ insert into books (
            title, 
            price,
            category,
            description,
            stars,
            availability,
            book_url
            ) values (
                %s,
                %s,
                %s,
                %s,
                %s,
                %s,
                %s
                )""",
            (
                item["title"],
                item["price"],
                item["category"],
                str(item["description"]),
                item["stars"],
                item["availability"],
                item["book_url"]
            ),
        )

        self.conn.commit()
        return item

    def close_spider(self, spider):
        # Close cursor & connection to database
        self.cur.close()
        self.conn.close()

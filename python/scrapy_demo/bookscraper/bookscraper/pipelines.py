# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter


class BookscraperPipeline:
    def process_item(self, item, spider):


        adapter = ItemAdapter(item)

        # Strip white space
        field_names = adapter.field_names()
        for field_name in field_names:
            if field_name != 'description':
                val = adapter.get(field_name, "")
                if type(val) == tuple:
                    val = val[0]
                adapter[field_name] = val.strip()

        lowercase_keys = ['category']
        for lowercase_key in lowercase_keys:
            val = adapter.get(lowercase_key, "")
            adapter[lowercase_key] = val.lower()


        adapter['price'] = float(adapter.get('price', '').replace('£',''))

        ## Availability --> extract number of books in stock
        availability_string = adapter.get('availability', '')
        split_string_array = availability_string.split('(')
        if len(split_string_array) < 2:
            adapter['availability'] = 0
        else:
            availability_array = split_string_array[1].split(' ')
            adapter['availability'] = int(availability_array[0])


        ## Stars --> convert text to number
        stars_string = adapter.get('stars', '')
        split_stars_array = stars_string.split(' ')
        stars_text_value = split_stars_array[1].lower()
        if stars_text_value == "zero":
            adapter['stars'] = 0
        elif stars_text_value == "one":
            adapter['stars'] = 1
        elif stars_text_value == "two":
            adapter['stars'] = 2
        elif stars_text_value == "three":
            adapter['stars'] = 3
        elif stars_text_value == "four":
            adapter['stars'] = 4
        elif stars_text_value == "five":
            adapter['stars'] = 5



        return item

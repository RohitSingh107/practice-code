# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy



# # Serializers if not using pipelines
def serialize_title(value):
    return value[0]
#
# def serialize_price(value):
#     return value[0]



class BookItem(scrapy.Item):
    # title = scrapy.Field(serializer = serialize_title)
    title = scrapy.Field()
    price = scrapy.Field()
    category = scrapy.Field()
    description = scrapy.Field()
    stars = scrapy.Field()
    availability = scrapy.Field()
    book_url = scrapy.Field()

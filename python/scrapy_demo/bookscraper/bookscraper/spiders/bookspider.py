import scrapy
from bookscraper.items import BookItem

class BookspiderSpider(scrapy.Spider):
    name = "bookspider"
    allowed_domains = ["books.toscrape.com"]
    start_urls = ["https://books.toscrape.com"]

    def parse(self, response):
        books = response.xpath("//*/article[@class= 'product_pod']")

        for book in books:
            # yield {
            #     "name": book.xpath("h3/a/@title").get(),
            #     "price": book.xpath("div/p[@class = 'price_color']/text()").get(),
            #     "url": book.xpath("h3/a/@href").get(),
            # }

            book_url = book.xpath("h3/a/@href").get()
            yield response.follow(book_url, callback=self.parse_book)

        next_page = response.xpath("//*/a[text() = 'next']/@href").get()

        if next_page is not None:
            yield response.follow(next_page, callback=self.parse)

    def parse_book(self, response):

        book_item = BookItem()

        book_item['title'] = response.xpath("//*/h1/text()").get(),
        book_item['price'] = response.xpath("//*/h1/following-sibling::p[1]//text()").get(),
        book_item['category'] = response.xpath("(//*/li/a)[3]/text()").get()
        book_item['description'] = response.xpath("//*/div[@id='product_description']/following-sibling::p/text()").get()
        book_item['stars'] = response.xpath("//*/h1/following-sibling::p[3]/@class").get()
        book_item["availability"] = response.xpath("//*/table//tr[th[text()='Availability']]/td/text()").get()
        book_item['book_url'] = response.url

        yield book_item

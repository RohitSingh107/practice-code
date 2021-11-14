# Project from Code with Harry- Library

class Library:
    def __init__(self, name):

        self.name = name
        self.books = []

    def stock_books(self, book):
        if type(book) == list:
            self.books.extend(book)
        else:
            self.books.append(book)

    def book_issue(self, book):
        if book in self.books:
            self.books.remove(book)
            print(f"Issued {book}")
        else:
            return f"{book} is not available"

    def issued_return(self, book):
        self.books.append(book)
        print(f"{book} Returned")


class Student:
    def __init__(self, name):
        self.name = name
        self.borrowed_book = []

    def borrow_book(self, book):
        self.borrowed_book.append(book)
        return book

    def return_book(self, book):
        try:
            self.borrowed_book.remove(book)
            return book
        except ValueError:
            print(f"You don't have {book}")


def main():
    central_lib = Library("Central Library")
    central_lib.stock_books(["Algorithm", "Media", "Crime", "Social", "Environment", "Data"])
    rohit = Student("Rohit")

    wel_msg = f""" 
    ==== Welcome to Central Library ====
    
    1. To list the available books
    2. To borrow a book
    3. To return a borrowed book
    4. To donate book to {central_lib.name}
    5. Quit
    """
    while True:
        print(wel_msg)

        response = input("Enter your choice: ")
        if response == "1":
            print(sorted(central_lib.books))

        elif response == "2":
            chosen_book = input("Choose the Book: ")
            central_lib.book_issue(rohit.borrow_book(chosen_book))

        elif response == "3":
            book_name = input("Name of Book: ")
            central_lib.issued_return(rohit.return_book(book_name))

        elif response == "4":
            stock_book = input("Enter the book: ")
            central_lib.stock_books(stock_book)

        elif response == "5":
            break

        else:
            print("Please give valid response")


if __name__ == "__main__":
    main()

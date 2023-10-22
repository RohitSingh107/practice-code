// Package main provides ...
package main

import (
	"net/http"
	"github.com/gin-gonic/gin"
  "strconv"
	// "errors"
)

type Book struct {
	ID       uint `json: id`
	Title    string `json: "title"`
	Author   string `json: "author"`
	Quantity uint    `json: "quantity"`
}

var books = []Book{
	{ID: 1, Title: "In Search of Lost Time", Author: "Marcel Proust", Quantity: 2},
	{ID: 2, Title: "The Great Gatsby", Author: "F. Scott Fitzgerald", Quantity: 5},
	{ID: 3, Title: "War and Peace", Author: "Leo Tolstoy", Quantity: 6},
}

func getBooks(c *gin.Context) {
	c.IndentedJSON(http.StatusOK, books)
}

func getBook(c *gin.Context) {
	id := c.Param("id")
	for _, book := range books {

		if strconv.Itoa(int(book.ID)) == id {
			c.IndentedJSON(http.StatusOK, book)
			return
		}

	}
	c.IndentedJSON(http.StatusNotFound, nil)
}

func createBook(c *gin.Context) {

	var book Book

	if err := c.ShouldBindJSON(&book); err != nil {

		c.JSON(http.StatusBadRequest, err.Error())
		return
	}
	books = append(books, book)

	c.IndentedJSON(http.StatusCreated, book)
}

func updateBook(c *gin.Context) {
  id := c.Param("id")
  var book Book

  if err := c.ShouldBindJSON(&book); err != nil {
    c.JSON(http.StatusBadRequest, err.Error())
    return
  }
  for index, b := range books {
    if strconv.Itoa(int(b.ID)) == id {

      books[index] = book
      c.IndentedJSON(http.StatusCreated, book)
      return

    }
  }
	c.IndentedJSON(http.StatusNotFound, nil)
}

func deleteBook(c *gin.Context) {
  id := c.Param("id")



  for index, b := range books {
    if strconv.Itoa(int(b.ID)) == id {

      books = append(books[:index], books[index+1:]...)
      c.IndentedJSON(http.StatusNoContent, nil)
      return

    }
  }
	c.IndentedJSON(http.StatusNotFound, nil)

}

func main() {
	router := gin.Default()
	router.GET("/books", getBooks)
	router.GET("/book/:id", getBook)
	router.POST("/book", createBook)
  router.PUT("/book/:id", updateBook)
  router.DELETE("/book/:id", deleteBook)
	router.Run("localhost:8000")
}

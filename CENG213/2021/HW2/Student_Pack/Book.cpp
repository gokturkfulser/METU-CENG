#include "Book.h"

Book::Book() {

}

Book::Book(const std::string &isbn, const std::string &title, const std::string &author) {

    this->isbn = isbn;
    this->title = title;
    this->author = author;
}

const std::string &Book::getIsbn() const {

    return this->isbn;
}

const std::string &Book::getTitle() const {

    return this->title;
}

const std::string &Book::getAuthor() const {

    return this->author;
}

bool Book::operator<(const Book &rhs) const {
    /* TODO */
}

bool Book::operator>(const Book &rhs) const {
    /* TODO */
}

bool Book::operator==(const Book &rhs) const {
    /* TODO */
}

std::ostream &operator<<(std::ostream &os, const Book &book) {

    os << "Book(isbn: " << book.isbn << ", title: " << book.title << ", author: " << book.author << ")";
    return os;
}

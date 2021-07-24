#include "BookCatalog.h"

// PUBLIC MEMBER FUNCTIONS.

BookCatalog::BookCatalog() {

}

const BinarySearchTree<Category> &BookCatalog::getCategories() const {

    return this->categories;
}

void BookCatalog::addCategory(const std::string &categoryName) {
    /* TODO */
}

void BookCatalog::removeCategory(const std::string &categoryName) {
    /* TODO */
}

Category *BookCatalog::searchCategory(const std::string &categoryName) {
    /* TODO */
}

void BookCatalog::addBook(const std::string &categoryName, const Book &book) {
    /* TODO */
}

void BookCatalog::removeBookByIsbn(const std::string &isbn) {
    /* TODO */
}

void BookCatalog::removeBookByTitle(const std::string &title) {
    /* TODO */
}

Book *BookCatalog::searchBookByIsbn(const std::string &isbn) {
    /* TODO */
}

Book *BookCatalog::searchBookByTitle(const std::string &title) {
    /* TODO */
}

std::vector<Book *> BookCatalog::getListOfBooksByCategory(const std::string &categoryName) {
    /* TODO */
}

std::vector<Book *> BookCatalog::getListOfBooksByAuthor(const std::string &author) {
    /* TODO */
}

void BookCatalog::print() {

    // printing the binary search tree of categories.
    std::cout << "<BookCatalog>\n" << categories << "\n</BookCatalog>" << std::endl;
}

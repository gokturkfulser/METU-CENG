#include "Category.h"

Category::Category() {

}

Category::Category(const std::string &name) {

    this->name = name;
}

const std::string &Category::getName() const {

    return this->name;
}

void Category::addBook(const Book &book) {
    /* TODO */
}

void Category::removeBook(const Book &book) {
    /* TODO */
}

Book *Category::searchBook(const Book &book) {
    /* TODO */
}

std::vector<Book *> Category::getListOfBooks() {
    /* TODO */
}

bool Category::operator<(const Category &rhs) const {

    // compare category names.
    return this->name < rhs.name;
}

bool Category::operator>(const Category &rhs) const {

    // compare category names.
    return this->name > rhs.name;
}

bool Category::operator==(const Category &rhs) const {

    // compare category names for equality.
    return this->name == rhs.name;
}

std::ostream &operator<<(std::ostream &os, const Category &category) {

    os << "Category(name: " << category.name << ", books: " << category.books << ")";
    return os;
}

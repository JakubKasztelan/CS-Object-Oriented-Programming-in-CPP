#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <ostream>

struct Book {
    std::string author;
    std::string category;
    int pages;
    std::string status;

    Book() = default;

    Book(std::string a, std::string c, int p, std::string s) : author(a), category(c), pages(p), status(s) {
    }
};

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << book.author << " (" << book.category << ", " << book.pages << book.status << ")";
    return os;
}

#endif

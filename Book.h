#ifndef BOOK_H
#define BOOK_H

#include <string>

struct Book {
    std::string author;
    std::string category;
    int pages;
    std::string status;

    Book() = default;

    Book(std::string a, std::string c, int p, std::string s) : author(a), category(c), pages(p), status(s) {
    }
};

#endif

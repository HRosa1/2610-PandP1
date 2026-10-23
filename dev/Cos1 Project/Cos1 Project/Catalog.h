#pragma once
#include "Book.h"
#include <vector>
#include <string>

class Catalog
{
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void removeBook(int index);
    int searchByTitle(const std::string& title) const;
    int searchByAuthor(const std::string& author) const;
    int searchByISBN(const std::string& isbn) const;
    void displayAll() const;
    const Book& getBook(int index) const;
    int getCount() const;
};
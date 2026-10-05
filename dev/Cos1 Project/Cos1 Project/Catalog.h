#pragma once
#include "Book.h"
#include <vector>

class Catalog
{
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);

    void removeBook(int index);

    int searchByTitle(const std::string& title) const;

    int searchByAuthor(const std::string& author) const;

    void displayAll() const;

    int getCount() const { return books.size(); }
};
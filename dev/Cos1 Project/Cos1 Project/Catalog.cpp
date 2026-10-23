#include "Catalog.h"
#include <iostream>
#include <stdexcept>

void Catalog::addBook(const Book& book)
{
    books.push_back(book);
}

void Catalog::removeBook(int index)
{
    if (index < 0 || static_cast<size_t>(index) >= books.size())
        return;
    books.erase(books.begin() + index);
}

int Catalog::searchByTitle(const std::string& title) const
{
    for (size_t i = 0; i < books.size(); i++)
    {
        if (books[i].getTitle() == title)
            return static_cast<int>(i);
    }
    return -1;
}

int Catalog::searchByAuthor(const std::string& author) const
{
    for (size_t i = 0; i < books.size(); i++)
    {
        if (books[i].getAuthor() == author)
            return static_cast<int>(i);
    }
    return -1;
}

int Catalog::searchByISBN(const std::string& isbn) const
{
    for (size_t i = 0; i < books.size(); i++)
    {
        if (books[i].getISBN() == isbn)
            return static_cast<int>(i);
    }
    return -1;
}

void Catalog::displayAll() const
{
    if (books.empty())
    {
        std::cout << "Catalog is empty." << std::endl;
        return;
    }
    for (size_t i = 0; i < books.size(); i++)
    {
        std::cout << i + 1 << ". ";
        books[i].display();
    }
}

const Book& Catalog::getBook(int index) const
{
    if (index < 0 || static_cast<size_t>(index) >= books.size())
        throw std::out_of_range("Invalid book index");
    return books[index];
}

int Catalog::getCount() const { return static_cast<int>(books.size()); }
#include "Catalog.h"
#include <iostream>

void Catalog::addBook(const Book& book)
{
    books.push_back(book);
}

void Catalog::removeBook(int index)
{
    if (index >= 0 && index < books.size())
    {
        books.erase(books.begin() + index);
        std::cout << "Book removed." << std::endl;
    }
    else
    {
        std::cout << "Invalid index." << std::endl;
    }
}

int Catalog::searchByTitle(const std::string& title) const
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getTitle() == title)
        {
            return i;
        }
    }
    return -1;
}

int Catalog::searchByAuthor(const std::string& author) const
{
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].getAuthor() == author)
        {
            return i;
        }
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
    for (int i = 0; i < books.size(); i++)
    {
        std::cout << i + 1 << ". ";
        books[i].display();
    }
}
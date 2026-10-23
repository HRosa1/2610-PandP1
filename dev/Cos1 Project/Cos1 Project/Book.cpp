#include "Book.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& author,
    const std::string& isbn, bool available)
    : title(title), author(author), isbn(isbn), available(available)
{
}

void Book::display() const
{
    std::cout << title << " by " << author
        << " (ISBN: " << isbn << ") - "
        << (available ? "Available" : "Checked Out") << std::endl;
}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getISBN() const { return isbn; }
bool Book::isAvailable() const { return available; }
void Book::setAvailable(bool val) { available = val; }
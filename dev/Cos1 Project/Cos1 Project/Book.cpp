#include "Book.h"
#include <iostream>

Book::Book(const std::string& _title, const std::string& _author, const std::string& _isbn)
    : title(_title), author(_author), isbn(_isbn), available(true)
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
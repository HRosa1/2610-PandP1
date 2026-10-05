#include "Book.h"

Book::Book(std::string _title, std::string _author, std::string _isbn)
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

bool Book::isAvailable() const { return available; }

void Book::setAvailable(bool val) { available = val; }
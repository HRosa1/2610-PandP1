#pragma once
#include <string>
#include <iostream>

class Book
{
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

public:
    Book(std::string _title, std::string _author, std::string _isbn)
        : title(_title), author(_author), isbn(_isbn), available(true)
    {
    }

    void display() const {
        std::cout << title << " by " << author
            << " (ISBN: " << isbn << ") - "
            << (available ? "Available" : "Checked Out") << std::endl;
    }

    std::string getTitle() const { return title; }

    std::string getAuthor() const { return author; }

    bool isAvailable() const { return available; }

    void setAvailable(bool val) { available = val; }
};
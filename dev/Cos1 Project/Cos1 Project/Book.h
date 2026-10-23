#pragma once
#include <string>

class Book
{
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

public:
    Book(const std::string& title, const std::string& author,
        const std::string& isbn, bool available = true);

    void display() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    bool isAvailable() const;
    void setAvailable(bool val);
};
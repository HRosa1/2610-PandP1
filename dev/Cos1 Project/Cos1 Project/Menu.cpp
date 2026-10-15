#include "Menu.h"
#include "Book.h"
#include "Loan.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

Menu::Menu(Catalog& catalog) : catalog(catalog)
{
}

int Menu::readInt(const std::string& prompt)
{
    while (true)
    {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        try
        {
            size_t pos;
            int value = std::stoi(input, &pos);
            if (pos != input.size())
                throw std::invalid_argument("trailing characters");
            return value;
        }
        catch (const std::exception&)
        {
            std::cout << "Please enter a valid number." << std::endl;
        }
    }
}

std::string Menu::readString(const std::string& prompt)
{
    std::string value;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, value);
        if (!value.empty()) return value;
        std::cout << "Input cannot be empty." << std::endl;
    }
}

bool Menu::validateDate(int day, int month, int year)
{
    if (year < 2000 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    return true;
}

Member* Menu::findMember(int id)
{
    for (auto& m : members)
    {
        if (m.getId() == id)
            return &m;
    }
    return nullptr;
}

void Menu::handleAddBook()
{
    std::string title = readString("Title: ");
    std::string author = readString("Author: ");
    std::string isbn = readString("ISBN: ");
    catalog.addBook(Book(title, author, isbn));
    std::cout << "Book added." << std::endl;
}

void Menu::handleSearch()
{
    std::cout << "Search by: 1) Title  2) Author  3) ISBN\nChoice: ";
    int type = readInt("");

    std::string query;
    if (type == 1)       query = readString("Title: ");
    else if (type == 2)  query = readString("Author: ");
    else if (type == 3)  query = readString("ISBN: ");
    else { std::cout << "Invalid choice." << std::endl; return; }

    int idx = (type == 1) ? catalog.searchByTitle(query)
        : (type == 2) ? catalog.searchByAuthor(query)
        : catalog.searchByISBN(query);

    if (idx != -1)
    {
        std::cout << "Found:" << std::endl;
        catalog.getBook(idx).display();
    }
    else
    {
        std::cout << "Not found." << std::endl;
    }
}

void Menu::handleRemoveBook()
{
    int index = readInt("Book number to remove: ");
    if (index < 1 || index > catalog.getCount())
    {
        std::cout << "Invalid book number." << std::endl;
        return;
    }

    Book& book = catalog.getBook(index - 1);
    if (!book.isAvailable())
    {
        std::cout << "Cannot remove a book that is currently checked out." << std::endl;
        return;
    }

    catalog.removeBook(index - 1);
    std::cout << "Book removed." << std::endl;
}

void Menu::handleCheckout()
{
    int memberId = readInt("Member ID: ");
    int bookNum = readInt("Book number: ");

    Member* member = findMember(memberId);
    if (!member)
    {
        std::cout << "Member not found." << std::endl;
        return;
    }
    if (bookNum < 1 || bookNum > catalog.getCount())
    {
        std::cout << "Invalid book number." << std::endl;
        return;
    }

    Book& book = catalog.getBook(bookNum - 1);
    if (!book.isAvailable())
    {
        std::cout << "That book is already checked out." << std::endl;
        return;
    }

    int day = readInt("Checkout day: ");
    int month = readInt("Checkout month: ");
    int year = readInt("Checkout year: ");

    if (!validateDate(day, month, year))
    {
        std::cout << "Invalid date. Please use a valid day (1-31), month (1-12), year (2000+)." << std::endl;
        return;
    }

    Loan loan(book.getTitle(), memberId, day, month, year);
    member->checkOut(loan);
    book.setAvailable(false);
    std::cout << "Book checked out." << std::endl;
}

void Menu::handleReturn()
{
    int memberId = readInt("Member ID: ");
    int bookNum = readInt("Book number: ");

    Member* member = findMember(memberId);
    if (!member)
    {
        std::cout << "Member not found." << std::endl;
        return;
    }
    if (bookNum < 1 || bookNum > catalog.getCount())
    {
        std::cout << "Invalid book number." << std::endl;
        return;
    }

    Book& book = catalog.getBook(bookNum - 1);
    if (member->returnBook(book.getTitle()))
    {
        book.setAvailable(true);
        std::cout << "Book returned." << std::endl;
    }
    else
    {
        std::cout << "That book is not checked out to this member." << std::endl;
    }
}

void Menu::handleShowLoans()
{
    int memberId = readInt("Member ID: ");
    Member* member = findMember(memberId);
    if (!member)
    {
        std::cout << "Member not found." << std::endl;
        return;
    }

    int day = readInt("Today's day: ");
    int month = readInt("Today's month: ");
    int year = readInt("Today's year: ");

    if (!validateDate(day, month, year))
    {
        std::cout << "Invalid date." << std::endl;
        return;
    }

    member->displayLoans(day, month, year);
}

void Menu::run()
{
    bool running = true;

    while (running)
    {
        std::cout << "\n===== ShelfLife Library =====\n"
            << "1. Add book\n"
            << "2. Display all books\n"
            << "3. Search\n"
            << "4. Remove book\n"
            << "5. Register member\n"
            << "6. Check out book\n"
            << "7. Return book\n"
            << "8. Show member's loans\n"
            << "0. Exit\n"
            << "Choice: ";

        int choice = readInt("");

        switch (choice)
        {
        case 1:  handleAddBook(); break;
        case 2:  catalog.displayAll(); break;
        case 3:  handleSearch(); break;
        case 4:  handleRemoveBook(); break;
        case 5:
        {
            int id = readInt("Member ID: ");
            std::string name = readString("Name: ");
            members.push_back(Member(id, name));
            std::cout << "Member registered." << std::endl;
            break;
        }
        case 6:  handleCheckout(); break;
        case 7:  handleReturn(); break;
        case 8:  handleShowLoans(); break;
        case 0:  running = false; std::cout << "Goodbye!" << std::endl; break;
        default: std::cout << "Invalid choice." << std::endl; break;
        }
    }
}
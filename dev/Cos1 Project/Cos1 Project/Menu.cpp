#include "Menu.h"
#include <iostream>

Menu::Menu(Catalog& _catalog) : catalog(_catalog)
{
}

int Menu::readInt(const std::string& prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value) return value;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Please enter a valid number." << std::endl;
    }
}

std::string Menu::readString(const std::string& prompt)
{
    std::string value;
    while (true)
    {
        std::cout << prompt;
        std::cin.ignore();
        std::getline(std::cin, value);
        if (!value.empty()) return value;
        std::cout << "Input cannot be empty." << std::endl;
    }
}

Member* Menu::findMember(int id)
{
    for (size_t i = 0; i < members.size(); i++)
    {
        if (members[i].getId() == id)
        {
            return &members[i];
        }
    }
    return nullptr;
}

void Menu::run()
{
    int choice;
    bool running = true;

    while (running)
    {
        std::cout << "\n===== ShelfLife Library =====\n"
            << "1. Add book\n"
            << "2. Display all books\n"
            << "3. Search by title\n"
            << "4. Search by author\n"
            << "5. Remove book\n"
            << "6. Register member\n"
            << "7. Check out book\n"
            << "8. Return book\n"
            << "9. Show member's loans\n"
            << "0. Exit\n"
            << "Choice: ";

        choice = readInt("");

        if (choice == 1)
        {
            std::string title = readString("Title: ");
            std::string author = readString("Author: ");
            std::string isbn = readString("ISBN: ");
            catalog.addBook(Book(title, author, isbn));
            std::cout << "Book added." << std::endl;
        }
        else if (choice == 2)
        {
            catalog.displayAll();
        }
        else if (choice == 3)
        {
            std::string title = readString("Search title: ");
            int idx = catalog.searchByTitle(title);
            if (idx != -1)
            {
                std::cout << "Found: " << title << std::endl;
            }
            else
            {
                std::cout << "Not found." << std::endl;
            }
        }
        else if (choice == 4)
        {
            std::string author = readString("Search author: ");
            int idx = catalog.searchByAuthor(author);
            if (idx != -1)
            {
                std::cout << "Found a book by " << author << std::endl;
            }
            else
            {
                std::cout << "Not found." << std::endl;
            }
        }
        else if (choice == 5)
        {
            int index = readInt("Book number to remove: ");
            catalog.removeBook(index - 1);
        }
        else if (choice == 6)
        {
            int id = readInt("Member ID: ");
            std::string name = readString("Name: ");
            members.push_back(Member(id, name));
            std::cout << "Member registered." << std::endl;
        }
        else if (choice == 7)
        {
            int memberId = readInt("Member ID: ");
            int bookNum = readInt("Book number: ");

            Member* member = findMember(memberId);
            if (!member)
            {
                std::cout << "Member not found." << std::endl;
            }
            else if (bookNum < 1 || bookNum > catalog.getCount())
            {
                std::cout << "Invalid book number." << std::endl;
            }
            else
            {
                Book& book = catalog.getBook(bookNum - 1);
                if (!book.isAvailable())
                {
                    std::cout << "That book is already checked out." << std::endl;
                }
                else
                {
                    int day = readInt("Checkout day: ");
                    int month = readInt("Checkout month: ");
                    int year = readInt("Checkout year: ");
                    Loan loan(book.getTitle(), memberId, day, month, year);
                    member->checkOut(loan);
                    book.setAvailable(false);
                }
            }
        }
        else if (choice == 8)
        {
            int memberId = readInt("Member ID: ");
            int bookNum = readInt("Book number: ");

            Member* member = findMember(memberId);
            if (!member)
            {
                std::cout << "Member not found." << std::endl;
            }
            else if (bookNum < 1 || bookNum > catalog.getCount())
            {
                std::cout << "Invalid book number." << std::endl;
            }
            else
            {
                Book& book = catalog.getBook(bookNum - 1);
                member->returnBook(book.getTitle());
                book.setAvailable(true);
            }
        }
        else if (choice == 9)
        {
            int memberId = readInt("Member ID: ");
            Member* member = findMember(memberId);
            if (!member)
            {
                std::cout << "Member not found." << std::endl;
            }
            else
            {
                int day = readInt("Today's day: ");
                int month = readInt("Today's month: ");
                int year = readInt("Today's year: ");
                member->displayLoans(day, month, year);
            }
        }
        else if (choice == 0)
        {
            running = false;
            std::cout << "Goodbye!" << std::endl;
        }
        else
        {
            std::cout << "Invalid choice." << std::endl;
        }
    }
}
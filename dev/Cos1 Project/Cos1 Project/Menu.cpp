#include "Menu.h"
#include <iostream>
#include <string>

Menu::Menu(Catalog& _catalog) : catalog(_catalog)
{
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
        std::cin >> choice;

        if (choice == 1)
        {
            std::string title, author, isbn;
            std::cout << "Title: ";
            std::cin >> title;
            std::cout << "Author: ";
            std::cin >> author;
            std::cout << "ISBN: ";
            std::cin >> isbn;
            catalog.addBook(Book(title, author, isbn));
            std::cout << "Book added." << std::endl;

        }
        else if (choice == 2)
        {
            catalog.displayAll();
        }
        else if (choice == 3)
        {
            std::string title;
            std::cout << "Search title: ";
            std::cin >> title;
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
            std::string author;
            std::cout << "Search author: ";
            std::cin >> author;
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
            int index;
            std::cout << "Book number to remove: ";
            std::cin >> index;
            catalog.removeBook(index - 1);

        }
        else if (choice == 6)
        {
            std::string name;
            int id;
            std::cout << "Member ID: ";
            std::cin >> id;
            std::cout << "Name: ";
            std::cin >> name;
            members.push_back(Member(id, name));
            std::cout << "Member registered." << std::endl;

        }
        else if (choice == 7)
        {
            int memberId, bookNum;
            std::cout << "Member ID: ";
            std::cin >> memberId;
            std::cout << "Book number: ";
            std::cin >> bookNum;
            for (int i = 0; i < members.size(); i++)
            {
                if (members[i].getId() == memberId)
                {
                    members[i].checkOut("Book #" + std::to_string(bookNum));
                    std::cout << "Checked out." << std::endl;
                    break;
                }
            }

        }
        else if (choice == 8)
        {
            int memberId, bookNum;
            std::cout << "Member ID: ";
            std::cin >> memberId;
            std::cout << "Book number: ";
            std::cin >> bookNum;
            for (int i = 0; i < members.size(); i++)
            {
                if (members[i].getId() == memberId)
                {
                    members[i].returnBook("Book #" + std::to_string(bookNum));
                    break;
                }
            }

        }
        else if (choice == 9)
        {
            int memberId;
            std::cout << "Member ID: ";
            std::cin >> memberId;
            for (int i = 0; i < members.size(); i++)
            {
                if (members[i].getId() == memberId)
                {
                    members[i].displayLoans();
                    break;
                }
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
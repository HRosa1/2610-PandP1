#include "Member.h"

Member::Member(int _id, std::string _name)
    : id(_id), name(_name)
{
}

int Member::getId() const { return id; }

std::string Member::getName() const { return name; }

void Member::checkOut(const std::string& bookTitle)
{
    checkedOut.push_back(bookTitle);
}

void Member::returnBook(const std::string& bookTitle)
{
    for (int i = 0; i < checkedOut.size(); i++)
    {
        if (checkedOut[i] == bookTitle)
        {
            checkedOut.erase(checkedOut.begin() + i);
            std::cout << "Book returned." << std::endl;
            return;
        }
    }
    std::cout << "That book is not checked out to this member." << std::endl;
}

void Member::displayLoans() const
{
    std::cout << name << " (ID: " << id << ") has "
        << checkedOut.size() << " book(s) out:" << std::endl;
    for (int i = 0; i < checkedOut.size(); i++)
    {
        std::cout << "  - " << checkedOut[i] << std::endl;
    }
}

int Member::getLoanCount() const { return checkedOut.size(); }
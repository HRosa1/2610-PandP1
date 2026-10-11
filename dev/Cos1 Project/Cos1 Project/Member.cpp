#include "Member.h"
#include <iostream>

Member::Member(int _id, const std::string& _name)
    : id(_id), name(_name)
{
}

int Member::getId() const { return id; }
std::string Member::getName() const { return name; }

void Member::checkOut(const Loan& loan)
{
    loans.push_back(loan);
    std::cout << "Book checked out." << std::endl;
}

void Member::returnBook(const std::string& bookTitle)
{
    for (size_t i = 0; i < loans.size(); i++)
    {
        if (loans[i].getBookTitle() == bookTitle)
        {
            loans.erase(loans.begin() + static_cast<int>(i));
            std::cout << "Book returned." << std::endl;
            return;
        }
    }
    std::cout << "That book is not checked out to this member." << std::endl;
}

void Member::displayLoans(int todayDay, int todayMonth, int todayYear) const
{
    std::cout << name << " (ID: " << id << ") has "
        << loans.size() << " book(s) out:" << std::endl;
    for (size_t i = 0; i < loans.size(); i++)
    {
        loans[i].display();
        if (loans[i].isOverdue(todayDay, todayMonth, todayYear))
        {
            std::cout << "    ** OVERDUE **" << std::endl;
        }
    }
}

int Member::getLoanCount() const { return static_cast<int>(loans.size()); }
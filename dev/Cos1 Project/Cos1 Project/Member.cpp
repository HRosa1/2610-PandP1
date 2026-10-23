#include "Member.h"
#include <iostream>
#include <iomanip>

Member::Member(int id, const std::string& name)
    : id(id), name(name)
{
}

int Member::getId() const { return id; }
std::string Member::getName() const { return name; }

void Member::checkOut(const Loan& loan)
{
    for (const auto& l : loans)
        if (l.getBookISBN() == loan.getBookISBN()) return;
    loans.push_back(loan);
}

bool Member::returnBook(const std::string& bookISBN)
{
    for (auto it = loans.begin(); it != loans.end(); ++it)
    {
        if (it->getBookISBN() == bookISBN)
        {
            loans.erase(it);
            return true;
        }
    }
    return false;
}

double Member::getFineForBook(const std::string& bookISBN,
    int todayDay, int todayMonth, int todayYear) const
{
    for (const auto& loan : loans)
    {
        if (loan.getBookISBN() == bookISBN)
            return loan.getFine(todayDay, todayMonth, todayYear);
    }
    return 0.0;
}

void Member::displayLoans(int todayDay, int todayMonth, int todayYear) const
{
    std::cout << name << " (ID: " << id << ") has "
        << loans.size() << " book(s) out:" << std::endl;

    double totalFines = 0.0;

    for (const auto& loan : loans)
    {
        loan.display();
        int days = loan.daysOverdue(todayDay, todayMonth, todayYear);
        if (days > 0)
        {
            double fine = loan.getFine(todayDay, todayMonth, todayYear);
            totalFines += fine;
            std::cout << "    ** OVERDUE by " << days
                << " day(s) | Fine: $" << std::fixed
                << std::setprecision(2) << fine << "**" << std::endl;
        }
    }

    if (totalFines > 0.0)
        std::cout << "Total outstanding fines: $" << std::fixed
        << std::setprecision(2) << totalFines << std::endl;
}

int Member::getLoanCount() const { return static_cast<int>(loans.size()); }
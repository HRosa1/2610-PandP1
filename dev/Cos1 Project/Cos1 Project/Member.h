#pragma once
#include <string>
#include <vector>
#include "Loan.h"

class Member
{
private:
    int id;
    std::string name;
    std::vector<Loan> loans;

public:
    Member(int id, const std::string& name);

    int getId() const;
    std::string getName() const;

    void checkOut(const Loan& loan);
    bool returnBook(const std::string& bookISBN);
    double getFineForBook(const std::string& bookISBN,
        int todayDay, int todayMonth, int todayYear) const;
    void displayLoans(int todayDay, int todayMonth, int todayYear) const;
    int getLoanCount() const;
};
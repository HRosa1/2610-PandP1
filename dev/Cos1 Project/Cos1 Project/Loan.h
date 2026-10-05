#pragma once
#include <string>
#include <iostream>

class Loan
{
private:
    std::string bookTitle;
    int memberId;
    int checkoutDay;
    int checkoutMonth;
    int checkoutYear;

    int dueDay;
    int dueMonth;
    int dueYear;

public:
    Loan(std::string _bookTitle, int _memberId,
        int _day, int _month, int _year);

    std::string getBookTitle() const;
    int getMemberId() const;

    void display() const;

    bool isOverdue(int todayDay, int todayMonth, int todayYear) const;
};
#pragma once
#include <string>

class Loan
{
    static constexpr int LOAN_DAYS = 14;
    static constexpr double FINE_PER_DAY = 0.50;

private:
    std::string bookISBN;
    int memberId;
    int checkoutDay, checkoutMonth, checkoutYear;
    int dueDay, dueMonth, dueYear;

public:
    Loan(const std::string& bookISBN, int memberId,
        int day, int month, int year);

    std::string getBookISBN() const;
    int getMemberId() const;

    void display() const;
    bool isOverdue(int todayDay, int todayMonth, int todayYear) const;
    int daysOverdue(int todayDay, int todayMonth, int todayYear) const;
    double getFine(int todayDay, int todayMonth, int todayYear) const;
};
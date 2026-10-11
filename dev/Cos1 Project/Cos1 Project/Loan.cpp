#include "Loan.h"
#include <iostream>

Loan::Loan(const std::string& _bookTitle, int _memberId,
    int _day, int _month, int _year)
    : bookTitle(_bookTitle), memberId(_memberId),
    checkoutDay(_day), checkoutMonth(_month), checkoutYear(_year),
    dueDay(_day + 14), dueMonth(_month), dueYear(_year)
{
    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    while (dueDay > daysInMonth[dueMonth - 1])
    {
        dueDay -= daysInMonth[dueMonth - 1];
        dueMonth++;
        if (dueMonth > 12)
        {
            dueMonth = 1;
            dueYear++;
        }
    }
}

std::string Loan::getBookTitle() const { return bookTitle; }
int Loan::getMemberId() const { return memberId; }

void Loan::display() const
{
    std::cout << bookTitle
        << " | Member ID: " << memberId
        << " | Checked out: " << checkoutMonth << "/" << checkoutDay << "/" << checkoutYear
        << " | Due: " << dueMonth << "/" << dueDay << "/" << dueYear
        << std::endl;
}

bool Loan::isOverdue(int todayDay, int todayMonth, int todayYear) const
{
    if (todayYear > dueYear) return true;
    if (todayYear < dueYear) return false;
    if (todayMonth > dueMonth) return true;
    if (todayMonth < dueMonth) return false;
    if (todayDay > dueDay) return true;
    return false;
}
#include "Loan.h"

Loan::Loan(std::string _bookTitle, int _memberId,
    int _day, int _month, int _year)
    : bookTitle(_bookTitle), memberId(_memberId),
    checkoutDay(_day), checkoutMonth(_month), checkoutYear(_year),
    dueDay(_day + 14), dueMonth(_month), dueYear(_year)
{
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
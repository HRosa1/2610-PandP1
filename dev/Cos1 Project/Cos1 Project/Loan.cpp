#include "Loan.h"
#include <iostream>

static int toAbsoluteDays(int d, int m, int y)
{
    static const int mdays[] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
    return y * 365 + mdays[m - 1] + d;
}

static int daysInMonth(int month)
{
    static const int base[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return base[month - 1];
}

Loan::Loan(const std::string& bookTitle, int memberId,
    int day, int month, int year)
    : bookTitle(bookTitle), memberId(memberId),
    checkoutDay(day), checkoutMonth(month), checkoutYear(year),
    dueDay(day + LOAN_DAYS), dueMonth(month), dueYear(year)
{
    while (dueDay > daysInMonth(dueMonth))
    {
        dueDay -= daysInMonth(dueMonth);
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
    return toAbsoluteDays(todayDay, todayMonth, todayYear)
         > toAbsoluteDays(dueDay, dueMonth, dueYear);
}

int Loan::daysOverdue(int todayDay, int todayMonth, int todayYear) const
{
    if (!isOverdue(todayDay, todayMonth, todayYear)) return 0;
    return toAbsoluteDays(todayDay, todayMonth, todayYear)
        - toAbsoluteDays(dueDay, dueMonth, dueYear);
}

double Loan::getFine(int todayDay, int todayMonth, int todayYear) const
{
    return daysOverdue(todayDay, todayMonth, todayYear) * FINE_PER_DAY;
}
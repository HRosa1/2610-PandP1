#include "Loan.h"
#include <iostream>

static bool isLeapYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

static int daysInMonth(int month, int year)
{
    static const int base[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && isLeapYear(year)) return 29;
    return base[month - 1];
}

static int toAbsoluteDays(int d, int m, int y)
{
    static const int mdays[] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
    int leap = (m > 2 && isLeapYear(y)) ? 1 : 0;
    return y * 365 + y / 4 - y / 100 + y / 400 + mdays[m - 1] + leap + d;
}

Loan::Loan(const std::string& bookISBN, int memberId,
    int day, int month, int year)
    : bookISBN(bookISBN), memberId(memberId),
    checkoutDay(day), checkoutMonth(month), checkoutYear(year),
    dueDay(day + LOAN_DAYS), dueMonth(month), dueYear(year)
{
    while (dueDay > daysInMonth(dueMonth, dueYear))
    {
        dueDay -= daysInMonth(dueMonth, dueYear);
        dueMonth++;
        if (dueMonth > 12)
        {
            dueMonth = 1;
            dueYear++;
        }
    }
}

std::string Loan::getBookISBN() const { return bookISBN; }
int Loan::getMemberId() const { return memberId; }

void Loan::display() const
{
    std::cout << bookISBN
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
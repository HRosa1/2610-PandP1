#pragma once
#include <string>
#include <vector>
#include <iostream>

class Member
{
private:
    int id;
    std::string name;
    std::vector<std::string> checkedOut;

public:
    Member(int _id, std::string _name);

    int getId() const;
    std::string getName() const;

    void checkOut(const std::string& bookTitle);
    void returnBook(const std::string& bookTitle);
    void displayLoans() const;
    int getLoanCount() const;
};
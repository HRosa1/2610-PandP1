#pragma once
#include "Catalog.h"
#include "Member.h"
#include <vector>
#include <string>

class Menu
{
private:
    Catalog& catalog;
    std::vector<Member> members;

    int readInt(const std::string& prompt);
    std::string readString(const std::string& prompt);
    Member* findMember(int id);
    bool validateDate(int day, int month, int year);

    void handleAddBook();
    void handleSearch();
    void handleRemoveBook();
    void handleCheckout();
    void handleReturn();
    void handleShowLoans();

public:
    explicit Menu(Catalog& catalog);
    void run();
};
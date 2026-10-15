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

    void handleAddBook();
    void handleSearch();
    void handleCheckout();
    void handleReturn();
    void handleShowLoans();

public:
    explicit Menu(Catalog& catalog);
    void run();
};
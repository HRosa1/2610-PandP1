#pragma once
#include "Catalog.h"
#include "Member.h"
#include <vector>

class Menu
{
private:
    Catalog& catalog;

    std::vector<Member> members;

public:
    Menu(Catalog& _catalog);

    void run();
};
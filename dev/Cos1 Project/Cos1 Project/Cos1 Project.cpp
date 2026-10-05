#include <iostream>
#include "Catalog.h"
#include "Menu.h"
#include "Loan.h"

int main()
{
    Catalog catalog;
    Menu menu(catalog);

    menu.run();
    return 0;
}
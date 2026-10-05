#include <iostream>
#include "Catalog.h"

int main()
{
    Catalog catalog;

    catalog.addBook(Book("The Hobbit", "J.R.R. Tolkien", "978-0547928227"));
    catalog.addBook(Book("Dune", "Frank Herbert", "978-0441172719"));
    catalog.addBook(Book("Neuromancer", "William Gibson", "978-0441569595"));

    catalog.displayAll();

    int result = catalog.searchByTitle("Dune");
    if (result != -1)
    {
        std::cout << "\nFound Dune at position " << result + 1 << std::endl;
    }

    return 0;
}
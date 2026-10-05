#include <iostream>
#include "Book.h"

int main()
{
    // Create a book and print it to make sure the class works
    Book b("The Hobbit", "J.R.R. Tolkien", "978-0547928227");
    b.display();
    return 0;
}
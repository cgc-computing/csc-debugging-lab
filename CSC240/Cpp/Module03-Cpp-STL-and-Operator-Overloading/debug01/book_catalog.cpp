/*
 * book_catalog.cpp
 * Keeps a library's catalog in a std::set so that the books are stored
 * without duplicates and come out ordered by publication year.
 */
#include <iostream>
#include <set>
#include <string>

struct Book {
    std::string title;
    int year;

    bool operator<(const Book& other) const
    {
        return year < other.year;
    }
};

void add_book(std::set<Book>& catalog, const std::string& title, int year)
{
    Book b{ title, year };
    if (catalog.insert(b).second) {
        std::cout << "Added   " << title << " (" << year << ")" << std::endl;
    } else {
        std::cout << "Skipped " << title << " (" << year << "): already in catalog" << std::endl;
    }
}

int main()
{
    std::set<Book> catalog;

    add_book(catalog, "The C Programming Language", 1978);
    add_book(catalog, "The Little Schemer", 1974);
    add_book(catalog, "Programming in Prolog", 1981);
    add_book(catalog, "Effective C++", 2005);
    add_book(catalog, "Learn Prolog Now", 2005);
    add_book(catalog, "The Little Schemer", 1974);

    std::cout << "\nCatalog by year (" << catalog.size() << " titles):" << std::endl;
    for (const Book& b : catalog) {
        std::cout << "  " << b.year << "  " << b.title << std::endl;
    }
    return 0;
}

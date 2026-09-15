// first_match.cpp
// Linear searches over a shelf of library books: find the first book by a
// given author, and find the first book that is currently checked out.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Book {
    string title;
    string author;
    bool checkedOut;
};

// Returns the index of the first book written by author, or -1 if none.
int findFirstByAuthor(const vector<Book>& books, const string& author) {
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].author == author) {
            return static_cast<int>(i);   // stop at the first match
        }
    }
    return -1;
}

// Returns the index of the first checked-out book, or -1 if none is out.
int findFirstCheckedOut(const vector<Book>& books) {
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i].checkedOut) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void report(const vector<Book>& books, const string& label, int index) {
    if (index < 0) {
        cout << label << ": none" << endl;
    } else {
        cout << label << ": #" << index << " \"" << books[index].title << "\"" << endl;
    }
}

int main() {
    vector<Book> shelf = {
        { "Dune",                  "Herbert", false },
        { "Emma",                  "Austen",  true  },
        { "Persuasion",            "Austen",  false },
        { "Neuromancer",           "Gibson",  true  },
        { "Sense and Sensibility", "Austen",  true  },
        { "Foundation",            "Asimov",  false }
    };

    report(shelf, "First book by Austen", findFirstByAuthor(shelf, "Austen"));
    report(shelf, "First book by Gibson", findFirstByAuthor(shelf, "Gibson"));
    report(shelf, "First book by Tolkien", findFirstByAuthor(shelf, "Tolkien"));
    report(shelf, "First checked-out book", findFirstCheckedOut(shelf));
    return 0;
}

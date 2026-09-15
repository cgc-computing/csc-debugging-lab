# Library Shelf Search

**Course:** CSC205 &nbsp;|&nbsp; **Module 10:** Searching &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program holds a shelf of `Book` records (title, author, checked-out flag) in a vector and performs linear searches: find the *first* book by a given author, and find the *first* book that is currently checked out. A search that finds nothing must report `none`.

## Expected Behavior

```
First book by Austen: #1 "Emma"
First book by Gibson: #3 "Neuromancer"
First book by Tolkien: none
First checked-out book: #1 "Emma"
```

## How to Run

```bash
g++ -std=c++17 -Wall -o first_match first_match.cpp
./first_match
```
(on Windows: `first_match.exe` or `.\first_match.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Both search functions should be fixed the same way.

## Think About

- How many books does each search examine before it returns? For the first Austen book, how many *should* it need to examine?
- If a shelf has three Austen books, which one does the loop's result variable hold when the loop ends? Why that one?
- What value should a search return when nothing matches? Can that value ever be confused with a real position on the shelf? Explain what the Tolkien search actually reported and why.

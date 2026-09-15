# Parts Inventory

**Course:** CSC240 &nbsp;|&nbsp; **Module 3:** C++ STL and Operator Overloading &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

The program keeps stock levels for three parts in a `std::map<std::string, int>` and answers three "is this in stock?" requests, one of them for a part the bin has never carried. It then prints how many distinct parts the map is tracking. Finally it takes a `std::vector<int>` of pending order numbers in which cancelled orders appear as `0`, drops the cancelled ones, and prints what remains.

## Expected Behavior

```
bolt: in stock
gasket: not stocked
nut: in stock
Distinct parts tracked: 3
  bolt 120
  nut 300
  washer 75
Pending orders (3): 102 117 130
```

## How to Run

```bash
g++ -std=c++17 -Wall -o parts_inventory parts_inventory.cpp
./parts_inventory
```

(on Windows: `parts_inventory.exe` or `.\parts_inventory.exe`)

No input is required.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the `std::map` and `std::vector`; the fixes are in how they are used.

## Think About

- The three yes/no answers are all correct, yet the map has changed size afterwards. What does `map[key]` promise to return, even when `key` has never been inserted? What must it do to keep that promise?
- Look up `std::map::find` and `std::map::count`. Why do they exist alongside `operator[]`?
- `std::remove` is given two iterators and a value. Can a function that only receives iterators change the *size* of the vector? What does it return, and what is the caller expected to do with that?
- In Java, `map.get(k)` on a missing key and `list.removeIf(...)` both behave the way their names suggest. Which STL habit would a Java programmer most likely carry over incorrectly here?

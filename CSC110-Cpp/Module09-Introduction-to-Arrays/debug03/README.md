# Reverse an Array in Place

**Course:** CSC110 &nbsp;|&nbsp; **Module 9:** Introduction to Arrays &nbsp;|&nbsp; **Activity:** debug03
**Language:** C++17

## Goal

The program reads six integers into an array, prints them, reverses the array in place with a
helper function `reverseArray`, and prints the result.

## Expected Behavior

Sample run (the user types `10 20 30 40 50 60`):

```
Enter 6 integers: 10 20 30 40 50 60
Original: 10 20 30 40 50 60
Reversed: 60 50 40 30 20 10
```

## How to Run

```bash
g++ -std=c++17 -Wall -o reverse_array reverse_array.cpp
./reverse_array
```

(on Windows: `reverse_array.exe` or `.\reverse_array.exe`)

Type six whole numbers separated by spaces, for example `10 20 30 40 50 60`, and press Enter.
Read any compiler messages carefully.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Keep `reverseArray`
as a separate function.

## Think About

- What does `reverseArray` believe the size of the array is? Add a temporary `cout` to check.
- What does an array parameter such as `int arr[]` actually become inside a function? What does `sizeof` measure then?
- Compare the two helper functions. How does `printArray` know how many elements to print?

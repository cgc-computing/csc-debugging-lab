# Remove the Even Numbers

**Course:** CSC205 &nbsp;|&nbsp; **Module 6:** Arrays, ArrayLists, Collections, and Iterators &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`removeEvens` deletes every even value from a `vector<int>` in place, keeping the odd values in their original order.

## Expected Behavior

```
Before: [2, 4, 6, 7, 8, 10, 11, 12]
After:  [7, 11]
Remaining count: 2
```

## How to Run

```bash
g++ -std=c++17 -Wall -o remove_evens remove_evens.cpp
./remove_evens
```
(on Windows: `remove_evens.exe` or `.\remove_evens.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the removal in place (do not build a second vector), and the fix should be small.

## Think About

- After `erase` removes the element at position `i`, which element now sits at position `i`? Which position will the loop examine next?
- Trace the loop by hand on `[2, 4, 6, 7]`, writing down `i`, the vector contents, and `v.size()` at each step.
- Does the same problem occur when you delete elements while walking a collection with an iterator? What happens to an iterator that pointed at the erased element?

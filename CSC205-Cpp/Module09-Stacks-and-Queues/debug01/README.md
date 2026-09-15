# Array Stack

**Course:** CSC205 &nbsp;|&nbsp; **Module 9:** Stacks and Queues &nbsp;|&nbsp; **Activity:** debug01
**Language:** C++17

## Goal

`ArrayStack` stores integers in a fixed-capacity array allocated with `new`, supporting `push`, `pop`, `peek`, `isEmpty`, `isFull`, and `size`. The driver pushes three values, looks at the top, pops everything, then pushes one more value and looks again.

## Expected Behavior

```
size after 3 pushes: 3
peek: 30
popping: 30 20 10
peek after pushing 7: 7
empty? no
```

## How to Run

```bash
g++ -std=c++17 -Wall -o array_stack array_stack.cpp
./array_stack
```
(on Windows: `array_stack.exe` or `.\array_stack.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the meaning of `top` that the class comment describes.

## Think About

- The comment says `top` is the *number of items stored*. After three pushes, what is `top`, and which array slot holds the most recently pushed value?
- Draw the array and trace `push(10)`, `push(20)`, `pop()` by hand, writing down `top` and the slot each operation touches.
- The value shown after pushing 7 is not 7 but a number from earlier in the run. Where in the array could that number still be sitting?

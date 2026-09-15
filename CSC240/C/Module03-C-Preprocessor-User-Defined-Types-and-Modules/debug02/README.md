# Integer Stack Module

**Course:** CSC240 &nbsp;|&nbsp; **Module 3:** C Preprocessor, User-Defined Types, and Modules &nbsp;|&nbsp; **Activity:** debug02
**Language:** C (C11)

## Goal

A small integer stack is split into a module: `stack.h` is the public interface, `stack.c` is the implementation, and `main.c` is a client that uses the stack to reverse six numbers and to evaluate the postfix expression `7 3 - 4 *`. The module also keeps a running count of push/pop operations, which `main.c` prints at the end.

## Expected Behavior

```
Reversed: 9 5 1 4 1 3
7 3 - 4 * = 16
Stack operations performed: 21
```

(Six pushes and six pops in the reversal, then five pushes and four pops in the expression; the final result is peeked, not popped. 12 + 9 = 21.)

## How to Run

All three files live in the same directory. Compile them together:

```bash
gcc -std=c11 -Wall -o stack_demo main.c stack.c
./stack_demo
```

(on Windows: `stack_demo.exe` or `.\stack_demo.exe`)

No input is required. Header files are never listed on the command line; they are pulled in by `#include`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. `main.c` should keep calling the stack the way it does now; the interface in `stack.h` is the one the client was written against.

## Think About

- Read the compiler message and identify *which file* it complains about. What are the two things it says disagree, and where does each one live?
- Once everything compiles, the build may still fail at a later stage. What is the difference between a compiler error and a linker error, and what does each one know about the other `.c` file?
- What does the word `static` mean when it appears on a variable *outside* any function? Who is allowed to see that variable?
- Should `main.c` be reaching into the module's bookkeeping directly? How would you redesign the interface so the client does not need to know how the count is stored?

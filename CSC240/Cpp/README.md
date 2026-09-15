# CSC240 — C++ Debugging Activities

**Course:** CSC240 Introduction to Programming Languages
**Language:** C++ (C++17). Compile with `g++ -std=c++17 -Wall` (Apple clang, GCC, or MinGW). Three activities also ask for `-fsanitize=address`.

These activities are for the weekly CS Work Lab. Each `debugNN` folder holds one short C++ program and a `README.md` that states what the program should do, how to build and run it, and a few questions to think about. Students compile and run the program, compare its behavior with the Expected Behavior, and then read the code to find and fix the problem. Every bug is tied to the module's concept (stream input and references, classes and virtual functions, copy control and ownership of heap memory, STL containers and operator overloading), and most come from carrying a Java habit into C++, so the fix should come from understanding the topic rather than from hunting typos. Within a module, `debug01` is the quickest and later activities take longer. Read compiler warnings before running; two activities put the first clue there.

| Module | Activities | Topic tags |
|---|---|---|
| `Module00-Introduction-to-Cpp` | 1 | debug01: visitor welcome badge |
| `Module01-OOP-in-Cpp-and-Virtual-Functions` | 3 | debug01: staff payroll by role · debug02: self-registering shapes · debug03: login sessions with buffers |
| `Module02-Memory-Management` | 3 | debug01: quiz score list class · debug02: theater ticket block · debug03: student honor roll |
| `Module03-Cpp-STL-and-Operator-Overloading` | 3 | debug01: library book catalog · debug02: money receipt arithmetic · debug03: parts inventory and pending orders |

**Total: 10 activities.**

Solutions, corrected sources, and the validation log are in `_solutions/` and are for instructors only.

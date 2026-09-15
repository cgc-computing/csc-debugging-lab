# CSC240 — C Debugging Activities

**Course:** CSC240 Introduction to Programming Languages
**Language:** C (C11). Compile with `gcc -std=c11 -Wall` (Apple clang, GCC, or MinGW). Two activities also ask for `-fsanitize=address`.

These activities are for the weekly CS Work Lab. Each `debugNN` folder holds one short C program and a `README.md` that states what the program should do, how to build and run it, and a few questions to think about. Students compile and run the program, compare its behavior with the Expected Behavior, and then read the code to find and fix the problem. Every bug is tied to the module's concept (pass by value, pointers and `malloc`, the preprocessor and multi-file compilation), so the fix should come from understanding the topic rather than from hunting typos. Within a module, `debug01` is the quickest and later activities take longer. Students coming from Java should read the compiler's warnings carefully; in several activities the warning is the first clue.

| Module | Activities | Topic tags |
|---|---|---|
| `Module01-Imperative-Control-Structures-Data-Types-Structures-and-Functions` | 2 | debug01: temperature readings statistics · debug02: course-section enrollment roster |
| `Module02-Pointers-and-Memory-Allocation` | 3 | debug01: sorting three integers · debug02: heap copies of five words · debug03: exam-score grade book |
| `Module03-C-Preprocessor-User-Defined-Types-and-Modules` | 3 | debug01: sensor readings and plot borders · debug02: multi-file integer stack module · debug03: monthly expense report by category |

**Total: 8 activities.**

Solutions, corrected sources, and the validation log are in `_solutions/` and are for instructors only.

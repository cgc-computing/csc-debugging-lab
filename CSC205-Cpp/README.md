# CSC205 — Object-Oriented Programming and Data Structures (C++)

**Language / tooling:** C++17, compiled with `g++ -std=c++17 -Wall` (validated with Apple clang on macOS; any current g++ or clang works). No build system and no external libraries — every activity is a single `.cpp` file (Module 4 debug01 also ships a small `students.csv`). Four activities ask you to add `-fsanitize=address` so that an invalid memory access is reported instead of silently misbehaving; their READMEs say so.

## How to use these in the Work Lab

Each module directory holds one to three activities (`debug01`, `debug02`, `debug03`, in increasing difficulty). Open the activity's `README.md`, read the Goal and Expected Behavior, compile and run the program exactly as shown, and compare what you see with what was promised. Then read the source, form a hypothesis about *why* it behaves that way, test the hypothesis, and fix the program so its output matches the Expected Behavior. The "Think About" questions are there to steer the group discussion; the point of the lab is being able to explain the behavior, not just make the output match. Do not rewrite programs wholesale — the structure is always sound and the bug is always tied to the module's concept.

## Modules and activities

| Module | Activities | Topics |
|---|---|---|
| `Module01-Cpp-Review-Software-Engineering-and-UML` | 1 | debug01: class roster lookup against a UML diagram |
| `Module02-Inheritance-and-Object-Oriented-Design` | 2 | debug01: employee and manager weekly pay · debug02: savings account with interest |
| `Module03-Polymorphism-and-Interfaces` | 2 | debug01: shape hierarchy area totals · debug02: store catalog with a `Sellable` interface |
| `Module04-File-IO-and-Exceptions` | 2 | debug01: exam averages from a CSV file · debug02: validated keyboard score reader |
| `Module05-Recursion-and-Analysis-of-Algorithms` | 3 | debug01: recursive factorial · debug02: recursive vowel counter · debug03: Fibonacci running time |
| `Module06-Arrays-ArrayLists-Collections-and-Iterators` | 2 | debug01: remove even numbers from a vector · debug02: day-to-day temperature changes |
| `Module07-Lists` | 3 | debug01: linked list add at both ends · debug02: linked list insert at index · debug03: linked list remove by value |
| `Module09-Stacks-and-Queues` | 3 | debug01: array-based stack · debug02: circular print-job queue · debug03: balanced-brackets checker |
| `Module10-Searching` | 2 | debug01: binary search for part numbers · debug02: library shelf linear search |
| `Module11-Sorting` | 3 | debug01: quiz score selection sort · debug02: card hand insertion sort · debug03: race time merge sort |
| `Module12-Introduction-to-Trees` | 2 | debug01: expression tree traversals · debug02: node count, leaf count, and height |
| `Module13-Binary-Search-Trees` | 3 | debug01: building a BST · debug02: member ID lookup with a BST · debug03: BST delete |
| `Module14-Introduction-to-Graphs` | 2 | debug01: campus walkway map with BFS · debug02: router hop counts with BFS |

**Total: 30 activities across 13 modules.** Modules 8 (midterm), E (ethics), 15 (review), and 16 (final) have no activities.

Solutions, corrected source files, and instructor notes are in `_solutions/` and are for instructors only.

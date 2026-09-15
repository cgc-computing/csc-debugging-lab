# CSC205 — Object-Oriented Programming and Data Structures (Java)

**Language / tooling:** Java 17 or later (`javac` / `java` from any current JDK; validated on JDK 25). No build tool, no external libraries — every activity is one to five `.java` files that compile with `javac *.java` and run with `java <DriverClass>`.

## How to use these in the Work Lab

Each module directory holds one to three activities (`debug01`, `debug02`, `debug03`, in increasing difficulty). Open the activity's `README.md`, read the Goal and Expected Behavior, compile and run the program exactly as shown, and compare what you see with what was promised. Then read the source, form a hypothesis about *why* it behaves that way, test the hypothesis, and fix the program so its output matches the Expected Behavior. The "Think About" questions are there to steer the group discussion; the point of the lab is being able to explain the behavior, not just make the output match. Do not rewrite programs wholesale — the structure is always sound and the bug is always tied to the module's concept.

## Modules and activities

| Module | Activities | Topics |
|---|---|---|
| `Module01-Java-Review-Software-Engineering-and-UML` | 1 | debug01: course roster lookup against a UML diagram |
| `Module02-Inheritance-and-Object-Oriented-Design` | 2 | debug01: payroll with manager bonuses · debug02: checking account with overdraft |
| `Module03-Polymorphism-and-Interfaces` | 2 | debug01: shape hierarchy area totals · debug02: honor roll ordering with `Comparable` |
| `Module04-File-IO-and-Exceptions` | 2 | debug01: class score report from CSV · debug02: letter-grade report writer |
| `Module05-Recursion-and-Analysis-of-Algorithms` | 3 | debug01: recursive factorial · debug02: recursive character count · debug03: Fibonacci running time |
| `Module06-Arrays-ArrayLists-Collections-and-Iterators` | 2 | debug01: remove even numbers from a list · debug02: long words with an iterator |
| `Module07-Lists` | 3 | debug01: linked list append · debug02: linked list insert at index · debug03: linked list remove by value |
| `Module09-Stacks-and-Queues` | 3 | debug01: array-based stack · debug02: circular array queue · debug03: balanced-brackets checker |
| `Module10-Searching` | 2 | debug01: binary search over exam scores · debug02: inventory search by item |
| `Module11-Sorting` | 3 | debug01: selection sort · debug02: insertion sort of temperatures · debug03: merge sort |
| `Module12-Introduction-to-Trees` | 2 | debug01: binary tree traversals · debug02: node count, leaf count, and height |
| `Module13-Binary-Search-Trees` | 3 | debug01: building a BST · debug02: student ID set with a BST · debug03: BST delete |
| `Module14-Introduction-to-Graphs` | 2 | debug01: campus shuttle map with BFS · debug02: router hop counts with BFS |

**Total: 30 activities across 13 modules.** Modules 8 (midterm), E (ethics), 15 (review), and 16 (final) have no activities.

Solutions, corrected source files, and instructor notes are in `_solutions/` and are for instructors only.

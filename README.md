# CS Work Lab Debugging Activities

This repo contains several intentionally buggy programs (sometimes more than one) 
organized by course and instructional module. They are meant for the optional weekly **CS Open Lab**:
pick the module you are studying, open a `debugXX` folder, run the program, compare it with the
Expected Behavior in its `README.md`, and work out *why* the code behaves the way it does before you
fix it. The goal is understanding the module's concept, not spotting a typo.

## Collections

| Directory | Course | Language / tooling | Modules | Activities |
|---|---|---|---|---|
| [`CSC101-Python/`](CSC101-Python/README.md) | CSC101 Introduction to Computer Science | Python 3 | 13 | 27 |
| [`CSC110-Java/`](CSC110-Java/README.md) | CSC110 Introduction to Computer Science (Java) | Java 17+ | 13 | 27 |
| [`CSC110-Cpp/`](CSC110-Cpp/README.md) | CSC110, parallel C++ collection | C++17 (`g++ -std=c++17 -Wall`) | 13 | 27 |
| [`CSC205-Java/`](CSC205-Java/README.md) | CSC205 Object-Oriented Programming and Data Structures | Java 17+ | 13 | 30 |
| [`CSC205-Cpp/`](CSC205-Cpp/README.md) | CSC205, parallel C++ collection | C++17 | 13 | 30 |
| [`CSC240/`](CSC240/README.md) | CSC240 Introduction to Programming Languages | C (C11), C++17, Scheme (DrRacket R5RS), Prolog (SWI) | 3 + 4 + 4 + 4 | 8 + 10 + 9 + 9 = 36 |
| [`CSC310-Python/`](CSC310-Python/README.md) | CSC310 Data Structures and Algorithms | Python 3 | 15 | 34 |
| [`CSC310-Cpp/`](CSC310-Cpp/README.md) | CSC310, parallel C++ collection | C++17 | 15 | 34 |

**Total: 245 activities.** Parallel collections (110 Java/C++, 205 Java/C++, 310 Python/C++) use
identical module directory names and the same activity concepts, so a lab section can mix languages.

## Sampley activity layout

```
<Course-Lang>/ModuleNN-Topic/debugNN/
├── README.md          Goal · Expected Behavior · How to Run · Your Task · Think About
└── program.ext        the program to debug (plus any small data file it reads)
```

Modules that are exams, reviews, syllabus-only, ethics, or optional content have no activities.

## Solutions

Every collection has a `_solutions/` folder that mirrors the student tree. Each activity's
`SOLUTION.md` gives the observed behavior, the bug, why it happens, the concept it illustrates, the
correction, and instructor notes on likely student questions and tempting wrong fixes; the corrected
source sits beside it. `_solutions/VALIDATION.md` records, per activity, whether the buggy symptom
and the corrected output were confirmed by execution. 
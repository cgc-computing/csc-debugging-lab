# CSC240 — Scheme Debugging Activities

**Course:** CSC240 Introduction to Programming Languages
**Language:** Scheme, R5RS. Use DrRacket with **Language → Choose Language → Other Languages → R5RS**, or `plt-r5rs file.scm` from the command line. No Racket-specific forms are used or needed.

These activities are for the weekly CS Work Lab. Each `debugNN` folder holds one short `.scm` file of definitions and a `README.md` that lists the sample calls to type in the Interactions window, the results they should give, and a few questions to think about. Students click Run, type the sample calls, compare the results (or error messages) with the Expected Behavior, and then read the definitions to find and fix the problem. Every bug is tied to the module's concept as *The Little Schemer* presents it (prefix notation and application, atoms and lists, natural recursion over flat and nested lists, higher-order procedures, pairs, and currying), so the fix should come from understanding the topic rather than from hunting typos. Reading Scheme's error messages word by word is part of the exercise. Within a module, `debug01` is the quickest and later activities take longer.

| Module | Activities | Topic tags |
|---|---|---|
| `Module00-Introduction-to-Scheme` | 1 | debug01: first-day geometry helpers |
| `Module01-Functional-Programming-Scheme-Terminology-Data-Types-and-Lists` | 2 | debug01: merging two lab-section rosters · debug02: lat predicates `atom?`, `lat?`, `member?` |
| `Module02-Writing-Recursive-List-Functions` | 3 | debug01: `rember` and `firsts` · debug02: `add-to-end`, `insertR`, `my-reverse` · debug03: counting atoms in nested lists |
| `Module03-Higher-Order-Functions-Pairs-and-Currying` | 3 | debug01: squares, evens, and their sum · debug02: curried adders and score bonuses · debug03: grade-record pairs and a right fold |

**Total: 9 activities.**

Solutions, corrected sources, and the validation log are in `_solutions/` and are for instructors only.

# CSC240 — Prolog Debugging Activities

**Course:** CSC240 Introduction to Programming Languages
**Language:** Prolog, SWI-Prolog (`swipl`, version 8 or 9). Run `swipl file.pl`, type the sample queries at `?-`, and finish with `halt.`

These activities are for the weekly CS Work Lab. Each `debugNN` folder holds one short `.pl` knowledge base and a `README.md` that lists the sample queries to type, the answers they should give, and a few questions to think about. Students load the file (watching for warnings while it loads), run the queries, compare the answers with the Expected Behavior, and then read the clauses to find and fix the problem. Every bug is tied to the module's concept (facts and queries, unification and arithmetic in rules, recursive list rules and clause order, cuts, negation, and the dynamic database), and most are the ones Java programmers make first in Prolog, so the fix should come from understanding the topic rather than from hunting typos. When a query hangs, press Ctrl-C then `a`. Within a module, `debug01` is the quickest and later activities take longer.

| Module | Activities | Topic tags |
|---|---|---|
| `Module00-Introduction-to-Prolog` | 1 | debug01: five-fact family tree |
| `Module01-Prolog-Introduction-Unification-Facts-Rules-and-Queries` | 2 | debug01: family rules (siblings, sisters, grandparents) · debug02: campus store prices and order costs |
| `Module02-Writing-Recursive-List-Rules` | 3 | debug01: `my_length` and `my_last` · debug02: reversing a list with `my_append` · debug03: ancestors in a family tree |
| `Module03-Advanced-Prolog-Topics-Cuts-and-Database-Manipulation` | 3 | debug01: tournament scores and `my_max` · debug02: students and course enrollment · debug03: dynamic sales tally |

**Total: 9 activities.**

Solutions, corrected sources, and the validation log are in `_solutions/` and are for instructors only.

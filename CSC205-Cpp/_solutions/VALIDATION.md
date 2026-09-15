# CSC205-Cpp — Validation Log

Environment: macOS, Apple clang 21.0.0 (`g++` is the clang driver), sources written for C++17. Every activity was copied to a scratch build directory, compiled with `g++ -std=c++17 -Wall` (plus `-fsanitize=address` for the four activities whose README asks for it), and run under a 30-second alarm (`perl -e 'alarm 30; exec @ARGV' ./program`) for both the buggy (student) version and the corrected (`_solutions/`) version. Module 4 debug02 was fed the README's five inputs on stdin. All 30 corrected versions compile with zero warnings under `-Wall`; none of the 30 buggy versions emits a warning either (the one compile-error activity, Module 3 debug02, emits errors only). No binaries or `.dSYM` bundles were left in the course tree. Module 4 debug01 was run from a directory containing `students.csv` (shipped in both the student and solution directories).

| Module | Activity | Source file | Bug type(s) | Buggy symptom confirmed? | Fixed output confirmed? | Method |
|---|---|---|---|---|---|---|
| Module01-Cpp-Review-Software-Engineering-and-UML | debug01 | roster.cpp | conceptual/design, logic | yes — all three lookups "not found"; `Roster::students` public vs UML `-` | yes | executed |
| Module02-Inheritance-and-Object-Oriented-Design | debug01 | employee_pay.cpp | conceptual/design | yes — Bob $800, Cara $600 (base rate used) while printed rate is right | yes | executed |
| Module02-Inheritance-and-Object-Oriented-Design | debug02 | savings_account.cpp | conceptual/design | yes — balance stays $1200 after `addInterest()` | yes | executed |
| Module03-Polymorphism-and-Interfaces | debug01 | shapes.cpp | conceptual/design | yes — three lines of `shape area = 0`, total 0 | yes | executed |
| Module03-Polymorphism-and-Interfaces | debug02 | catalog.cpp | syntax/compile, conceptual/design | yes — 3 errors: `price() override` hides `const` virtual; `Movie` abstract | yes | executed |
| Module04-File-IO-and-Exceptions | debug01 | grade_report.cpp (+ students.csv) | logic | yes — warning prints but `Dana: 88.6667` still reported, count 5 | yes | executed |
| Module04-File-IO-and-Exceptions | debug02 | score_reader.cpp | runtime, logic | yes — after `abc`, `Skipping invalid input:` repeats forever (killed by alarm) | yes — 3 / 255 / 85 | executed |
| Module05-Recursion-and-Analysis-of-Algorithms | debug01 | factorial.cpp | boundary, runtime | yes — 5!, 10!, 1! print, then segmentation fault (exit 139) on 0! | yes | executed |
| Module05-Recursion-and-Analysis-of-Algorithms | debug02 | count_vowels.cpp | logic | yes — every vowel-containing word reports 1 | yes | executed |
| Module05-Recursion-and-Analysis-of-Algorithms | debug03 | fibonacci_timing.cpp | conceptual/design (analysis) | yes — fib(30) 6 ms, fib(40) 480 ms (~80×) | yes — both 0 ms | executed |
| Module06-Arrays-ArrayLists-Collections-and-Iterators | debug01 | remove_evens.cpp | logic | yes — `[4, 7, 10, 11]`, count 4 | yes | executed |
| Module06-Arrays-ArrayLists-Collections-and-Iterators | debug02 | daily_changes.cpp | boundary, runtime | yes — weeks 1–2 fine, ASan SEGV on the empty week 3 (exit 134) | yes | executed |
| Module07-Lists | debug01 | linked_list.cpp | logic | yes — `[5 -> 10 -> 40]  (size 5)` | yes | executed |
| Module07-Lists | debug02 | insert_at.cpp | boundary, logic | yes — every insert rejected, list stays `[]`, size 0 | yes | executed |
| Module07-Lists | debug03 | remove_node.cpp | runtime (use-after-free), boundary | yes — ASan heap-use-after-free in `remove` on first removal (exit 134) | yes | executed |
| Module09-Stacks-and-Queues | debug01 | array_stack.cpp | boundary, logic | yes — peek 0, pops `0 30 20`, peek after push 7 is 20 | yes | executed |
| Module09-Stacks-and-Queues | debug02 | circular_queue.cpp | conceptual/design | yes — after 5 enqueues: every dequeue "nothing to print", 106/107 rejected | yes | executed |
| Module09-Stacks-and-Queues | debug03 | bracket_checker.cpp | logic, runtime | yes — `"((a + b)"` balanced, then ASan SEGV in `pop()` on `"a + b)"` (exit 134) | yes | executed |
| Module10-Searching | debug01 | binary_search.cpp | boundary, runtime (infinite loop) | yes — four found lines, then hang on part 300 (killed by alarm, exit 142) | yes | executed |
| Module10-Searching | debug02 | first_match.cpp | logic | yes — Austen `#4`, Tolkien `#0 "Dune"`, checked-out `#4` | yes | executed |
| Module11-Sorting | debug01 | selection_sort.cpp | logic | yes — `30 45 60 45 88 72 91`, 15 swaps, `NOT sorted!` | yes | executed |
| Module11-Sorting | debug02 | insertion_sort.cpp | boundary, runtime | yes — ASan heap-buffer-overflow (4 bytes before region) in pass 1 (exit 134) | yes | executed |
| Module11-Sorting | debug03 | merge_sort.cpp | logic, boundary | yes — `merged [0..3]: 301 350 377 377`; final `301 350 377 377 388 399 455 455` | yes | executed |
| Module12-Introduction-to-Trees | debug01 | expression_tree.cpp | logic, conceptual/design | yes — In-order line identical to Pre-order | yes | executed |
| Module12-Introduction-to-Trees | debug02 | tree_stats.cpp | logic, boundary | yes — nodes 4 (should be 9), heights 4 / 1 / 0 (should be 3 / 0 / -1) | yes | executed |
| Module13-Binary-Search-Trees | debug01 | bst_insert.cpp | logic, conceptual/design | yes — `In order: 50`, size 1, min = max = 50 | yes | executed |
| Module13-Binary-Search-Trees | debug02 | bst_contains.cpp | logic, boundary | yes — tree correct (7 members), every `isMember` "not a member" | yes | executed |
| Module13-Binary-Search-Trees | debug03 | bst_delete.cpp | logic, conceptual/design | yes — `remove 50: 40 60 60 65 70 (size 5)` | yes | executed |
| Module14-Introduction-to-Graphs | debug01 | campus_graph.cpp | conceptual/design | yes — `From Dorms (1 reachable): Dorms` | yes | executed |
| Module14-Introduction-to-Graphs | debug02 | bfs_distances.cpp | conceptual/design, logic | yes — hops 0 1 2 3 4, 7 queue pushes | yes | executed |

30 activities executed; 0 UNCHECKED.

## Notes and items worth a second look

- **Two intentional hangs**, one per module as the plan allows: Module 4 debug02 (failed `cin` never cleared, so the loop spins) and Module 10 debug01 (binary search with `high = mid`). Both READMEs tell students what a finished run looks like and to press Ctrl+C if the program does not stop.
- **Undefined behavior is made observable with the sanitizer.** Four activities read or dereference invalid memory (Module 6 debug02, Module 7 debug03, Module 9 debug03, Module 11 debug02). Their READMEs instruct `-fsanitize=address` and say to omit the flag if the compiler lacks it; the SOLUTION files describe both the sanitizer report and the unsanitized behavior. Without the sanitizer, Module 6 debug02 and Module 9 debug03 still crash deterministically (null-page reads); Module 11 debug02 usually *appears* to work without it, which the SOLUTION discusses as a teaching point; Module 7 debug03 without the sanitizer crashes on the head-removal case. Module 5 debug01 (unbounded recursion) and Module 9 debug01 (reads a zero-initialized slot inside the array) are deterministic without a sanitizer.
- **Module 5 debug03 timings are machine-dependent.** Observed 6 ms / 480 ms here; SOLUTION.md quotes 8 ms / 472 ms from an earlier run. The README already says only the ratio matters.
- **Module 4 debug02 with piped input** shows the prompts run together (`Score: Score: Score: Skipping invalid input:`) because typed input is not echoed; the SOLUTION's transcript shows the interactive form. Same behavior, different rendering.
- **Module 7 debug03 output ordering.** Because ASan aborts before `cout` is flushed, the partial `remove 30: ` text may print after the sanitizer report or not at all; the SOLUTION notes this.
- **Program length.** Modules 5 and 6 activities are short (22–41 lines) — below the "roughly 40–120 lines" guideline — because the recursion and vector programs are naturally small. Everything else is 46–115 lines.
- **Bug counts.** Module 1 has two by blueprint design (UML violation plus `==` on `char*`). Modules 2–4 have exactly one each. Modules 5–14 have one to three related bugs; where the same misconception appears twice or two related off-by-ones coexist (M07 debug02, M07 debug03, M09 debug01, M09 debug03, M10 debug02, M12 debug02) the count is listed as 2 with that note in the SOLUTION.
- **Error-type mix (30 activities):** 1 compile-error activity (3 %, under the ≤20 % cap); runtime symptom (crash, sanitizer abort, or hang) primary in 7 (≈23 %); logic/boundary primary in 14 (≈47 %); conceptual/design primary in 8 (≈27 %).
- **Standard-library use** is limited to what Module 6 introduces: `vector` everywhere from Module 6 on, `std::queue` as the BFS work queue in Module 14, `<chrono>` for timing in Module 5 debug03, and `<sstream>`/`<fstream>` in Module 4. Lists, stacks, the circular queue, trees, and the graph adjacency structure are hand-written and are where the bugs live.
- **Compiler-message line numbers** quoted in Module 3 debug02's SOLUTION (`catalog.cpp:35`, `:15`, `:50`) match the shipped file on Apple clang 21; other compilers word the first error differently (the SOLUTION quotes the GNU wording too).

# CSC110-Cpp — Validation Log

Platform: macOS, Apple clang (`g++ -std=c++17 -Wall`). Each buggy program was compiled and run
with the README's sample input (5-second timeout); the symptom was compared with `SOLUTION.md` →
Observed Behavior. Each corrected program was compiled with `-Wall` (all 27 compile with zero
warnings) and run with the same input; the output was compared with the README → Expected
Behavior. Binaries were built in a scratch directory outside the tree. Module 9 debug01 was
additionally run three times under `-fsanitize=address` to confirm the report is reliable.

| Module | Activity | Source file | Bug type(s) | Buggy symptom confirmed? | Fixed output confirmed? | Method |
|---|---|---|---|---|---|---|
| Module01-Introduction-to-Computing-in-Cpp | debug01 | quote_printer.cpp | logic | yes — quotation and attribution run together on one line | yes | executed |
| Module02-Data-and-Expressions | debug01 | test_average.cpp | logic | yes — `Average: 89` | yes — `89.6667` | executed |
| Module02-Data-and-Expressions | debug02 | receipt.cpp | logic | yes — `Tip (15%): $7`, `Total: $59.4` | yes — `$7.86`, `$60.26` | executed |
| Module03-Using-Classes-and-Objects | debug01 | name_formatter.cpp | conceptual/design | yes — `Middle name: King Lov` | yes | executed |
| Module03-Using-Classes-and-Objects | debug02 | high_score.cpp | runtime | yes — name empty, `Name length: 0` | yes — `Maria Santos`, 12 | executed |
| Module04-Control-Structures-Conditionals | debug01 | letter_grade.cpp | logic | yes — 85/93/71/64 all print `D`, 42 prints `F` | yes — B/A/C/D/F | executed |
| Module04-Control-Structures-Conditionals | debug02 | member_discount.cpp | logic | yes — `G` gives 10 %, `$72`; S/B/X correct | yes — `G` gives 20 %, `$64` | executed |
| Module05-Control-Structures-Loops | debug01 | sum_to_n.cpp | boundary | yes — four trace lines, sum 10 | yes — five lines, sum 15 | executed |
| Module05-Control-Structures-Loops | debug02 | countdown.cpp | logic | yes — `-Wempty-body` warning; prints only `T-minus 0` | yes | executed |
| Module05-Control-Structures-Loops | debug03 | quiz_average.cpp | logic | yes — `Scores entered: 4`, `Average: 59.75`; lone `-1` gives count 1 | yes — 3 / 80; lone `-1` gives no-scores message | executed |
| Module06-User-Defined-Static-Methods | debug01 | price_with_tax.cpp | conceptual/design | yes — no tax applied (10, 25, 35) | yes — 10.8, 27, 37.8 | executed |
| Module06-User-Defined-Static-Methods | debug02 | swap_values.cpp | conceptual/design | yes — `Smaller: 42`, `Larger: 17` | yes; `3 9` unchanged | executed |
| Module07-Writing-Classes | debug01 | rectangle.cpp | logic | yes — two `-Wself-assign` warnings; all values 0 | yes — 4, 6.5, 26, 21 | executed |
| Module07-Writing-Classes | debug02 | ticket.cpp | conceptual/design | yes — every ticket `#1`, count 1 | yes — #1 #2 #3, count 3 | executed |
| Module08-Designing-Classes | debug01 | course_roster.cpp | conceptual/design | yes — `Enrolled: 0`, empty roster | yes — 3, `Ana, Ben, Chloe` | executed |
| Module08-Designing-Classes | debug02 | student_record.cpp | syntax/compile | yes — `error: 'this' argument to member function 'getGpa' has type 'const Student', but function is not marked const` | yes | executed |
| Module09-Introduction-to-Arrays | debug01 | temperature_stats.cpp | runtime (UB, ASAN) | yes — `AddressSanitizer: stack-buffer-overflow ... READ of size 4 ... temperature_stats.cpp:18`, 3 of 3 runs | yes — 507 / 72.4286 | executed |
| Module09-Introduction-to-Arrays | debug02 | highest_score.cpp | logic | yes — `Bowled in game 1` | yes — game 4 | executed |
| Module09-Introduction-to-Arrays | debug03 | reverse_array.cpp | logic | yes — `-Wsizeof-array-argument` and `-Wsizeof-pointer-div` warnings; `20 10 30 40 50 60` | yes — fully reversed | executed |
| Module10-More-About-Arrays | debug01 | seating_chart.cpp | boundary | yes — `Open seats: 5 of 15` | yes — 8 of 15 | executed |
| Module10-More-About-Arrays | debug02 | class_roster.cpp | logic | yes — 6 students, three blank entries, average 45 | yes — 3 students, average 90 | executed |
| Module11-Inheritance | debug01 | employee_manager.cpp | logic | yes — `unassigned manages Engineering and earns $0` | yes | executed |
| Module11-Inheritance | debug02 | pet_sounds.cpp | conceptual/design | yes — every pet `says ...` | yes — Woof! / Meow. / ... | executed |
| Module13-Exceptions | debug01 | number_sum.cpp | logic | yes — `Valid entries: 2`, `Sum: 19` | yes — 4 / 53 | executed |
| Module13-Exceptions | debug02 | bank_withdrawals.cpp | conceptual/design | yes — two `-Wexceptions` warnings; both rejections print `Transaction failed:` | yes — `Invalid amount:` / `Declined: ... (short by $420)` | executed |
| Module14-File-IO | debug01 | score_reader.cpp | logic | yes — `Dmitri: 95` twice, `Students: 5`, `Average: 89.8` | yes — 4 / 88.5 | executed |
| Module14-File-IO | debug02 | grade_report.cpp | logic | yes — report holds only `Dmitri 95 A` | yes — header + 4 lines; second run identical | executed |

Executed: 27. UNCHECKED: 0.

## Bug-type mix (27 activities)

syntax/compile 1 (4 %) · runtime 2 (7 %) · logic/boundary 16 (59 %) · conceptual/design 8 (30 %).
Compile-error activities are well under the 20 % ceiling. The runtime share is below the plan's
20–30 % guideline; this follows from the B2 blueprint itself (the C++ substitutes for Java's
`ArrayIndexOutOfBounds`/`NullPointerException` bugs are wrong-output or sanitizer-detected UB, not
crashes) and was not altered so the tree stays aligned with `CSC110-Java`.

## Notes and items the lead may want to double-check

- **Module09/debug01 (UB).** The out-of-bounds read is undefined behavior; the README instructs
  students (this activity only) to compile with `-fsanitize=address -g`. The sanitizer aborted
  reliably in every run. Without the sanitizer the total is off by an unpredictable amount, which
  the README and SOLUTION both say.
- **Module09/debug03 (`sizeof` on a decayed parameter).** Deterministic on 64-bit platforms
  (`size == 2`, so only the first pair swaps); on a 32-bit build `size == 1` and nothing moves.
  Not UB, just platform-dependent; SOLUTION.md notes this.
- **Module14/debug01 (`eof()` loop).** The double-processing of the last line relies on
  standard-specified behavior: a failed `>>` into a `string` leaves it unchanged, and a failed
  stream skips the `int` extraction. Confirmed with libc++; libstdc++ behaves the same. The
  symptom depends on `scores.txt` ending with a newline, which it does (keep it that way if the
  file is ever edited).
- **Module14/debug02** creates `report.txt` in the directory it runs from; the README says so.
  No such file is left in the tree.
- **Module07/debug02** uses a `static` member and **Module08/debug02** uses `const` member
  functions. A8's CSC110 line places `static` at M8 and says `const` members are "not yet" at M8,
  but B2 explicitly calls for both of these bugs at those modules, so the blueprint was followed.
- **Module13/debug02** compiles with two clang `-Wexceptions` warnings that name the problem
  (like the `-Wempty-body`, `-Wself-assign`, and `-Wsizeof-*` warnings in earlier activities).
  The README tells students to read compiler messages; the warning is part of the lesson.
- Buggy versions of Module05/debug02, Module07/debug01, Module09/debug03, and Module13/debug02
  emit `-Wall` warnings; all corrected versions compile with none.

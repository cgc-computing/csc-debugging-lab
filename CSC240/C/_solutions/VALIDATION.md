# Validation Log — CSC240 / C

Toolchain: Apple clang 21.0.0 invoked as `gcc -std=c11 -Wall` (plus `-fsanitize=address -g` where the README requires it), macOS arm64. Every buggy and corrected program was compiled and run with the README's sample input under a 5-second timeout. All corrected programs compile with zero warnings. Binaries were built in a scratch directory; none remain in the tree.

| Module | Activity | Source file | Bug type(s) | Buggy symptom confirmed? | Fixed output confirmed? | Method |
|---|---|---|---|---|---|---|
| Module01-Imperative-Control-Structures-Data-Types-Structures-and-Functions | debug01 | `temperature_stats.c` | runtime (crash), conceptual | Yes: `-Wformat` warning at 47:17, then segmentation fault (exit 139) after the count is typed | Yes: Count 5 / Min 58 / Max 91 / Average 73.2 | executed |
| Module01-Imperative-Control-Structures-Data-Types-Structures-and-Functions | debug02 | `class_roster.c` | logic, conceptual | Yes: "Enrolling" messages correct, "After" table identical to "Before" | Yes: 22/24, 12/20, 14/16 | executed |
| Module02-Pointers-and-Memory-Allocation | debug01 | `sort_three.c` | logic, conceptual | Yes: `After: 42 7 19` (unchanged) | Yes: `After: 7 19 42` | executed |
| Module02-Pointers-and-Memory-Allocation | debug02 | `word_copies.c` | runtime (heap overflow), boundary | Yes: ASan heap-buffer-overflow, WRITE of size 1 in `copy_string` line 18, "0 bytes after 7-byte region" allocated at line 13; with bug 1 alone fixed, WRITE of size 4 in `make_length_table` line 30 after a 5-byte region | Yes: five words, lengths 7/6/12/4/4, total 33, no ASan report | executed |
| Module02-Pointers-and-Memory-Allocation | debug03 | `grade_book.c` | runtime (crash), conceptual | Yes: `Loaded 7 scores`, `Scores:` then segmentation fault (exit 139) | Yes: scores listed, Average 75.57, Passing 5 of 7 | executed |
| Module03-C-Preprocessor-User-Defined-Types-and-Modules | debug01 | `sensor_report.c` | logic, paradigm-specific (macros) | Yes: 10 / 4 / -46 cells, peak 5 | Yes: 40 / 56 / 96 cells, peak 40 | executed |
| Module03-C-Preprocessor-User-Defined-Types-and-Modules | debug02 | `main.c`, `stack.c`, `stack.h` | syntax/compile (prototype mismatch), link error (`static`), conceptual | Yes: `stack.c:35:5: error: conflicting types for 'stack_pop'`; with only the prototype fixed, `Undefined symbols for architecture arm64: "_op_count"` at link time | Yes: `Reversed: 9 5 1 4 1 3`, `7 3 - 4 * = 16`, 21 operations | executed |
| Module03-C-Preprocessor-User-Defined-Types-and-Modules | debug03 | `expense_report.c` | logic, boundary | Yes: labels shifted (Other 1150.00, Rent 82.50, Travel 119.35), Other row missing, ALL 1611.85 | Yes: five rows in enum order, ALL 1666.85 | executed |

Executed: 8 of 8. Desk-checked only: 0.

## Notes and items the lead may want to double-check

- `temperature_stats.c` (M1 debug01) and `class_roster.c` (M1 debug02) use object-like `#define` constants (`MAX_READINGS`, `SECTION_COUNT`). Function-like macros are a Module 3 topic; a plain named constant is standard first-week C and was left as is. Flagging in case the lead prefers literal sizes in Module 1.
- `grade_book.c` (M2 debug03) originally declared its lookup table `static const int raw[]`; `static` is a Module 3 concept, so the keyword was removed from both the student and corrected copies. Behavior is unchanged.
- `grade_book.c` buggy run: when stdout is a pipe rather than a terminal the two lines before the crash are lost in the stdio buffer; SOLUTION.md already notes this.
- `word_copies.c` (M2 debug02): the bug is undefined behavior without the sanitizer; the README makes `-fsanitize=address` mandatory for this activity and tells students without ASan what to expect.
- Error-type mix for this tree: compile/link 1 (12.5 %), runtime 3 (37.5 %), logic/boundary 3 (37.5 %), conceptual/paradigm-heavy 1 (12.5 %) counting each activity by its primary type; within A7's rough bands.

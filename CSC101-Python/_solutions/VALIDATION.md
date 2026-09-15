# CSC101-Python — Validation Log

Environment: macOS, Python 3.9.6. Every buggy and corrected program was executed with the
README's sample input piped on stdin (`subprocess.run(..., timeout=5)`). For `workout_log.py`
the data file was restored to its shipped contents after each run.

| Module | Activity | Source file | Bug type(s) | Buggy symptom confirmed? | Fixed output confirmed? | Method |
|---|---|---|---|---|---|---|
| Module01-Introduction-to-Computers-and-Python | debug01 | greeting.py | runtime (NameError) | Yes — `NameError: name 'Print' is not defined` after partial output | Yes | executed |
| Module02-Data-Types-Variables-and-Expressions | debug01 | quiz_average.py | conceptual (type conversion) | Yes — `Total points: 858892`, `Average score: 286297.33` | Yes — 265 / 88.33 | executed |
| Module02-Data-Types-Variables-and-Expressions | debug02 | split_bill.py | logic (precedence) | Yes — `Each person pays: $63.00` | Yes — $18.00 | executed |
| Module03-Strings | debug01 | username.py | boundary (slice end) | Yes — `hoppg` | Yes — `hoppeg` | executed |
| Module03-Strings | debug02 | censor.py | conceptual (immutability) | Yes — censored line unchanged | Yes — `****` substituted twice | executed |
| Module04-Lists-Tuples-Sets-and-Dictionaries | debug01 | grocery_list.py | runtime (AttributeError on None) | Yes — `'NoneType' object has no attribute 'sort'` | Yes — 4 sorted items | executed |
| Module04-Lists-Tuples-Sets-and-Dictionaries | debug02 | roster.py | conceptual (aliasing) | Yes — both rosters show 5 identical students | Yes — A has 4, B has 5 | executed |
| Module04-Lists-Tuples-Sets-and-Dictionaries | debug03 | inventory.py | runtime (KeyError) | Yes — `KeyError: 'stapler'`; `Backpack` run works | Yes — `Stock for stapler: 0` | executed |
| Module05-Conditionals | debug01 | letter_grade.py | logic (branch order) | Yes — 85 → D | Yes — 85 → B | executed |
| Module05-Conditionals | debug02 | ticket_price.py | logic (truthiness in `or`) | Yes — Friday gets discount, $16.00 | Yes — Friday $24.00, Tuesday $16.00 | executed |
| Module06-Loops-Part-1-For-and-While | debug01 | staircase_blocks.py | boundary (`range` stop) | Yes — 4 step lines, total 10 | Yes — 5 lines, total 15 | executed |
| Module06-Loops-Part-1-For-and-While | debug02 | savings_goal.py | runtime (infinite loop) / logic | Yes — timed out at 5 s with no output after prompts | Yes — 6 months, $1000.00 | executed |
| Module06-Loops-Part-1-For-and-While | debug03 | shopping_total.py | logic (accumulator reset) | Yes — Subtotal $10.00 | Yes — $16.75 / $1.34 / $18.09 | executed |
| Module07-Loops-Part-2-Nested-Loops-and-Exceptions | debug01 | times_table.py | logic (inner variable unused) | Yes — each row repeats a square | Yes — correct 4×4 table | executed |
| Module07-Loops-Part-2-Nested-Loops-and-Exceptions | debug02 | quiz_scores.py | conceptual (try/except placement) / logic | Yes — `Scores entered: 1`, `Average: 90.0` | Yes — 3 scores, 80.0 | executed |
| Module08-Algorithm-Design-and-the-Software-Lifecycle | debug01 | coldest_reading.py | logic (initialization) | Yes — `0.0 F (reading #0)` | Yes — `36.0 F (reading #4)` | executed |
| Module09-Functions | debug01 | paint_estimate.py | runtime (TypeError on None) / conceptual | Yes — stray `150.0` then TypeError | Yes — 540.0 sq ft, 1.54 | executed |
| Module09-Functions | debug02 | weather_summary.py | logic (argument order) | Yes — `-24.0 degrees, a small swing` | Yes — `24.0 degrees, a big swing` | executed |
| Module09-Functions | debug03 | bake_sale.py | runtime (UnboundLocalError) / conceptual (scope) | Yes — UnboundLocalError on first sale | Yes — running totals, $7.75 | executed |
| Module10-Advanced-Functions-Lambdas-and-Modules | debug01 | top_scorers.py | logic (sort direction) | Yes — Chloe/Eli/Ana | Yes — Fatima/Ben/Dev | executed |
| Module10-Advanced-Functions-Lambdas-and-Modules | debug02 | shopping_cart.py | conceptual (mutable default) | Yes — both carts hold all 4 items | Yes — 2 items each | executed |
| Module11-Classes-and-Objects | debug01 | bank_account.py | conceptual (missing `self.`) / logic | Yes — `Insufficient funds.`, balance stays $50.00 | Yes — $15.00 | executed |
| Module11-Classes-and-Objects | debug02 | student.py | conceptual (class attribute shared) | Yes — both students list 3 courses | Yes — 2 and 1 | executed |
| Module12-File-IO | debug01 | scores_report.py | runtime (ValueError) / boundary | Yes — `invalid literal for int() with base 10: ''` after 5 scores | Yes — 5 / 438 / 87.6 | executed |
| Module12-File-IO | debug02 | workout_log.py | conceptual (file mode `w` vs `a`) | Yes — only new entry remains in file and output | Yes — 3 entries; file restored after each run | executed |
| Module13-Python-Libraries | debug01 | dice_simulator.py | boundary (`randrange` exclusive stop) | Yes — face 6 count 0 (deterministic symptom) | Yes — all six faces nonzero | executed |
| Module13-Python-Libraries | debug02 | birthday_facts.py | runtime (ValueError) / logic (argument order) | Yes — `ValueError: month must be in 1..12` | Yes — Friday, 7587 days, 20.8 years | executed |

Totals: 27 activities, 27 executed, 0 UNCHECKED.

Error-type mix (primary category): runtime 8 (30 %), logic/boundary 12 (44 %), conceptual/design 7 (26 %),
syntax/compile 0. The Module 1 activity is a runtime `NameError` rather than a `SyntaxError` so that
students see partial output followed by a traceback, which is the intended lesson.

## Notes and items to double-check

* **Module06 debug02 (savings_goal.py)** is the one intentional hang in Module 6. It prints nothing
  after the prompts; the README tells students to press Ctrl+C if the program does not finish.
* **Module12 debug02 (workout_log.py)**: running the buggy version destroys the two shipped log
  lines. The README states the original contents and tells students to restore them. Instructors
  may want a spare copy of `workout_log.txt`.
* **Module13 debug01 (dice_simulator.py)**: output is random, but the symptom (face 6 never appears)
  is deterministic. The README's sample run is illustrative, not exact.
* **Module13 debug02 (birthday_facts.py)**: with a birth day ≤ 12 the buggy program runs without an
  exception and prints a plausible wrong answer; the README's sample (day 25) exposes the crash, and
  a Think About question points students at the silent case.
* **Module08 debug01**: the pseudocode in the README says "keep track of the coldest temperature seen
  so far" without specifying initialization; this is deliberate so tracing, not reading, finds the
  problem.
* **Module04 debug03 (inventory.py)**: the intended fix is `dict.get(item, 0)`, since `if` is not
  available until Module 5. Students who know `if ... in` will propose it; SOLUTION.md addresses that.
* Leak grep over the student tree (`bug|fix|todo|hint|wrong|error is|line [0-9]`) returns only the `debugNN`
  activity labels in README headers and the
  verbatim "Your Task" sentence in each README.

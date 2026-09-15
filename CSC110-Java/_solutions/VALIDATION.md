# CSC110-Java — Validation Log

Environment: macOS, OpenJDK 25.0.4 (programs written for Java 17+). Every activity was built in a
scratch copy outside the tree. For each activity the **buggy** version was compiled and run with the
README's sample input (5-second alarm on every run) and its behavior compared with `SOLUTION.md` →
Observed Behavior; then the **corrected** version in `_solutions/` was compiled (no warnings) and
run with the same input and compared with the README → Expected Behavior. Where a README lists
additional inputs (other grades, zones, `98`, `-1` first, divisor `0`, divisor `five`, a differing
ID), the corrected version was also run with those. No `.class` files remain in the tree.

| Module | Activity | Source file | Bug type(s) | Buggy symptom confirmed? | Fixed output confirmed? | Method |
|---|---|---|---|---|---|---|
| Module01-Introduction-to-Computing-in-Java | debug01 | QuotePrinter.java | logic | yes — three quotation lines run together on one line | yes | executed |
| Module02-Data-and-Expressions | debug01 | TestAverage.java | logic | yes — `Average score: 91.0` | yes — `91.33333333333333` | executed |
| Module02-Data-and-Expressions | debug02 | Receipt.java | logic | yes — `Total due: $25.02.0` | yes — `$27.0` | executed |
| Module03-Using-Classes-and-Objects | debug01 | NameFormatter.java | conceptual/design | yes — name tag stays lowercase | yes | executed |
| Module03-Using-Classes-and-Objects | debug02 | DiceGame.java | boundary | yes — rolls `0 and 2`, `0 and 4` | yes — `1 and 3`, `1 and 5` | executed |
| Module04-Control-Structures-Conditionals | debug01 | LetterGrade.java | logic | yes — 85 earns D, no compliment | yes (85→B; 92 A, 71 C, 64 D, 40 F) | executed |
| Module04-Control-Structures-Conditionals | debug02 | ShippingCost.java | logic | yes — warning printed and $8.50 for zone 1 | yes (zones 1, 2, 3, 7) | executed |
| Module05-Control-Structures-Loops | debug01 | SumToN.java | boundary | yes — loop total 45 vs formula 55 | yes (10, 1, 100) | executed |
| Module05-Control-Structures-Loops | debug02 | StarBox.java | logic (syntax-shaped) | yes — one star per row | yes | executed |
| Module05-Control-Structures-Loops | debug03 | SentinelAverage.java | logic | yes — 4 scores, total 269, avg 67.25 | yes (also `-1` first → "No scores were entered.") | executed |
| Module06-User-Defined-Static-Methods | debug01 | PriceCalculator.java | conceptual/design | yes — after-tax equals before-tax | yes | executed |
| Module06-User-Defined-Static-Methods | debug02 | ScoreCurve.java | conceptual/design | yes — curved score 82 | yes (82→87, 98→100) | executed |
| Module07-Writing-Classes | debug01 | Rectangle.java, RectangleTester.java | logic | yes — all 0.0 until setter; perimeter 10.0 | yes | executed |
| Module07-Writing-Classes | debug02 | Ticket.java, TicketTester.java | conceptual/design | yes — every ticket #1, sold 1 | yes | executed |
| Module08-Designing-Classes | debug01 | Course.java, Roster.java, CourseTester.java | conceptual/design | yes — both rosters list 5, total 10 | yes | executed |
| Module08-Designing-Classes | debug02 | Student.java, DuplicateChecker.java | conceptual/design | yes — identical records reported DIFFERENT | yes (also differing ID → DIFFERENT) | executed |
| Module09-Introduction-to-Arrays | debug01 | ScoreStats.java | runtime, boundary | yes — `ArrayIndexOutOfBoundsException: Index 5 out of bounds for length 5` | yes | executed |
| Module09-Introduction-to-Arrays | debug02 | TallestStudent.java | logic | yes — `Jordan at 66 inches` | yes — `Sofia at 74 inches` | executed |
| Module09-Introduction-to-Arrays | debug03 | ReverseArray.java | logic, boundary | yes — "reversed" array identical to original | yes | executed |
| Module10-More-About-Arrays | debug01 | RainfallTable.java | logic, boundary | yes — Q4 column missing, total 30.4 | yes — 45.4 | executed |
| Module10-More-About-Arrays | debug02 | HonorRoll.java, Student.java | runtime | yes — `NullPointerException` on first setter call | yes | executed |
| Module11-Inheritance | debug01 | Employee.java, Manager.java, PayrollTester.java | conceptual/design | yes — `Unassigned earns $0.00 and manages Operations` | yes | executed |
| Module11-Inheritance | debug02 | Ticket.java, StudentTicket.java, SeniorTicket.java, BoxOffice.java | conceptual/design | yes — students charged $12.00, total $44.40 | yes — $6.00, total $32.40 | executed |
| Module13-Exceptions | debug01 | NumberSummer.java | conceptual/design, logic | yes — one skip reported, sum 19 | yes — two skips, sum 54 | executed |
| Module13-Exceptions | debug02 | SafeDivider.java | syntax/compile | yes — `exception NumberFormatException has already been caught` (2 errors) | yes (17/5, 17/0, 17/five) | executed |
| Module14-File-IO | debug01 | ScoreReader.java (+ scores.txt) | runtime, logic | yes — `NoSuchElementException` from `nextInt` after six scores | yes — 6 / 95 / 84.83 | executed |
| Module14-File-IO | debug02 | ReportWriter.java (+ scores.txt) | runtime, conceptual/design | yes — `report.txt` created with 0 bytes | yes — 135-byte report matches README | executed |

**Totals:** 27 activities, 27 executed, 0 UNCHECKED. Compile-error activities: 1 of 27 (3.7 %).

## Other checks

* README section order (Goal / Expected Behavior / How to Run / Your Task / Think About), the
  verbatim task sentence, and `**Language:** Java 17+` verified by script on all 27 READMEs;
  SOLUTION.md section order and `Bug type(s)` / `Bug count` header lines verified on all 27.
* `_solutions/` mirrors the student path exactly; every corrected source keeps the student file
  name; Module 14 ships `scores.txt` in both the activity and the solution directory.
* Leak grep (`bug|fix|todo|hint|wrong|error is|line [0-9]`) over student `.java` and `README.md`
  files: the only hits are the header line `**Activity:** debugNN` (contains "bug") and the
  user-facing message `"Something went wrong: "` in `SafeDivider.java`, which is a normal program
  string, not a hint.
* Concept availability (A8) checked by reading every source: no methods outside `main` before
  Module 6, no user-defined classes before Module 7, no arrays before Module 9, no `ArrayList`
  anywhere (Module 10 uses an array of objects), no inheritance before Module 11, no exceptions
  before Module 13, no file I/O before Module 14.

## Notes and items worth a second look

* **Module 8 debug02 deviates from the B2 blueprint.** B2 suggests an `equals(Person)` overload that
  makes `list.contains` fail, but `ArrayList` is not available until Module 10 (A8). The activity
  instead uses `==` on the `String` field inside a correctly-signed `equals(Object)`, with names read
  from the keyboard so the reference comparison reliably fails. Same module topic (`equals`),
  different mechanism.
* **Module 13 debug02** is the tree's one compile-error activity, as B2 prescribes. Its README says
  to "read carefully anything the compiler or the program tells you", and one Think About question
  quotes the phrase "already been caught" from the compiler message — that text is what students
  will see on their first compile, so it is treated as observed output rather than a leak.
* **Module 14 debug01**'s symptom depends on `scores.txt` ending with a newline (it does). If a
  student's editor strips the trailing newline, the buggy program runs correctly; the SOLUTION.md
  Instructor Notes point this out.
* **Error-type mix** (primary types): compile 1 (4 %), runtime 4 (15 %), logic/boundary 13 (48 %),
  conceptual/design 9 (33 %). Runtime is a little under the A7 target band and conceptual a little
  over; this reflects CSC110's content (pass-by-value, references, `static`, `super`, overriding),
  and no activity was redesigned to chase the ratio.
* **Size:** Module 1's `QuotePrinter.java` is 13 lines (below the 20-line guideline, inherent to
  the B2 spec for that module); Module 11 debug02 totals 84 lines across four files (slightly over
  80, still readable in a session).
* Two READMEs name a specific method in Think About (`toUpperCase()` in Module 3 debug01,
  `Random.nextInt(int bound)` in Module 3 debug02) because that method is the module's learning
  objective; neither states the correction.

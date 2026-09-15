# CSC205-Java — Validation Log

Environment: macOS, OpenJDK 25.0.4 (`javac`/`java`), sources written for Java 17+. Every activity was copied to a scratch directory, compiled with `javac *.java`, and run with a 10-second alarm (`perl -e 'alarm 10; exec @ARGV' java <Driver>`) for both the buggy (student) version and the corrected (`_solutions/`) version. All corrected versions compile without errors; under `javac -Xlint:all` the only warning is the customary `[serial]` note (no `serialVersionUID`) on `InvalidScoreException` in Module 4 debug02, which is left as is because textbook custom exceptions do not declare one. No `.class` files were left in the course tree. Module 4 activities were run from the directory containing `students.csv` (shipped in both the student and solution directories).

| Module | Activity | Source file | Bug type(s) | Buggy symptom confirmed? | Fixed output confirmed? | Method |
|---|---|---|---|---|---|---|
| Module01-Java-Review-Software-Engineering-and-UML | debug01 | Main.java, Course.java, Student.java | conceptual/design, logic | yes — enrolled student reported "not enrolled"; `Student.name` public, `getName()` missing vs UML | yes | executed |
| Module02-Inheritance-and-Object-Oriented-Design | debug01 | Main.java, Employee.java, Manager.java | conceptual/design | yes — manager bonuses missing (Ben $70,000, Cleo $81,000, total $203,000) | yes | executed |
| Module02-Inheritance-and-Object-Oriented-Design | debug02 | Main.java, BankAccount.java, CheckingAccount.java | conceptual/design, logic | yes — balance stuck at $150.00, second withdrawal declined | yes | executed |
| Module03-Polymorphism-and-Interfaces | debug01 | Main.java, Shape.java, Circle.java, Rectangle.java, Triangle.java | conceptual/design, logic | yes — triangle area 0.00, total 102.54 | yes | executed |
| Module03-Polymorphism-and-Interfaces | debug02 | Main.java, Student.java | logic, conceptual/design | yes — list printed in insertion order, unsorted | yes | executed |
| Module04-File-IO-and-Exceptions | debug01 | ScoreReport.java (+ students.csv) | conceptual/design, runtime (swallowed) | yes — Brianna shows Alice's score 88, average 86.5 | yes | executed |
| Module04-File-IO-and-Exceptions | debug02 | GradeReport.java, InvalidScoreException.java | runtime, conceptual/design | yes — "Report saved" but report.txt empty | yes | executed |
| Module05-Recursion-and-Analysis-of-Algorithms | debug01 | Factorial.java | runtime, boundary | yes — `StackOverflowError` on 0! | yes | executed |
| Module05-Recursion-and-Analysis-of-Algorithms | debug02 | StringRecursion.java | logic, conceptual/design | yes — counts 0, 0, 1, 0 instead of 4, 3, 3, 0 | yes | executed |
| Module05-Recursion-and-Analysis-of-Algorithms | debug03 | Fibonacci.java | conceptual/design (analysis) | yes — fib(35) 22 ms, fib(40) 245 ms (≈11× for +5) | yes — both 0 ms | executed |
| Module06-Arrays-ArrayLists-Collections-and-Iterators | debug01 | RemoveEvens.java | logic, boundary | yes — `[3, 6, 7, 14, 5]`, adjacent evens survive | yes | executed |
| Module06-Arrays-ArrayLists-Collections-and-Iterators | debug02 | LongWords.java | logic, runtime | yes — wrong words then `NoSuchElementException` | yes | executed |
| Module07-Lists | debug01 | Main.java, SinglyLinkedList.java | logic | yes — `10 -> 40`, middle appends vanish, size still 4 | yes | executed |
| Module07-Lists | debug02 | Main.java, SinglyLinkedList.java | boundary, runtime | yes — insert lands one too far, then `NullPointerException` | yes | executed |
| Module07-Lists | debug03 | Main.java, SinglyLinkedList.java | boundary, logic | yes — head never removed, size never decrements | yes | executed |
| Module09-Stacks-and-Queues | debug01 | Main.java, ArrayStack.java | boundary, logic | yes — peek 0, pops 0/30/20 | yes | executed |
| Module09-Stacks-and-Queues | debug02 | Main.java, CircularQueue.java | runtime, logic | yes — `ArrayIndexOutOfBoundsException: Index 5` on wrap-around enqueue | yes | executed |
| Module09-Stacks-and-Queues | debug03 | BracketChecker.java, CharStack.java | logic, boundary, runtime | yes — `"((a)"` balanced, then `RuntimeException: stack is empty` on `")("` | yes | executed |
| Module10-Searching | debug01 | BinarySearch.java | boundary, logic (infinite loop) | yes — first three searches correct, hang on search for 40 (killed by 10 s alarm, exit 142) | yes | executed |
| Module10-Searching | debug02 | ItemSearch.java, Item.java | conceptual/design, logic | yes — same-reference search finds index 2; equal new object gives -1 and count 0 | yes | executed |
| Module11-Sorting | debug01 | SelectionSort.java | logic | yes — `[5, 13, 10, 14, 29, 37]`, `[2, 1, 3]`, Sorted? false | yes | executed |
| Module11-Sorting | debug02 | InsertionSort.java | boundary, runtime | yes — `ArrayIndexOutOfBoundsException: Index -1` on first array | yes | executed |
| Module11-Sorting | debug03 | MergeSort.java | logic, boundary | yes — `[3, 9, 0, 0, 27, 38, 43]`, `[1, 0, 0, 5, 0, 0]`; pair sorts correctly | yes | executed |
| Module12-Introduction-to-Trees | debug01 | Main.java, BinaryTree.java | logic, conceptual/design | yes — in-order line identical to pre-order | yes | executed |
| Module12-Introduction-to-Trees | debug02 | Main.java, BinaryTree.java | logic, boundary | yes — nodes 3 (should be 7), height 4 (should be 3) | yes | executed |
| Module13-Binary-Search-Trees | debug01 | Main.java, BST.java | logic, conceptual/design | yes — in-order `50`, size 7, height 0 | yes | executed |
| Module13-Binary-Search-Trees | debug02 | Main.java, BST.java | logic, boundary | yes — duplicates stored (size 9), every `contains` false | yes | executed |
| Module13-Binary-Search-Trees | debug03 | Main.java, BST.java | logic, conceptual/design | yes — `40 60 60 70 80 size 4`, then `40 60 60 80 80 size 3` | yes | executed |
| Module14-Introduction-to-Graphs | debug01 | Main.java, Graph.java | conceptual/design, logic | yes — one-directional lists; BFS from 4 = `[4]`, from 2 = `[2, 3, 4]` | yes | executed |
| Module14-Introduction-to-Graphs | debug02 | Main.java, Graph.java | logic, conceptual/design | yes — 11 dequeues, hop counts 0 1 2 3 4 | yes | executed |

30 activities executed; 0 UNCHECKED.

## Notes and items worth a second look

- **Module 10 debug01 is the tree's one intentional hang** (infinite loop in binary search). The README tells students a correct run finishes instantly and to press `Ctrl+C` if it does not. No other activity hangs.
- **Module 05 debug03 timings are machine-dependent.** Observed 22 ms / 245 ms here; SOLUTION.md quotes 21 ms / 239 ms from an earlier run. The README already says exact millisecond values vary and that only the ratio matters.
- **Module 04 debug02 writes `report.txt`** into the working directory during the run (buggy: empty file; fixed: four lines). Students should run it from the activity directory.
- **Program length.** Modules 5 and 6 activities are short (16–29 lines) — below the "roughly 40–120 lines" guideline for CSC205 — because the recursion/iterator programs are naturally small and padding them would be artificial. Module 13 debug03 is 123 lines (just over). Everything else is 39–94 lines.
- **Bug counts.** Module 1 has two bugs by blueprint design (UML violation plus `==` on strings). Modules 2–4 have exactly one each. Modules 5–14 have one to three related bugs; where the same misconception appears twice (M09 debug01 `pop`/`peek`, M10 debug02 `indexOf`/`count`, M13 debug01 left/right branch) the count is listed as 2 with that note.
- **Error-type mix (30 activities):** 0 compile-error activities (0 %, under the ≤20 % cap); runtime symptom in 8 (≈27 %); logic/boundary primary in 14 (≈47 %); conceptual/design primary in 8 (≈27 %). Roughly on target; slightly heavy on conceptual because the OO modules (1–3) are inherently design-focused.
- **Module 14 uses `java.util.ArrayDeque` as the BFS work queue** and `ArrayList` for the adjacency lists; the `Graph` class itself (representation, `addEdge`, BFS) is hand-written and is where the bugs live. Modules 7, 9, 12, 13 use no `java.util` collections at all.
- **Stack-trace line numbers** quoted in SOLUTION.md files for Modules 5–11 were checked against the actual output on JDK 25 (two stale numbers in M09 debug02/debug03 were corrected during this pass). Line numbers of `java.base` frames may differ slightly on other JDK versions.

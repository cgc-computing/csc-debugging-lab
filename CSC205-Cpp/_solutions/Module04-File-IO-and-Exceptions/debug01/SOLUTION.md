# Solution: CSV Grade Report

**Course/Module/Activity:** CSC205 · Module 4 File I/O and Exceptions · debug01
**Bug type(s):** logic (exception-handling control flow)
**Bug count:** 1

## Observed Behavior

```
Alice: 91.6667
Bob: 75
Carol: 86.3333
Warning: bad record for Dana, skipping.
Dana: 88.6667
Evan: 70
5 students reported.
```

The warning prints, but Dana is still reported — with an average that is not hers — and the count is 5.

## The Bug(s)

The `catch` block in the read loop prints the warning but does not leave the iteration:

```cpp
} catch (const invalid_argument& e) {
    cout << "Warning: bad record for " << name << ", skipping." << endl;
}
// execution falls through to the averaging code below
```

## Why the Program Behaved Incorrectly

For Dana's line the loop stores `scores[0] = 95`, then `stoi("")` throws `invalid_argument` before `scores[1]` is assigned. The handler runs, and then control simply continues *after* the try/catch, to the code that sums `scores` and prints. Because `scores` is declared outside the `while` loop, `scores[1]` and `scores[2]` still hold Carol's 92 and 79, so Dana's "average" is (95 + 92 + 79) / 3 = 88.67, and `reported` is incremented.

## The Concept This Illustrates

Catching an exception does not undo the work that was half-finished, nor does it skip the rest of the loop body; it only resumes execution after the handler. When a record is invalid, the program must *explicitly* decide what "skipping" means — here, `continue` to the next line. Students often assume that handling an error automatically restores a clean state. This activity also shows why keeping per-record variables inside the loop body limits how far stale data can leak.

## The Correction

```cpp
// before
} catch (const invalid_argument& e) {
    cout << "Warning: bad record for " << name << ", skipping." << endl;
}

// after
} catch (const invalid_argument& e) {
    cout << "Warning: bad record for " << name << ", skipping." << endl;
    continue;
}
```

Moving the averaging and printing *inside* the `try` block is an equally correct fix.

## Instructor Notes

- Some students first suspect the CSV parsing (`getline` with `','`) and rewrite it. Redirect them: the warning proves parsing detected the problem; the question is what happens *next*.
- Ask students to declare `scores` inside the loop and rerun the buggy version. The output changes (indeterminate values or zeros), and the count is still wrong — a good demonstration that the state leak and the control-flow error are separate issues, and that only the `continue` fixes the count.
- `stoi` also throws `out_of_range`; ask whether the current handler catches it and what a more general handler (`catch (const exception&)`) would trade away.
- Expected output prints `75` and `70` rather than `75.0`; that is default `cout` formatting.

# Solution: Sum of Typed Numbers

**Course/Module/Activity:** CSC110 · Module 13 Exceptions · debug01
**Bug type(s):** logic (try/catch scope)
**Bug count:** 1

## Observed Behavior

The first bad entry ends the whole loop. With input `5` and `12 7 x 30 4`:

```
How many entries? 5
Enter 5 entries: 12 7 x 30 4
Skipping 'x' (not a whole number)
Valid entries: 2
Sum: 19
```

`30` and `4` are never processed. The program compiles with no warnings.

## The Bug(s)

`number_sum.cpp`, `main`: the `try` block wraps the *entire* `for` loop:

```cpp
try {
    for (int i = 0; i < howMany; i++) {
        cin >> entry;
        int value = stoi(entry);
        ...
    }
} catch (const invalid_argument& e) {
    ...
}
```

The handler is outside the loop, so once control transfers to it, the loop is over.

## Why the Program Behaved Incorrectly

When `stoi("x")` throws `std::invalid_argument`, execution leaves the `try` block immediately —
which means leaving the `for` loop, since the loop lives inside the `try`. The `catch` prints the
skip message, and the next statement after the `try/catch` is the summary. Only `12` and `7` were
added before the throw, so `valid == 2` and `sum == 19`. The remaining tokens `30 4` are still
sitting unread in the input stream when the program exits.

## The Concept This Illustrates

The placement of a `try` block decides *how much work is abandoned* when an exception occurs.
Everything between the throw point and the matching handler is unwound. To skip a single bad item
and continue, the `try/catch` must sit *inside* the loop, around only the code that can fail for
that item. Students often wrap the largest possible region in `try` ("so nothing crashes") without
asking where they want execution to resume.

## The Correction

```cpp
// before
try {
    for (int i = 0; i < howMany; i++) {
        cin >> entry;
        int value = stoi(entry);
        sum += value;
        valid++;
    }
} catch (const invalid_argument& e) {
    cout << "Skipping '" << entry << "' (not a whole number)" << endl;
}

// after
for (int i = 0; i < howMany; i++) {
    cin >> entry;
    try {
        int value = stoi(entry);
        sum += value;
        valid++;
    } catch (const invalid_argument& e) {
        cout << "Skipping '" << entry << "' (not a whole number)" << endl;
    }
}
```

## Instructor Notes

- Ask students to add a `cout << i` at the top of the loop body in the original; seeing it stop at
  `2` makes "the exception left the loop" concrete.
- Some students keep the outer `try` and add a second, inner `try/catch`; the outer one is then
  dead code. Ask what it would ever catch.
- Others replace the exception with an `if` that checks whether every character is a digit. That
  works for this input but ask about `"-3"` or `"+7"` (`stoi` accepts both); the exception-based
  version is simpler and more complete.
- Follow-up: `stoi("99999999999")` throws `std::out_of_range`, not `invalid_argument`. What happens
  with the corrected program? Should there be a second handler, or a `catch (const exception&)`?
  (Leads into debug02.)

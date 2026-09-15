# Solution: Class Roster

**Course/Module/Activity:** CSC240 · Module 1 Imperative Control Structures, Data Types, Structures, and Functions · debug02
**Bug type(s):** logic, conceptual/design
**Bug count:** 1

## Observed Behavior

Compiles cleanly. The enrolling messages are correct, but the "After" table is identical to the "Before" table:

```
--- Enrolling ---
Added 4 to CSC110
Cannot add 10 to CSC205: only 8 seats open
Added 5 to CSC240

--- After ---
CSC110   18/24 enrolled,  6 seats open
CSC205   12/20 enrolled,  8 seats open
CSC240    9/16 enrolled,  7 seats open
```

## The Bug(s)

`add_students(struct class_t c, int count)` receives the section **by value** and updates `c.enrolled += count;` on its private copy. The caller's `sections[i]` is never changed:

```c
void add_students(struct class_t c, int count)
{
    ...
    c.enrolled += count;
    printf("Added %d to %s\n", count, c.code);
}
```

## Why the Program Behaved Incorrectly

A `struct` in C is a value type. `add_students(sections[0], 4)` copies all of `sections[0]` (the code array and both integers) into the parameter `c`. The capacity check and the message use the copy, so they look right, and the increment happens to the copy, which is discarded when the function returns. `main` then prints the untouched originals.

## The Concept This Illustrates

Java students expect "passing an object" to mean passing a reference, so mutations inside the method are visible outside. In C there are no objects, only values; a `struct` argument is copied just like an `int`. To get a result back you must either **return** the updated struct (this module) or pass the struct's address and use `->` (Module 2). `print_section` also takes its struct by value, which is fine because it only reads.

## The Correction

Return the updated record and store it:

```c
/* before */
void add_students(struct class_t c, int count) { ... c.enrolled += count; ... }
add_students(sections[0], 4);

/* after */
struct class_t add_students(struct class_t c, int count) { ... c.enrolled += count; ... return c; }
sections[0] = add_students(sections[0], 4);
```

(The full corrected file returns `c` on both the success and the refusal path.)

## Instructor Notes

- Students who have read ahead may propose `void add_students(struct class_t *c, int count)` with `c->enrolled += count` and `add_students(&sections[0], 4)`. That is the idiomatic C fix and should be accepted; ask them to explain what `&sections[0]` is and why `->` is needed.
- A common half-fix: returning the struct but forgetting to assign it (`add_students(sections[0], 4);` still). Output is unchanged; good moment to stress that C ignores discarded return values silently.
- Another half-fix: returning `c` only on the success path, so the refused section becomes garbage. Ask what `sections[1]` holds after the call in that version.
- Contrast with `print_section`: passing by value is *fine* when the function does not need to modify the caller's data, though it does copy the whole struct.

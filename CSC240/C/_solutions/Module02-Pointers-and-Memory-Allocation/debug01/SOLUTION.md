# Solution: Sort Three Numbers

**Course/Module/Activity:** CSC240 · Module 2 Pointers and Memory Allocation · debug01
**Bug type(s):** logic, conceptual/design
**Bug count:** 1

## Observed Behavior

Compiles cleanly with `-Wall`. The numbers come back in their original order:

```
Enter three integers: 42 7 19
Before: 42 7 19
After:  42 7 19
```

## The Bug(s)

`swap` exchanges the two **pointer variables** instead of the integers they point to:

```c
void swap(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}
```

## Why the Program Behaved Incorrectly

`a` and `b` are local copies of the addresses passed in. Assigning `a = b` changes which `int` the local `a` points to; it never touches the caller's variables. When `swap` returns, `a`, `b`, and `temp` vanish and `first`, `second`, `third` are unchanged. `sort_three` correctly passes addresses and correctly dereferences with `*x > *y` in its comparisons, so the pointer plumbing is fine right up to the last step.

## The Concept This Illustrates

Pointers are values too. A function receives a *copy* of a pointer; reassigning that copy is invisible to the caller. To modify what the pointer points at, you must dereference: `*a = *b`. Students coming from Java conflate "I have a reference to it" with "I can change it"; in C the `*` is the explicit act of reaching through the reference.

## The Correction

```c
/* before */
int *temp = a;
a = b;
b = temp;

/* after */
int temp = *a;
*a = *b;
*b = temp;
```

## Instructor Notes

- Ask students to draw the memory picture: two boxes in `main`, two pointer boxes in `swap`. The buggy code swaps the arrows; the fixed code swaps the contents.
- Some students will change only one or two of the three lines (for example `int temp = *a; a = b; b = temp;`). That does not compile (`int` assigned to `int *`), which is a useful error to read together.
- Follow-up: why does the program need `swap(x, y)` and not `swap(&x, &y)` inside `sort_three`? (Because `x` and `y` are already pointers.)
- Connect to Module 1: a `swap(int a, int b)` with plain values fails for the same underlying reason; pointers are the fix, but only if you dereference them.

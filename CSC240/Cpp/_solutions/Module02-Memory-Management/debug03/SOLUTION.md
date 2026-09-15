# Solution: Honor Roll

**Course/Module/Activity:** CSC240 · Module 2 Memory Management · debug03
**Bug type(s):** runtime (dangling pointer / use-after-free), conceptual/design (invalidation on reallocation)
**Bug count:** 1

## Observed Behavior

Compiles cleanly with `-Wall`. Under the sanitizer the program dies while adding the *second* student:

```
Added Aisha (roster size 1)
Added Marcus (roster size 2)
=================================================================
==6001==ERROR: AddressSanitizer: heap-use-after-free on address 0x... at pc ...
READ of size 8 at 0x... thread T0
    #0 ... in main honor_roll.cpp:46
0x... is located 24 bytes inside of 32-byte region [...]
freed by thread T0 here:
    #0 ... in operator delete(void*)
    ...
    #8 ... in std::vector<Student>::push_back(Student const&) vector.h:...
    #9 ... in main honor_roll.cpp:42
previously allocated by thread T0 here:
    #0 ... in operator new(unsigned long)
    ...
    in std::vector<Student>::push_back(Student const&) ...
```

The report points at line 46 (the comparison in the `if`) as the bad read and at line 42 (the `push_back`) as the operation that freed the memory.

Without the sanitizer the run usually *looks* fine or names the wrong top student; one plain run printed `Top student: Sofia with GPA 3.7`. The freed memory frequently still holds plausible bytes, which is why this bug hides so well.

## The Bug(s)

`main` stores a raw pointer to an element of a vector that is still growing:

```cpp
const Student* top = nullptr;
...
roster.push_back(incoming[i]);
if (top == nullptr || roster.back().gpa > top->gpa) {
    top = &roster.back();
}
```

## Why the Program Behaved Incorrectly

A `std::vector` keeps its elements in one contiguous heap block. When `push_back` finds the block full it allocates a larger block, copies (or moves) every element across, and **frees the old block**. Every pointer, reference, or iterator into the old block is now dangling.

With libc++ the capacity grows 1 → 2 → 4 → 8. Trace:

| push | reallocated? | what happens in the `if` |
|---|---|---|
| Aisha | yes (empty → 1); nothing to free | `top == nullptr`, so `top = &roster[0]` in block A |
| Marcus | **yes** (1 → 2): block A freed | `top->gpa` reads Aisha's GPA from freed block A: use-after-free |

The comparison `roster.back().gpa > top->gpa` dereferences the stale pointer *before* the assignment would have refreshed it, so the very first reallocation is caught. With other growth policies (libstdc++ also starts at 1) the iteration may differ, but the outcome does not: the first time the vector reallocates after `top` was set, `top` is dangling. Without the sanitizer, the read from freed memory returns whatever happens to be there, and the final `top->name` may print a stale or overwritten record.

## The Concept This Illustrates

**Pointer and iterator invalidation.** In Java an `ArrayList<Student>` holds references; the array of references may be reallocated, but the `Student` objects themselves never move, so a saved reference stays valid. A `std::vector<Student>` holds the *objects*, so when the vector reallocates, the objects are relocated and every address into the old storage becomes a dangling pointer. The rule to learn: do not keep pointers or references into a vector across any operation that can change its size, unless you have reserved capacity ahead of time.

## The Correction

Remember *which* element (an index survives reallocation) instead of *where* it lives:

```cpp
// before
const Student* top = nullptr;
...
if (top == nullptr || roster.back().gpa > top->gpa) {
    top = &roster.back();
}
...
std::cout << "Top student: " << top->name << ...

// after
std::size_t top_index = 0;
...
if (roster.back().gpa > roster[top_index].gpa) {
    top_index = roster.size() - 1;
}
...
const Student& top = roster[top_index];
std::cout << "Top student: " << top.name << ...
```

## Instructor Notes

- A tempting alternative fix is `roster.reserve(incoming_count);` before the loop. It genuinely works here (no reallocation ever happens) and is worth discussing, but ask what happens the day the incoming list has seven students. The index-based fix is robust; the reserve-based fix is a performance tool that happens to hide the problem.
- Another valid fix: find the top student in a second loop *after* the roster is complete (`top = &roster[i]` when nothing more will be pushed). The README asks for a single pass to steer students toward the index idea, but accept this with a discussion of why it is safe.
- Some students switch to `std::vector<Student*>` with `new Student(...)`. That fixes invalidation (the pointed-to objects no longer move) at the cost of manual `delete`s; it is the Java model made explicit and a good bridge to `std::unique_ptr` if time allows.
- Students often ask why the crash happens on the second push. Walk through the capacity table: the vector starts with capacity 1, so the second `push_back` is already a reallocation, and the `if` reads through `top` before it reassigns it.
- Range-for loops that `push_back` into the vector being iterated are the same bug in disguise; mention it as a thing to watch for in their own code.

# Solution: Class Roster Lookup

**Course/Module/Activity:** CSC205 · Module 1 C++ Review, Software Engineering, and UML · debug01
**Bug type(s):** conceptual/design, logic
**Bug count:** 2 (one UML-conformance defect, one review-level logic bug, as the blueprint specifies for this module)

## Observed Behavior

The program compiles cleanly and runs, but every lookup fails:

```
Roster size: 3
Bob Chen: not found
Carla Diaz: not found
Zed Nobody: not found
```

Separately, the `Roster` class does not match the UML: `students` is declared under `public:` although the diagram marks it `-` (private).

## The Bug(s)

1. `Roster::find` compares two `const char*` values with `==`:
   `if (students[i].getName() == name)`. This compares *addresses*, not characters.
2. `class Roster { public: vector<Student> students; ... }` — the aggregation should be a private member; the diagram gives the class a public interface of `add`, `find`, and `size` only.

## Why the Program Behaved Incorrectly

`getName()` returns a pointer into the `Student` object's own `name` array. The `name` parameter in `find` points at a string literal in `main`. Those are two different memory locations, so the pointer comparison is always false, even when the characters are identical. Because the array inside each `Student` is a distinct object, this result is deterministic — the loop never finds anything and the function returns `false` for every query.

The public `students` member does not change the output, but it lets any code outside `Roster` add, remove, or reorder students without going through `add`, which is exactly what the diagram is forbidding.

## The Concept This Illustrates

Two review-level ideas: (1) C-strings are arrays addressed by pointers, so equality must be tested with `strcmp` (or by converting to `std::string`); `==` on pointers asks "same address?", not "same text?". (2) UML visibility markers are requirements, not decoration. A `-` member is part of the encapsulation contract, and honoring the diagram is part of implementing the design correctly.

## The Correction

```cpp
// before
if (students[i].getName() == name) {
// after
if (strcmp(students[i].getName(), name) == 0) {
```

```cpp
// before
class Roster {
public:
    vector<Student> students;
// after
class Roster {
private:
    vector<Student> students;
public:
```

## Instructor Notes

- Some students will "fix" the lookup by changing `Student::name` to `std::string` and comparing with `==`. That works and is arguably better C++, but the UML says `char[32]`; ask them whether they are allowed to change the design, and make sure they can still explain why the original comparison failed.
- Students may wonder why comparing two *literals* with `==` sometimes appears to work (compilers often merge identical literals). Point out that relying on that is relying on luck, and it is impossible here because the roster's copy lives in its own array.
- Ask what `strcmp` returns and why the test is `== 0`, not `strcmp(...)` alone; the latter is a classic inverted-truth bug.
- Follow-up: "What else in the UML would break if we later switched `students` to a single `Student` member instead of a `vector`?" (multiplicity `1..*`).

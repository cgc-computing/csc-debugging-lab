# Solution: Rectangle Class

**Course/Module/Activity:** CSC110 · Module 7 Writing Classes · debug01
**Bug type(s):** logic (parameter shadows field)
**Bug count:** 2 (the same misconception twice)

## Observed Behavior

The program compiles (clang warns twice: `explicitly assigning value of variable of type
'double' to itself; did you mean to assign to member 'width'? [-Wself-assign]`) and every value
prints as zero:

```
Enter width and height: 4 6.5
Width:     0
Height:    0
Area:      0
Perimeter: 0
```

## The Bug(s)

`rectangle.cpp`, `Rectangle::Rectangle(double width, double height)`:

```cpp
width = width;
height = height;
```

The constructor parameters have the same names as the fields. Inside the constructor body the
parameter *shadows* the field, so each statement assigns a parameter to itself. The fields keep
their in-class initial value of `0`.

## Why the Program Behaved Incorrectly

Name lookup finds the innermost declaration first. Inside the constructor, `width` means the
parameter, on both sides of `=`. The member `width` is never mentioned, so it stays `0`, and every
getter and calculation reports `0`. The compiler warned about the pointless self-assignment, which
is the clue that something other than the field is being assigned.

## The Concept This Illustrates

Scope and shadowing in a class: fields and parameters live in different scopes, and a parameter
with the same name hides the field for the duration of the method. `this->width` (or a different
parameter name, or a member initializer list) is how a method names its own object's field
unambiguously. This is exactly why textbooks introduce `this` in the "writing classes" module.

## The Correction

```cpp
// before
Rectangle(double width, double height) {
    width = width;
    height = height;
}

// after
Rectangle(double width, double height) {
    this->width = width;
    this->height = height;
}
// or, equivalently:
// Rectangle(double width, double height) : width(width), height(height) {}
```

## Instructor Notes

- Renaming the parameters (`double w, double h`) is an equally valid fix; use it to discuss
  style: some codebases forbid shadowing, others prefer `this->` or an initializer list.
- Ask what would print if the fields had *no* in-class initializer (`double width;`). Answer:
  undefined behavior — usually garbage. The zeros here are only because the fields were
  initialized; point out that "prints 0" is not the same as "is correct."
- Note that the member initializer list `: width(width)` does not suffer from shadowing: the name
  before the parentheses always denotes the member.

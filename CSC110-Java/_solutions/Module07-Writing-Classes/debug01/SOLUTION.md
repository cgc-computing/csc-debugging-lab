# Solution: Rectangle Class

**Course/Module/Activity:** CSC110 · Module 7 Writing Classes · debug01
**Bug type(s):** logic
**Bug count:** 1 (the same misconception on both constructor lines)

## Observed Behavior

Both rectangles report 0.0 for everything until a setter is used:

```
Poster: 0.0 x 0.0
  area = 0.0, perimeter = 0.0
Photo:  0.0 x 0.0
  area = 0.0, perimeter = 0.0
After widening the photo to 5 inches:
  area = 0.0, perimeter = 10.0
```

## The Bug(s)

`Rectangle.java`, constructor:

```java
public Rectangle(double width, double height) {
    width = width;
    height = height;
}
```

The parameters shadow the fields, so each statement assigns a parameter to itself.

## Why the Program Behaved Incorrectly

When a parameter has the same name as a field, the bare name refers to the parameter (the innermost declaration). `width = width;` copies the parameter's value into the parameter — a no-op. The fields `width` and `height` are never assigned and keep their default value of 0.0. The setters work because their parameters are named `newWidth`/`newHeight`, so the bare `width` inside them does refer to the field — which is why the perimeter becomes 10.0 (2 × (5 + 0)) after `setWidth`.

## The Concept This Illustrates

Scope and shadowing, and the purpose of `this`. A constructor parameter that shares a field's name hides that field for the duration of the constructor; `this.width` is the way to name the field explicitly. Students often assume Java "knows" that the left side must be the field.

## The Correction

```java
// before
width = width;
height = height;

// after
this.width = width;
this.height = height;
```

## Instructor Notes

- Renaming the parameters (`double w, double h`) also fixes it. Discuss the trade-off: `this.x = x` is the standard idiom and keeps names meaningful.
- Ask students to explain why the setters did *not* have this problem, even though they never use `this`.
- Some IDEs and `javac -Xlint` do not flag self-assignment; this is a good reminder that "it compiled" is a low bar.
- Follow-up: what would `this.width = this.width;` do? (Also nothing — the parameter is never read.)

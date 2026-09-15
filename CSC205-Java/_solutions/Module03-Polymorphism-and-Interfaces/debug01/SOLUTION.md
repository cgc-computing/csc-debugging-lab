# Solution: Shape Area Totals

**Course/Module/Activity:** CSC205 · Module 3 Polymorphism and Interfaces · debug01
**Bug type(s):** conceptual/design, logic
**Bug count:** 1

## Observed Behavior

```
circle     area = 78.54
rectangle  area = 24.00
triangle   area = 0.00
Total area: 102.54
```

## The Bug(s)

`Triangle.java` declares `public double getArea()` instead of `public double area()`. Because the name differs, it is a new, unrelated method, not an override of `Shape.area()`. `Shape.area()` is a concrete method returning `0.0`, so the polymorphic call falls back to that default and the compiler has nothing to complain about.

## Why the Program Behaved Incorrectly

Dynamic dispatch selects the most specific *override* of the method named in the call. `s.area()` is resolved against the methods named `area` with no parameters; `Triangle` has none, so the inherited `Shape.area()` runs and returns `0.0`. `Triangle.getArea()` is never called by anyone.

## The Concept This Illustrates

Overriding requires an identical signature (name and parameter list). Module 3 introduces two tools that prevent exactly this mistake: `@Override`, which makes the compiler verify that a method really overrides something, and `abstract` methods, which force every concrete subclass to provide an implementation. A concrete "default" `area()` returning `0.0` in an abstract class silently hides missing overrides.

## The Correction

```java
// Triangle.java  (before)
public double getArea() { return 0.5 * base * height; }

// after
@Override
public double area() { return 0.5 * base * height; }

// Shape.java  (before)
public double area() { return 0.0; }
// after
public abstract double area();
```

## Instructor Notes

- Students will often rename the method and stop. Push for the second half: make `Shape.area()` abstract and add `@Override`, then ask them to reintroduce the typo and read the compiler message.
- Some will "fix" `Main` by calling `((Triangle) s).getArea()` inside an `instanceof` check. Ask what that does to the point of having a `Shape[]` at all.
- Ask: "Why does `Shape` being abstract not force `Triangle` to implement `area()` in the original code?" (Only *abstract methods* impose that obligation; an abstract class may have concrete methods.)

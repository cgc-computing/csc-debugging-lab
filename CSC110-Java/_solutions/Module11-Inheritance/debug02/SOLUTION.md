# Solution: Box Office Ticket Pricing

**Course/Module/Activity:** CSC110 · Module 11 Inheritance · debug02
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

Student tickets are charged full price while senior tickets are discounted correctly:

```
Noah     Regular  $ 12.00
Elena    Student  $ 12.00
Walter   Senior   $  8.40
Kai      Student  $ 12.00

Total collected: $44.40
```

## The Bug(s)

`StudentTicket.java`:

```java
public double cost(int baseFare) {
    return baseFare * 0.5;
}
```

The parameter type is `int`, but `Ticket.cost` takes a `double`. This method *overloads* `cost` instead of overriding it.

## Why the Program Behaved Incorrectly

Overriding requires the same name and the same parameter list. `cost(int)` has a different parameter type from `cost(double)`, so `StudentTicket` now has two `cost` methods: the inherited `cost(double)` and its own `cost(int)`. `BoxOffice` calls `sold[i].cost(BASE_FARE)` through a `Ticket` reference with a `double` argument; the compiler binds that call to `cost(double)`, and at run time the only `cost(double)` a `StudentTicket` has is the inherited one that returns the full fare. The `cost(int)` method is never called by anyone. `SeniorTicket` matches the signature exactly, so its override is chosen.

## The Concept This Illustrates

Override versus overload, and how dynamic dispatch selects a method: the *signature* is fixed at compile time from the reference type and argument types; only the *implementation* is chosen at run time from the object's class. A near-miss signature silently creates an overload. `getType()` in the same class overrides correctly, which is why the label says "Student" while the price says "Regular".

## The Correction

```java
// before
public double cost(int baseFare) {

// after
public double cost(double baseFare) {
```

## Instructor Notes

- Adding `@Override` above `cost` in `StudentTicket` turns this bug into a compile error ("method does not override or implement a method from a supertype"). This is the single most convincing demonstration of why the annotation is worth typing every time.
- Ask students to predict what `new StudentTicket("x").cost(12)` (an `int` literal, through a `StudentTicket` reference) would return — 6.0, because now `cost(int)` is the best match. This shows the method *exists*, it just is not the one polymorphism reaches.
- Students sometimes "fix" it by casting in `BoxOffice` (`(int) BASE_FARE`); it breaks the regular and senior tickets. Redirect to the class.
- Contrast with `getType()` which has no parameters and therefore cannot be mis-overloaded this way.

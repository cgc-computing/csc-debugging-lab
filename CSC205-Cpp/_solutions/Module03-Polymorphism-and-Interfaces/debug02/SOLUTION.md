# Solution: Store Catalog Interface

**Course/Module/Activity:** CSC205 · Module 3 Polymorphism and Interfaces · debug02
**Bug type(s):** syntax/compile, conceptual/design
**Bug count:** 1

## Observed Behavior

The program does not compile. Apple clang reports (abridged):

```
catalog.cpp:35:20: error: non-virtual member function marked 'override' hides virtual member function
    double price() override { return minutes > 120 ? 14.99 : 9.99; }
catalog.cpp:15:20: note: hidden overloaded virtual function 'Sellable::price' declared here: different qualifiers ('const' vs unqualified)
catalog.cpp:50:27: error: allocating an object of abstract class type 'Movie'
    catalog.push_back(new Movie("Hackers", 105));
catalog.cpp:15:20: note: unimplemented pure virtual method 'price' in 'Movie'
```

(g++ on Linux words the first error as "'price' marked 'override' but does not override any member functions".)

## The Bug(s)

In `Movie`, `price()` is declared without `const`:

```cpp
double price() override { ... }          // Movie
virtual double price() const = 0;        // Sellable
```

The `const` qualifier is part of the function's signature, so `Movie::price()` is a *new* function, not an override of `Sellable::price() const`.

## Why the Program Behaved Incorrectly

Overriding requires the same name, the same parameter list, and the same cv-qualification (`const`). Because the qualifiers differ, `Movie` still has an unimplemented pure virtual `price() const` and is therefore abstract; `new Movie(...)` is illegal. The `override` keyword makes the root cause explicit: the compiler says outright that the function overrides nothing. Without `override`, the only error would be the more confusing "abstract class" message at the `new` expression.

## The Concept This Illustrates

An interface is a contract about *exact* signatures. `const` on a member function is not a stylistic detail; it changes the type of the implicit `this` parameter. Students who learned Java, where there is no `const` member qualifier, tend to treat it as optional. This activity also shows why `override` is worth writing every time: it turns a silent hiding/overloading mistake into a precise compile error.

## The Correction

```cpp
// before
double price() override { return minutes > 120 ? 14.99 : 9.99; }
// after
double price() const override { return minutes > 120 ? 14.99 : 9.99; }
```

## Instructor Notes

- Some students remove the `override` keyword to make the first error go away, then get stuck on the "abstract class" error. Use this to explain that the keyword is a *check*, not a cause.
- Others will remove `const` from the interface instead. That compiles, but then `price()` cannot be called on a `const Sellable*`, which `catalogTotal` uses. Ask them to try it and read the new error; it is a good `const`-correctness lesson.
- Ask: "If `Movie::price()` had a parameter — `price(int quantity)` — what would the compiler say?" (Same override error; parameters are part of the signature too.)
- Point out the expected output formats `14` rather than `14.00`; that is normal `cout` behavior and not part of the exercise.

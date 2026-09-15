# Solution: Safe Integer Division

**Course/Module/Activity:** CSC110 · Module 13 Exceptions · debug02
**Bug type(s):** syntax/compile
**Bug count:** 1

## Observed Behavior

The program does not compile:

```
SafeDivider.java:26: error: exception NumberFormatException has already been caught
        } catch (NumberFormatException e) {
          ^
SafeDivider.java:28: error: exception ArithmeticException has already been caught
        } catch (ArithmeticException e) {
          ^
2 errors
```

## The Bug(s)

`SafeDivider.java`, in `main`: the `catch` blocks are ordered from most general to most specific.

```java
} catch (Exception e) {
    ...
} catch (NumberFormatException e) {
    ...
} catch (ArithmeticException e) {
    ...
}
```

## Why the Program Behaved Incorrectly

`catch` clauses are tried in order and the first one whose type matches (including by inheritance) wins. `Exception` is the superclass of both `NumberFormatException` and `ArithmeticException`, so a `catch (Exception e)` placed first would swallow every exception, and the two specific handlers after it could never execute. Java treats unreachable `catch` blocks as a compile-time error rather than silently ignoring them — which is why this shows up as an error rather than as wrong output.

## The Concept This Illustrates

The exception class hierarchy and its consequence for handler ordering: specific before general. The compiler is being helpful here; in some other languages (and in Java for unrelated types) misordering compiles and simply produces the wrong message at run time. Students should learn to read "has already been caught" as "a handler above this one is broader than this one."

## The Correction

```java
// after
} catch (NumberFormatException e) {
    System.out.println("Both entries must be whole numbers.");
} catch (ArithmeticException e) {
    System.out.println("Cannot divide by zero.");
} catch (Exception e) {
    System.out.println("Something went wrong: " + e.getMessage());
}
```

## Instructor Notes

- Some students fix the compile error by deleting the two specific handlers. It compiles and prints the generic message for everything — the README forbids this; ask what the user loses.
- Ask whether the order of `NumberFormatException` and `ArithmeticException` relative to *each other* matters (no — neither is a subclass of the other).
- Have students trigger all three paths after the fix. Getting `Something went wrong` to appear is hard on purpose; ask what kind of exception could reach it.
- Preview for later courses: `catch (Exception e)` as a first resort is a code smell; discuss why catching only what you can actually handle is better.

# Solution: Two-Dice Showdown

**Course/Module/Activity:** CSC110 · Module 3 Using Classes and Objects · debug02
**Bug type(s):** boundary
**Bug count:** 1 (the same misconception appears in all four die rolls)

## Observed Behavior

Dice show 0, which no real die can:

```
Player 1 rolls: 0 and 2
Player 1 total: 2

Player 2 rolls: 0 and 4
Player 2 total: 4
```

## The Bug(s)

`DiceGame.java`, in `main`, each of the four roll statements:

```java
int player1Die1 = generator.nextInt(6);
```

`nextInt(6)` returns a value in the range 0 through 5, not 1 through 6.

## Why the Program Behaved Incorrectly

`Random.nextInt(bound)` returns a uniformly distributed value from 0 (inclusive) to `bound` (exclusive). A bound of 6 yields six possible values 0–5. The seed 2024 happens to produce 0 as the first and third values, so the symptom is visible immediately.

## The Concept This Illustrates

Reading and trusting library documentation over intuition: "six-sided die" does not mean `nextInt(6)` gives 1–6. Half-open ranges (`0` to `bound - 1`) are the norm in Java and in most of computing, and shifting a range means adding an offset.

## The Correction

```java
// before
int player1Die1 = generator.nextInt(6);

// after
int player1Die1 = generator.nextInt(6) + 1;
```

Apply to all four roll statements.

## Instructor Notes

- The fix must go on all four rolls; students who fix only the rolls that printed 0 have not understood the range. Ask why 2 and 4 are also "wrong" values (they came from the same 0–5 range).
- A common wrong fix is `nextInt(7)`, which produces 0–6. Ask them to explain the possible outputs of that call.
- Java 17+ also offers `generator.nextInt(1, 7)` (origin inclusive, bound exclusive). If a student uses it, ask why the second argument is 7.
- After the fix, the printed rolls with this seed are 1, 3, 1, 5. Changing the seed changes the values, which is why the README asks students to leave it alone.

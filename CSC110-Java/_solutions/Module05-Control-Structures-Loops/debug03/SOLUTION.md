# Solution: Quiz Average with a Sentinel

**Course/Module/Activity:** CSC110 · Module 5 Control Structures: Loops · debug03
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

The sentinel is counted as a score and its value (−1) is added to the total:

```
Scores entered: 4
Total points:   269
Average:        67.25
```

Entering `-1` first reports one score with average −1.00 instead of "No scores were entered."

## The Bug(s)

`SentinelAverage.java`, in `main`, the `do-while` loop accumulates the value before checking whether it is the sentinel:

```java
do {
    System.out.print("Score: ");
    score = keyboard.nextInt();
    sum += score;
    count++;
} while (score != SENTINEL);
```

## Why the Program Behaved Incorrectly

A `do-while` loop tests its condition *after* the body runs. So when the user enters −1, `sum += score` and `count++` have already executed for that value before `score != SENTINEL` is evaluated and ends the loop. Every run therefore includes exactly one bogus "score" of −1.

## The Concept This Illustrates

Sentinel-controlled loops need to check the value *between* reading it and processing it. A `do-while` places the test after processing, which is the wrong shape for this problem; the standard idiom is a priming read followed by a `while` whose body processes the value and then reads the next one.

## The Correction

```java
// before
do {
    System.out.print("Score: ");
    score = keyboard.nextInt();
    sum += score;
    count++;
} while (score != SENTINEL);

// after (priming read + while)
System.out.print("Score: ");
score = keyboard.nextInt();
while (score != SENTINEL) {
    sum += score;
    count++;
    System.out.print("Score: ");
    score = keyboard.nextInt();
}
```

## Instructor Notes

- An equally valid fix keeps the `do-while` and guards the accumulation: `if (score != SENTINEL) { sum += score; count++; }`. Ask which version reads more clearly and which is easier to get wrong.
- Some students "fix" it by subtracting the sentinel afterwards (`sum += 1; count--;`). It gives the right numbers here; ask what happens if the sentinel is changed to −999, and whether the code still expresses the intent.
- Ask: what should happen if the user enters −1 first? Have them test the `No scores were entered.` path before and after the fix.

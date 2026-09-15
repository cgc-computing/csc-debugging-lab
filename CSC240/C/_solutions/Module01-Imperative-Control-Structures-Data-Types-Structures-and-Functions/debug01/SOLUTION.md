# Solution: Temperature Statistics

**Course/Module/Activity:** CSC240 · Module 1 Imperative Control Structures, Data Types, Structures, and Functions · debug01
**Bug type(s):** runtime (crash), conceptual/design
**Bug count:** 1

## Observed Behavior

The program compiles, but `gcc -Wall` warns:

```
temperature_stats.c:47:17: warning: format specifies type 'int *' but the argument has type 'int' [-Wformat]
```

When run, it prints the prompt and then crashes as soon as the count is typed:

```
How many readings? 5
zsh: segmentation fault  ./temperature_stats
```

## The Bug(s)

`main`, the first `scanf` call:

```c
scanf("%d", n);
```

The variable `n` is passed by value instead of passing its address `&n`.

## Why the Program Behaved Incorrectly

`scanf` needs somewhere to *store* the number it reads, so `%d` expects a pointer to an `int`. The program hands it the *value* of `n`, which was initialized to `0`. `scanf` treats that `0` as an address and tries to write the number 5 to memory location 0, which the operating system forbids; the process is killed with a segmentation fault. The loop that reads the individual readings uses `&readings[i]` correctly, so only the first `scanf` is wrong.

## The Concept This Illustrates

C passes every argument by value. A called function can only change a variable in the caller if it is given that variable's *address*. Java students are used to library methods "returning" values or mutating objects through references; in C the `&` operator is how you hand a function permission to write into your variable. The compiler warning is the first clue and students should learn to read it rather than ignore it.

## The Correction

```c
/* before */
scanf("%d", n);

/* after */
scanf("%d", &n);
```

## Instructor Notes

- Ask students to explain why `scanf("%d", &readings[i])` in the loop is correct while the first call is not. Both pass an address; one just does it with an array element.
- Some students will "fix" the crash by changing `int n = 0;` to `int n;`. Point out that this makes the behavior *worse*: it becomes undefined instead of a reliable crash, and the warning is still there.
- Follow-up: what does `scanf` *return*? Checking that return value is how real programs detect bad input.
- Windows students may see "the program has stopped working" instead of "segmentation fault"; the cause is identical.

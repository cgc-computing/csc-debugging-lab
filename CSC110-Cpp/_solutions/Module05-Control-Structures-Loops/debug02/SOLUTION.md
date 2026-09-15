# Solution: Launch Countdown

**Course/Module/Activity:** CSC110 · Module 5 Control Structures: Loops · debug02
**Bug type(s):** logic (stray semicolon; compiles)
**Bug count:** 1

## Observed Behavior

The program compiles (clang prints `warning: for loop has empty body [-Wempty-body]`) and runs,
but prints only one countdown line, with the wrong number:

```
Start the countdown from: 5
T-minus 0
Liftoff!
```

## The Bug(s)

`countdown.cpp`, `main`:

```cpp
for (t = start; t >= 1; t--);
{
    cout << "T-minus " << t << endl;
}
```

The semicolon after the closing parenthesis of the `for` header is the loop's entire body (an
empty statement). The braces that follow are an ordinary block that runs once, after the loop.

## Why the Program Behaved Incorrectly

The loop does execute five times, but its body is the empty statement `;`, so nothing prints
while `t` counts down 5, 4, 3, 2, 1. The loop ends when `t` becomes `0` (`0 >= 1` is false). Then
the block `{ cout << "T-minus " << t << endl; }` runs exactly once with `t == 0`. Because `t` was
declared before the loop, it is still in scope and holds the exit value.

## The Concept This Illustrates

The body of a `for` (or `while`) is the single statement that follows the header — a block only if
you attach one with braces. A trailing `;` is a complete, empty statement. Indentation and braces
mean nothing to the compiler; the syntax alone decides what is repeated. The `-Wall` warning is
the compiler noticing that the loop repeats nothing.

## The Correction

```cpp
// before
for (t = start; t >= 1; t--);
{
    cout << "T-minus " << t << endl;
}

// after
for (t = start; t >= 1; t--) {
    cout << "T-minus " << t << endl;
}
```

## Instructor Notes

- Ask students to explain *why* the output says `0` rather than `1` — it forces them to trace the
  update and test steps at loop exit.
- If a student declares `t` inside the header (`for (int t = ...);`) without removing the
  semicolon, the block no longer compiles (`t` undeclared). That error message is a useful
  second clue; discuss why.
- Reinforce reading warnings: the compiler told them exactly what happened before they ran it.

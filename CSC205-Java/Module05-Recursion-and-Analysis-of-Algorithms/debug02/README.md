# Recursive Character Count

**Course:** CSC205 &nbsp;|&nbsp; **Module 5:** Recursion and Analysis of Algorithms &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`countChar(s, c)` returns how many times character `c` appears in string `s`, computed recursively by looking at the first character and recursing on the rest. `reverse(s)` reverses a string the same way.

## Expected Behavior

```
s in mississippi: 4
a in banana:      3
a in aardvark:    3
z in hello:       0
reverse(recursion) = noisrucer
```

## How to Run

```bash
javac StringRecursion.java
java StringRecursion
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep both methods recursive.

## Think About

- In a recursive method, what happens to the value a recursive call returns if the caller does not use it?
- For `countChar("aardvark", 'a')`, what does the very first call know on its own, and what must it learn from the rest of the string?
- Compare the structure of `reverse` with `countChar`: how does `reverse` combine its own piece of work with the recursive result?

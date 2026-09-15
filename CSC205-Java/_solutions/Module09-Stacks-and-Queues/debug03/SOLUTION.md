# Solution: Balanced Brackets Checker

**Course/Module/Activity:** CSC205 · Module 9 Stacks and Queues · debug03
**Bug type(s):** logic, boundary, runtime
**Bug count:** 2

## Observed Behavior

```
"(a + b) * [c]"  balanced
"{[()]}"         balanced
"[(])"           NOT balanced
"((a)"           balanced
Exception in thread "main" java.lang.RuntimeException: stack is empty
	at CharStack.pop(CharStack.java:24)
	at BracketChecker.isBalanced(BracketChecker.java:10)
	at BracketChecker.main(BracketChecker.java:35)
```

## The Bug(s)

Both in `BracketChecker.java`, `isBalanced`:

1. On a closing bracket the code calls `stack.pop()` without first checking `stack.isEmpty()`. A closing bracket with nothing open (`")("`) should mean "not balanced", but instead the stack throws.
2. After the loop the method returns `true` unconditionally. If openers remain on the stack (`"((a)"`), the string is *not* balanced; the method should return `stack.isEmpty()`.

## Why the Program Behaved Incorrectly

`"((a)"`: two pushes, one pop that matches, loop ends with one `(` still on the stack — but the code never looks, and returns `true`. `")("`: the first character is a closer; `pop` on an empty stack throws `RuntimeException`, which propagates out of `isBalanced` and kills the program before the remaining tests run.

## The Concept This Illustrates

The stack algorithm for balanced brackets has three failure modes, and each maps to a stack condition: (a) *mismatch* — the popped opener does not pair with the closer; (b) *too many closers* — a closer arrives while the stack is empty; (c) *too many openers* — the stack is non-empty when the input ends. Students typically implement (a) and forget that "empty when it should not be" and "non-empty when it should be" are the other two halves of the same invariant. Checking `isEmpty()` before `pop()` is the general discipline for any stack client.

## The Correction

```java
// closing-bracket branch, before
char open = stack.pop();
// after
if (stack.isEmpty()) {
    return false;
}
char open = stack.pop();

// end of method, before
return true;
// after
return stack.isEmpty();
```

## Instructor Notes

- Some students wrap the `pop()` in `try { ... } catch (RuntimeException e) { return false; }`. It works; ask whether using an exception for an expected input condition is good design, and what `isEmpty()` is for.
- Others change `CharStack.pop()` to return a sentinel like `'\0'` when empty, which quietly moves the check into the data structure. Discuss where the responsibility belongs (the README says `CharStack` is correct).
- Ask students to classify each test string by which of the three failure modes it exercises; `"[(])"` is the mismatch case, and both original bugs leave it working — a good reminder that passing some tests proves little.
- Extension: report the *index* of the first offending character.

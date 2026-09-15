# Solution: Balanced Brackets Checker

**Course/Module/Activity:** CSC205 · Module 9 Stacks and Queues · debug03
**Bug type(s):** logic, runtime (null pointer dereference)
**Bug count:** 2 (related: both are missing checks of the stack's emptiness in `isBalanced`)

## Observed Behavior

With `-fsanitize=address`:

```
"(a + b) * [c - d]" -> balanced
"{[()]}" -> balanced
"[(])" -> NOT balanced
"((a + b)" -> balanced
AddressSanitizer:DEADLYSIGNAL
=================================================================
==...==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000
    #0 ... in CharStack::pop()
    #1 ... in isBalanced(std::string const&)
    #2 ... in main
```

The fourth string, which is missing a closing parenthesis, is reported as balanced. The fifth string, which has a closing parenthesis with nothing open, crashes the program inside `pop()`. Without the sanitizer the crash appears as `Segmentation fault: 11` at the same point.

## The Bug(s)

`bracket_checker.cpp`, function `isBalanced`:

1. On a closing bracket the code calls `stack.pop()` unconditionally. If the stack is empty, `pop()` dereferences `top`, which is `nullptr`.
2. After the loop the function `return true;` regardless of whether anything is still on the stack.

## Why the Program Behaved Incorrectly

For `"((a + b)"`, two `(` are pushed and one is popped by the single `)`. The loop ends with one `(` still on the stack — an unclosed bracket — but the function ignores the stack and returns true.

For `"a + b)"`, the `)` arrives with nothing pushed. `pop()` executes `Node* old = top;` where `top` is `nullptr`, then reads `old->data`, a read through a null pointer. The sanitizer reports the SEGV at address 0 inside `CharStack::pop`, called from `isBalanced`.

## The Concept This Illustrates

A stack-based matcher relies on two symmetric facts: every closer needs an opener *already on the stack*, and every opener needs a closer *before the input ends*. The first is a check before `pop`; the second is a check of `isEmpty()` after the loop. Students who write only the "does the top match?" test have understood the nesting idea but not the two boundary states of the stack — empty when it should not be, and non-empty when it should be. It also illustrates that a documented precondition (`pop` requires a non-empty stack) is a contract the *caller* must honor.

## The Correction

```cpp
// before
} else if (isClosing(c)) {
    char open = stack.pop();
    ...
}
return true;

// after
} else if (isClosing(c)) {
    if (stack.isEmpty()) {
        return false;
    }
    char open = stack.pop();
    ...
}
return stack.isEmpty();
```

## Instructor Notes

- Students often fix the crash by making `pop()` return a sentinel such as `'\0'` when empty. That happens to make `matches('\0', ')')` false, so the test passes — but ask whether `pop` should be responsible for a decision that belongs to `isBalanced`, and what happens the next time someone uses `CharStack` for something else. Either design is defensible if it is deliberate; the point is that *someone* must check.
- Some students find the crash, fix it, and stop. Ask them to rerun and read the output for `"((a + b)"`; the second bug is silent.
- Ask: "Could you replace the stack with a counter of open brackets?" Let them try `"[(])"` — a counter cannot detect wrong nesting order, which is exactly why a stack is the right structure.
- Follow-up: have them add `<` `>` as a fourth pair and see how many places need to change; then discuss a lookup table versus the chain of `||`.

# Solution: Integer Stack Module

**Course/Module/Activity:** CSC240 · Module 3 C Preprocessor, User-Defined Types, and Modules · debug02
**Bug type(s):** syntax/compile (declaration mismatch), syntax/compile (link error from `static`), conceptual/design
**Bug count:** 2 (related: both are interface-vs-implementation disagreements in a multi-file module)

## Observed Behavior

The build fails in `stack.c`:

```
stack.c:35:5: error: conflicting types for 'stack_pop'
   35 | int stack_pop(struct stack *s, int *value)
      |     ^
./stack.h:19:6: note: previous declaration is here
   19 | int  stack_pop(struct stack *s);               /* caller must check stack_is_empty first */
```

After that is fixed, compilation succeeds for both files but the link step fails:

```
Undefined symbols for architecture arm64:
  "_op_count", referenced from:
      _main in main-xxxxxx.o
ld: symbol(s) not found for architecture arm64
```

(On Linux: `undefined reference to 'op_count'`.)

## The Bug(s)

1. `stack.c` defines `int stack_pop(struct stack *s, int *value)` with an out-parameter, but `stack.h` declares (and `main.c` uses) `int stack_pop(struct stack *s)` returning the popped value. Because `stack.c` includes its own header, the compiler sees both and rejects the definition.
2. `stack.c` declares the operation counter `static int op_count = 0;`. File-scope `static` gives the variable *internal linkage*: it exists only inside `stack.c`'s translation unit. `main.c`'s `extern int op_count;` promises the linker that some other file defines a global `op_count`, and none does.

## Why the Program Behaved Incorrectly

Each `.c` file is compiled separately into an object file with no knowledge of the others. The header is the contract that makes the pieces fit. In bug 1 the implementation broke the contract, and including the header in `stack.c` is exactly what let the compiler notice. In bug 2 the contract was never written down at all: `main.c` invented its own declaration, and the linker, which is the first tool to see both object files together, reported that the promised symbol does not exist because `static` hid it.

## The Concept This Illustrates

Separate compilation. A header describes what a module offers; every `.c` file that includes it (the implementation included) is checked against it. `static` at file scope is how a module keeps something private, and `extern` is how a client asks for something a module has chosen to make public. The two keywords are opposite promises, and this module makes both at once.

## The Correction

Bug 1, `stack.c`:

```c
/* before */
int stack_pop(struct stack *s, int *value)
{
    s->top--;
    *value = s->items[s->top];
    op_count++;
    return 1;
}

/* after */
int stack_pop(struct stack *s)
{
    s->top--;
    op_count++;
    return s->items[s->top];
}
```

Bug 2: remove `static` from the definition in `stack.c` and move the `extern int op_count;` declaration into `stack.h`, deleting it from `main.c`, so the header is again the single statement of the interface.

## Instructor Notes

- Students may instead change the header and `main.c` to the out-parameter style. That also works and is a fine discussion ("who owns the interface?"), but the README asks them to keep the client as written.
- Some will "fix" bug 2 by defining `int op_count;` in `main.c`. That links, and the program prints `0`, because `main.c` and `stack.c` now have two *different* variables. Ask what the two `op_count`s are and which one the stack increments.
- The cleaner design, worth raising after the fix: keep `static int op_count` private and export `int stack_op_count(void);` from the module. Ask why hiding the variable is better than exposing it.
- Note the header guard: it is correct here. Ask what would happen if `stack.h` were included twice in one file without it (the `struct stack` definition would be repeated and rejected).
- Pop does not check for an empty stack; the header documents that as the caller's job. That is a design choice, not the bug.

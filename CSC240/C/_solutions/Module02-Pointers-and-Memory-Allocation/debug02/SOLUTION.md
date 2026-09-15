# Solution: Word Copies

**Course/Module/Activity:** CSC240 · Module 2 Pointers and Memory Allocation · debug02
**Bug type(s):** runtime (heap overflow), boundary
**Bug count:** 2 (related: both undersized `malloc` requests)

## Observed Behavior

Compiles cleanly with `-Wall`. Under `-fsanitize=address` the program aborts immediately with a report like:

```
==12345==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x... 
WRITE of size 1 at 0x... thread T0
    #0 0x... in copy_string word_copies.c:18
    #1 0x... in main word_copies.c:42
0x... is located 0 bytes after 7-byte region [0x...,0x...)
allocated by thread T0 here:
    #0 0x... in malloc
    #1 0x... in copy_string word_copies.c:13
```

After the first bug is fixed, a second report appears:

```
==12346==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x...
WRITE of size 4 at 0x... thread T0
    #0 0x... in make_length_table word_copies.c:30
...
0x... is located 0 bytes after 5-byte region
```

Without the sanitizer the program usually prints the correct output by luck, because the allocator rounds small requests up. That is exactly why the README insists on the sanitizer.

## The Bug(s)

1. `copy_string`: `char *copy = malloc(length);` allocates room for the characters but not for the terminating `'\0'`. The copy loop `for (i = 0; i <= length; i++)` correctly copies `length + 1` bytes, so the terminator is written one byte past the block.
2. `make_length_table`: `int *lengths = malloc(count);` allocates `count` **bytes** (5) rather than `count` **ints** (20). Storing `lengths[1]` already writes past the end.

## Why the Program Behaved Incorrectly

Both calls hand `malloc` a number that is not the number of bytes actually needed. `malloc` does not know what type you intend to store; it returns exactly the bytes you asked for. Writing beyond the block is undefined behavior: sometimes it works, sometimes it corrupts the allocator's bookkeeping so a later `free` crashes, and under ASan it is reported at the exact write.

## The Concept This Illustrates

Dynamic memory in C is *sized by the programmer*. Two things Java hides: (a) C strings carry an invisible extra byte for the terminator, so the storage size is `strlen(s) + 1`; (b) arrays are requested in bytes, so the size is `n * sizeof(element)`. Getting the count right is the whole skill in this module.

## The Correction

```c
/* before */
char *copy = malloc(length);
int *lengths = malloc(count);

/* after */
char *copy = malloc(length + 1);
int *lengths = malloc(count * sizeof(int));
```

## Instructor Notes

- The sanitizer stops at the first error, so students fix the string copy, rerun, and discover the second one. Use that: "you fixed one undersized allocation; where else does this file call `malloc`?"
- A common alternative fix for bug 1 is changing the loop to `i < length`, which makes the report go away but leaves the copy without a terminator; `printf("%s")` then reads garbage (ASan may report a heap-buffer-overflow *read* in `printf`). Ask what `%s` uses to know where the string ends.
- `malloc(count * sizeof *lengths)` or `calloc(count, sizeof(int))` are equally good for bug 2.
- If a student's toolchain lacks ASan (some MinGW installs), have them add a `printf` after each `malloc` showing the requested size and reason about it.

# Solution: Grade Book

**Course/Module/Activity:** CSC240 · Module 2 Pointers and Memory Allocation · debug03
**Bug type(s):** runtime (crash), conceptual/design
**Bug count:** 1

## Observed Behavior

Compiles cleanly with `-Wall`. The count is right, then the program crashes when it tries to print the first score:

```
Loaded 7 scores
Scores:zsh: segmentation fault  ./grade_book
```

(When output is redirected to a file the two lines may not appear because the buffer is never flushed; in a terminal they do.) The allocated block is also leaked.

## The Bug(s)

`load_scores(int *scores, int *count)` assigns the result of `malloc` to its **local copy** of the pointer:

```c
void load_scores(int *scores, int *count)
{
    ...
    scores = malloc(n * sizeof(int));
    ...
}
/* in main */
int *scores = NULL;
load_scores(scores, &count);
```

`main`'s `scores` stays `NULL`.

## Why the Program Behaved Incorrectly

`count` works because `main` passes `&count`, so `*count = n` writes into `main`'s variable. `scores` is passed by value: the function receives the value `NULL`, overwrites its own parameter with the new heap address, fills that array correctly, and returns; the parameter dies and the heap block is orphaned. Back in `main`, `scores[0]` dereferences `NULL`, which the OS refuses, hence the segmentation fault. `free(NULL)` at the end would have been harmless, but the program never gets there.

## The Concept This Illustrates

To let a function change a variable, pass the variable's address. That rule does not stop applying when the variable is itself a pointer: to change an `int *`, pass an `int **`. Students often internalize "pointers let functions modify things" and miss that the pointer variable itself is just another value that was copied. The `count` parameter in the same function is the model to imitate.

## The Correction

```c
/* before */
void load_scores(int *scores, int *count) { ... scores = malloc(...); ... scores[i] = raw[i]; }
load_scores(scores, &count);

/* after */
void load_scores(int **scores, int *count) { ... *scores = malloc(...); ... (*scores)[i] = raw[i]; }
load_scores(&scores, &count);
```

## Instructor Notes

- An equally good fix is `int *load_scores(int *count)` that returns the new pointer: `scores = load_scores(&count);`. Accept it and ask why the count still needs to go through a pointer.
- Students who write `*scores[i] = raw[i]` get a compile error or a crash because `[]` binds tighter than `*`; the parentheses in `(*scores)[i]` matter. A local `int *arr = *scores;` after the allocation is a cleaner way to write the loop.
- A tempting non-fix: declaring the array in `main` and passing it in. It "works" but abandons dynamic allocation, which is the point of the module.
- The `-Wall` build gives no warning here. Ask students why the compiler cannot catch this one when it caught the `scanf` mistake in Module 1.
- Compare with debug01: same underlying idea (a pointer parameter is a copy), one level of indirection deeper.

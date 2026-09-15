# Solution: Score List

**Course/Module/Activity:** CSC240 · Module 2 Memory Management · debug01
**Bug type(s):** runtime (use-after-free / double free), conceptual/design (Rule of Three)
**Bug count:** 1 (missing copy control; it bites twice in `main`)

## Observed Behavior

Compiles cleanly with `-Wall`. The first two lines print correctly, then the address sanitizer aborts the program the first time `quiz` is touched after `average` returns:

```
Quiz 1: 88 92 75 100
Average: 88.75
=================================================================
==4242==ERROR: AddressSanitizer: heap-use-after-free on address 0x... at pc ...
READ of size 4 at 0x... thread T0
    #0 ... in ScoreList::get(int) const score_list.cpp:25
    #1 ... in main score_list.cpp:65
0x... is located 0 bytes inside of 16-byte region [...]
freed by thread T0 here:
    #0 ... in operator delete[](void*)
    #1 ... in ScoreList::~ScoreList() score_list.cpp:21
    #2 ... in main score_list.cpp:60
previously allocated by thread T0 here:
    #0 ... in operator new[](unsigned long)
    #1 ... in ScoreList::ScoreList(int) score_list.cpp:12
    #2 ... in main score_list.cpp:53
```

Line 60 is the call `average(quiz)`: the freeing destructor belongs to the by-value parameter. Without the sanitizer the program prints garbage for the last two rows (one run gave `Curved: 100 5 7 5` and `Backup: 100 5 7 5`, the freed block having been reused by the allocator) and then aborts at exit with a `malloc: double free` / `free(): double free detected` message, because three destructors try to release the same block.

## The Bug(s)

`ScoreList` owns a raw pointer but declares only a constructor and destructor. It has **no copy constructor and no copy-assignment operator**, so the compiler generates member-wise copies:

```cpp
double average(ScoreList list)   // parameter is copy-constructed from quiz
...
ScoreList backup = quiz;         // copy-constructed from quiz
```

Both copies receive the *same* `scores_` pointer as `quiz`.

## Why the Program Behaved Incorrectly

1. `average(quiz)` copy-constructs `list`; `list.scores_ == quiz.scores_`. When `average` returns, `list`'s destructor runs `delete[] scores_`, freeing the block that `quiz` still points to. `quiz` is now dangling.
2. `ScoreList backup = quiz;` copies the dangling pointer again.
3. The curve loop reads and writes through `quiz.scores_`, which is freed memory: ASan reports the first read in `get`.
4. Had it continued, `backup` and `quiz` would both print whatever the freed block holds, and at the end of `main` two more `delete[]` calls would hit the already-freed block.

## The Concept This Illustrates

The **Rule of Three**: a class that manages a resource in its destructor almost always needs a user-written copy constructor and copy-assignment operator too, because the compiler-generated versions copy the *handle* (the pointer), not the *resource* (the array). Java students have never had to choose between shallow and deep copies at this level; `=` in Java always copies a reference and the garbage collector never frees an object that is still referenced. In C++ the class author decides what copying means, and "do nothing" means "share and double-free".

## The Correction

Add deep-copying copy control:

```cpp
// before: only these two exist
explicit ScoreList(int size);
~ScoreList();

// after: Rule of Three
ScoreList(const ScoreList& other)
    : size_(other.size_), scores_(new int[other.size_])
{
    for (int i = 0; i < size_; i++) scores_[i] = other.scores_[i];
}

ScoreList& operator=(const ScoreList& other)
{
    if (this != &other) {
        int* fresh = new int[other.size_];
        for (int i = 0; i < other.size_; i++) fresh[i] = other.scores_[i];
        delete[] scores_;
        scores_ = fresh;
        size_ = other.size_;
    }
    return *this;
}
```

## Instructor Notes

- The most common "fix" is changing `average` to take `const ScoreList&`. That removes the first copy, and the sanitizer report moves to the end of `main` (double free from `backup` and `quiz`). It is a good change in itself, but the class is still broken; the README forbids changing `average`'s signature to keep the focus on the class.
- Students who write only the copy constructor pass this program. Ask them what `backup = quiz;` (assignment to an *existing* object) would do and why the Rule says *three*. The corrected file includes the assignment operator; point out the self-assignment check and the allocate-before-delete ordering.
- Some students propose `= delete` for the copy operations. That is a legitimate design (non-copyable class) and turns both copies into compile errors; discuss when that is the right call versus deep copying.
- Modern follow-up: replacing `int*` with `std::vector<int>` makes the compiler-generated copies correct automatically. Ask why.
- The Rule of Five (`move` operations) is beyond this module; mention it only if a student asks about `std::move`.

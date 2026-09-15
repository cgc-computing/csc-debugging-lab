# Solution: Expense Report

**Course/Module/Activity:** CSC240 · Module 3 C Preprocessor, User-Defined Types, and Modules · debug03
**Bug type(s):** logic, boundary
**Bug count:** 2 (related: both break the enum-as-index correspondence)

## Observed Behavior

Compiles cleanly with `-Wall`. The labels are wrong for three rows, the "Other" row is missing, and the grand total is short by 55.00:

```
Category        Total
Food           260.00
Other         1150.00
Rent            82.50
Travel         119.35
ALL           1611.85
```

## The Bug(s)

1. `category_names` is not in enumerator order:
   ```c
   static const char *category_names[CATEGORY_COUNT] = {
       "Food", "Other", "Rent", "Travel", "Utilities"
   };
   ```
   The enum is `FOOD=0, RENT=1, TRAVEL=2, UTILITIES=3, OTHER=4`, so `category_names[RENT]` is `"Other"`, and so on. (The names were alphabetized after "Food".)
2. `print_report` loops `for (int c = FOOD; c < OTHER; c++)`, which stops *before* `OTHER` (value 4), so the last real category is never printed or added to the grand total.

## Why the Program Behaved Incorrectly

`add_expense` indexes `totals` by the enumerator's integer value, so the totals themselves are correct: `totals[1]` really is the rent. The names table is a *parallel array* that only works if its element order matches the enum's numbering, and here it does not. Separately, the loop bound uses the last enumerator instead of the sentinel `CATEGORY_COUNT`; `c < OTHER` excludes `OTHER` itself.

## The Concept This Illustrates

An `enum` in C is just a set of named integers. Using it as an array index is idiomatic and efficient, but it creates an invisible dependency: every table indexed by the enum must list its entries in exactly the enum's order, and every loop over the enum must run to the sentinel count that is declared *last* for that purpose. Java students think of enums as objects with their own fields (`Category.RENT.label()`); in C the "field" is a separate array that the programmer must keep aligned by hand.

## The Correction

```c
/* before */
static const char *category_names[CATEGORY_COUNT] = {
    "Food", "Other", "Rent", "Travel", "Utilities"
};
...
for (int c = FOOD; c < OTHER; c++) {

/* after */
static const char *category_names[CATEGORY_COUNT] = {
    "Food", "Rent", "Travel", "Utilities", "Other"
};
...
for (int c = FOOD; c < CATEGORY_COUNT; c++) {
```

## Instructor Notes

- Students frequently fix the loop first (`c <= OTHER`), which prints the fifth row but with the labels still scrambled; that is a fine intermediate step but ask why `CATEGORY_COUNT` exists and why `<= OTHER` breaks as soon as a category is appended after `OTHER`.
- Some students will reorder the *enum* to match the names. That also "works" but reorders the report; point out that the enum is the source of truth and everything else follows it.
- C99/C11 designated initializers make the alignment self-enforcing: `[FOOD] = "Food", [RENT] = "Rent", ...`. Show this as the robust fix and connect it to the `typedef struct { ... } expense_t;` pattern in the same file (an anonymous struct given a name via `typedef`).
- Follow-up question from the README: adding `HEALTH` before `CATEGORY_COUNT` requires exactly one more string in the names table and nothing else, *if* the loop uses the count.

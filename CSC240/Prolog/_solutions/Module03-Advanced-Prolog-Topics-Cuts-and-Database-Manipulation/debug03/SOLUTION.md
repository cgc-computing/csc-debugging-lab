# Solution: Sales Log

**Course/Module/Activity:** CSC240 · Module 3 Advanced Prolog Topics, Cuts, and Database Manipulation · debug03
**Bug type(s):** logic, paradigm-specific (`retract` vs `retractall`; `bagof` free-variable grouping vs `findall`)
**Bug count:** 2 (related: both use an "all matching facts" operation that actually processes one group or one clause at a time)

## Observed Behavior

Desk-checked (no SWI-Prolog on the authoring machine). The file loads cleanly. The sales and per-item reads are right; the total comes out split in two, and after the reset stale tallies survive:

```prolog
?- sell(apples), sell(apples), sell(pears).
true.

?- sales(apples, N).
N = 2.

?- sales(pears, N).
N = 1.

?- total_sold(T).
T = 2 ;
T = 1.

?- reset_sales.
true 

?- sales(pears, N).
N = 1 ;
N = 0.

?- total_sold(T).
T = 0 ;
T = 1.
```

(After `reset_sales` SWI-Prolog prints `true` and **waits** instead of finishing with a period: `retract/1` left a choice point because another `sold` fact still matched. The transcript assumes you press Enter to accept. Pressing `;` instead retracts that other fact and asserts two more zeros, printing a second `true`, then `false.`, and leaving four `sold` facts. The waiting prompt is itself a clue.)

## The Bug(s)

1. `total_sold` collects with `bagof/3`, whose goal contains a free variable (`_`, the item):
   ```prolog
   bagof(N, sold(_, N), Ns)
   ```
2. `reset_sales` clears the tallies with `retract/1`, which removes **one** clause:
   ```prolog
   retract(sold(_, _)),
   ```

## Why the Program Behaved Incorrectly

**Bug 1.** `bagof/3` treats every variable in the goal that is not in the template (and not marked with `^`) as a *free variable* and produces one bag **per distinct binding** of it, backtracking through them. The anonymous `_` is still a variable, so `bagof(N, sold(_, N), Ns)` yields `Ns = [2]` for apples and then `Ns = [1]` for pears (sorted by the free variable's value), and `total_sold` reports `2` then `1` instead of `3`. `findall/3` has no free-variable rule; it collects every solution into one list.

**Bug 2.** Trace the fact order. Each `sell` retracts a fact and re-asserts it at the *end* of the database, so after the three sales the facts are `sold(apples, 2). sold(pears, 1).` in that order. `reset_sales` then retracts exactly one matching clause, `sold(apples, 2)`, and asserts two zeros, leaving:

```prolog
sold(pears, 1).
sold(apples, 0).
sold(pears, 0).
```

Hence `sales(pears, N)` has two answers and, with bug 1 still present, `total_sold` groups them: apples `[0]` → `0`, pears `[1, 0]` → `1`. Even with `findall` the total after reset would be `1`, not `0`, until bug 2 is fixed.

## The Concept This Illustrates

Database manipulation in Prolog is procedural and per-clause: `assert` adds one clause, `retract` removes one (the first that unifies) and can be backtracked into for the next, `retractall` removes every match and always succeeds. Likewise the collecting predicates differ in what "all" means: `findall/3` gathers every solution regardless of other variables and returns `[]` when there are none; `bagof/3` and `setof/3` group by free variables and *fail* when there are no solutions. A student who thinks of `retract` as "delete where" and `bagof` as "select all" will write exactly this file.

## The Correction

```prolog
% before
total_sold(Total) :-
    bagof(N, sold(_, N), Ns),
    sum_list(Ns, Total).

reset_sales :-
    retract(sold(_, _)),
    ...

% after
total_sold(Total) :-
    findall(N, sold(_, N), Ns),
    sum_list(Ns, Total).

reset_sales :-
    retractall(sold(_, _)),
    ...
```

(`bagof(N, Item^sold(Item, N), Ns)` is the other way to fix bug 1, at the cost of failing on an empty database.)

## Instructor Notes

- `?- listing(sold).` before and after each step is the best debugging tool here; make students use it before they touch the code.
- For bug 1, have students run `?- bagof(N, sold(I, N), Ns).` with a named variable `I`; seeing `I = apples, Ns = [2] ; I = pears, Ns = [1]` explains what the `_` was doing.
- A partial fix some students try for bug 2 is calling `retract` twice. It works for exactly two items; ask what happens when `oranges` is added. Others write a recursive `retract_all_sold :- retract(sold(_, _)), retract_all_sold.` with a base case; that is essentially re-implementing `retractall`, and a fine conversation.
- Ask why `sell/1` is *correct* with plain `retract`: it intends to remove exactly one fact (the item's current tally), and the first argument is bound so only one clause can match.
- `assert/1` is a legacy alias of `assertz/1` in SWI-Prolog; if students ask, `assertz` (add at end) and `asserta` (add at front) are the explicit forms. Note that the fact *order* changing on every `sell` is what made bug 2 visible.
- Emphasize that the dynamic database is global mutable state, the very thing the rest of the language avoids; that is why the README insists the queries be run in order and why "quit and reload" is the reset of last resort.

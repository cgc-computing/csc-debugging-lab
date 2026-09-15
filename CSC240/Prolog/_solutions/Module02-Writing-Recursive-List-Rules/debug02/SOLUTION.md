# Solution: List Reverse

**Course/Module/Activity:** CSC240 · Module 2 Writing Recursive List Rules · debug02
**Bug type(s):** logic, paradigm-specific (`[H|T]` builds at the front; appending requires `append`)
**Bug count:** 1

## Observed Behavior

Desk-checked (no SWI-Prolog on the authoring machine). The file loads cleanly. `my_reverse` returns its input unchanged:

```prolog
?- my_append([1, 2], [3], L).
L = [1, 2, 3].

?- my_reverse([1, 2, 3], R).
R = [1, 2, 3].

?- my_reverse([a], R).
R = [a].

?- my_reverse([], R).
R = [].

?- my_reverse([1, 2, 3], [3, 2, 1]).
false.
```

## The Bug(s)

The recursive clause puts the head back on the **front** of the reversed tail:

```prolog
my_reverse([H|T], R) :-
    my_reverse(T, RT),
    R = [H|RT].
```

## Why the Program Behaved Incorrectly

`[H|RT]` is the list whose first element is `H` and whose rest is `RT`. Trace from the inside out:

| call | `H` | `RT` (reversed tail) | `R = [H|RT]` |
|---|---|---|---|
| `my_reverse([3], R)` | 3 | `[]` | `[3]` |
| `my_reverse([2,3], R)` | 2 | `[3]` | `[2,3]` |
| `my_reverse([1,2,3], R)` | 1 | `[2,3]` | `[1,2,3]` |

Each level correctly reverses the tail and then undoes the work by putting the head back where it started. The result is always the original list, which is why the one-element and empty cases look fine and the three-element case is the identity.

## The Concept This Illustrates

List notation in Prolog gives direct access to the **front** only. `[H|T]` decomposes or builds at the head; there is no `[T|H]` for the back. To place an element at the end you must *append* a one-element list, which is itself a recursive walk (`my_append(RT, [H], R)`). This is the Prolog version of the `cons`-vs-`append` distinction from the Scheme module, and Java programmers used to `list.add(x)` (which appends) reach for `[H|RT]` because it is the only construction syntax they have seen.

## The Correction

```prolog
% before
my_reverse([H|T], R) :-
    my_reverse(T, RT),
    R = [H|RT].

% after
my_reverse([H|T], R) :-
    my_reverse(T, RT),
    my_append(RT, [H], R).
```

(The built-in `append(RT, [H], R)` is equally correct.)

## Instructor Notes

- A frequent wrong attempt is `my_append(RT, H, R)` (forgetting the brackets). `my_append([], 3, L)` gives `L = 3`, and the next level tries `my_append(3, [2], R)`, which fails. Ask what the second argument of `append` must be.
- Another: `R = [RT|H]`. That produces nested, improper lists such as `[[[[]|3]|2]|1]`. Reading that output aloud is useful; it is the Prolog cousin of Scheme's dotted pairs.
- Ask students why the corrected version is O(n²) and introduce the accumulator version (`rev(L, R) :- rev(L, [], R).` with `rev([H|T], Acc, R) :- rev(T, [H|Acc], R).`) as the idiomatic solution in which `[H|Acc]` *is* the right construction.
- `my_reverse([1,2,3], [3,2,1])` failing before the fix is worth pointing out: Prolog predicates are relations, and a checking query is just as good a test as a computing query.

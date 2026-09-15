# Solution: Inventory Search by Item

**Course/Module/Activity:** CSC205 · Module 10 Searching · debug02
**Bug type(s):** conceptual/design, logic
**Bug count:** 2 (same misconception in `indexOf` and `count`)

## Observed Behavior

```
indexOf pliers (#1003): 2
indexOf wrench (#1002): -1
count   wrench (#1002): 0
indexOf drill (#2001): -1
```

The search finds an item only when the caller passes the *exact same object* that is stored on the shelf; a freshly constructed but identical `Item` is reported missing.

## The Bug(s)

`ItemSearch.java`:

1. `indexOf`: `if (items[i] == target)` — compares references.
2. `count`: `if (it == target)` — same mistake.

`Item` overrides `equals` (and `hashCode`) correctly, but the search never calls it.

## Why the Program Behaved Incorrectly

`==` on two object references asks "are these the same object in memory?" `shelf[2]` and `sameObject` are the same reference, so the first search succeeds. `new Item("wrench", 1002)` creates a brand-new object; no element of `shelf` is that object, so `==` is false for every slot and `indexOf` falls through to `-1`, while `count` never increments.

## The Concept This Illustrates

Searching a collection of objects means comparing by *value*, which in Java is `equals`, not by *identity*, which is `==`. The `Item` class went to the trouble of defining equality; a search that ignores it can only ever find the object it was handed. The same misconception appears with `String` (Module 1 of this course), but with user-defined classes there is no interning to accidentally make `==` work, so the failure is consistent.

## The Correction

```java
// indexOf, before
if (items[i] == target) {
// after
if (items[i].equals(target)) {

// count, before
if (it == target) {
// after
if (it.equals(target)) {
```

## Instructor Notes

- Ask why the *first* search works. Students who answer "because pliers is in the array" have not yet separated identity from equality; push until they say "because it is literally the same object."
- Some students will fix `indexOf` and forget `count`, or vice versa. The output exposes both, so make them run it again.
- Some will compare fields directly (`items[i].getSku() == target.getSku()`). That works here, but ask: "Why did the author write `equals`? What happens when `Item` gains a third field?"
- Follow-up: "What would happen if `Item` had *not* overridden `equals`?" (`Object.equals` is `==`, so the fix would change nothing — leads naturally into why `equals`/`hashCode` matter for `ArrayList.contains`, `HashSet`, etc.)

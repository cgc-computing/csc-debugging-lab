# Solution: Honor Roll Ordering

**Course/Module/Activity:** CSC205 · Module 3 Polymorphism and Interfaces · debug02
**Bug type(s):** logic, conceptual/design
**Bug count:** 1

## Observed Behavior

The roster comes out in its original insertion order; the sort changes nothing:

```
Honor roll order:
1. Ana   3.20
2. Ben   3.90
3. Cleo  2.80
4. Dev   3.50
5. Eli   3.85
```

## The Bug(s)

`Student.java`, `compareTo`: `return (int) (other.gpa - this.gpa);` casts the difference of two `double` values to `int`. Any difference with magnitude less than 1.0 truncates to `0`, which tells the sort the two students are equal.

## Why the Program Behaved Incorrectly

`3.90 - 3.20 = 0.70` → `(int) 0.70 == 0`, so Ben and Ana compare as equal and the (stable) sort leaves them in insertion order. Only pairs whose GPAs differ by at least 1.0 (Ben vs Cleo, Eli vs Cleo) produce a non-zero result, and for this data every such pair is already in an order the comparator accepts, so the insertion sort that `Arrays.sort` uses for small arrays never moves anything. Worse, the relation is not *transitive*: Ana (3.20) "equals" Ben (3.90) and Ana "equals" Cleo (2.80), yet Ben and Cleo compare as different. Such inconsistencies violate the `Comparable` contract and make the sort's output depend on the algorithm and the input order rather than on the data.

## The Concept This Illustrates

Implementing an interface means honoring its *contract*, not just its method signature. `compareTo` must return a negative, zero, or positive value consistently (sign-consistent, transitive). Subtracting and casting is a habit that works for `int` fields (until overflow) and quietly fails for `double`. `Double.compare(a, b)` exists exactly for this.

## The Correction

```java
// before
return (int) (other.gpa - this.gpa);
// after
return Double.compare(other.gpa, this.gpa);
```

## Instructor Notes

- A common "fix" is `(int) ((other.gpa - this.gpa) * 100)`. It works for this data; ask what happens with GPAs 3.851 and 3.855, or for very large values. Then show `Double.compare`.
- Another is to write `if (this.gpa > other.gpa) return -1; else return 1;` — ask what happens for equal GPAs (violates `compareTo(x) == 0` symmetry; can make `sort` misbehave).
- Ask students to swap the arguments and predict the order (ascending), reinforcing that the *sign* carries the meaning.
- Note for Java `int` fields: `a - b` overflows for large magnitudes; `Integer.compare` is the analogue.

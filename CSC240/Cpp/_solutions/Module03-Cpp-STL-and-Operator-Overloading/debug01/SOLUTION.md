# Solution: Book Catalog

**Course/Module/Activity:** CSC240 · Module 3 C++ STL and Operator Overloading · debug01
**Bug type(s):** logic, conceptual/design (ordering defines equivalence in ordered containers)
**Bug count:** 1

## Observed Behavior

Compiles cleanly with `-Wall`. The second 2005 book is rejected as a duplicate and the catalog has only four titles:

```
Added   The C Programming Language (1978)
Added   The Little Schemer (1974)
Added   Programming in Prolog (1981)
Added   Effective C++ (2005)
Skipped Learn Prolog Now (2005): already in catalog
Skipped The Little Schemer (1974): already in catalog

Catalog by year (4 titles):
  1974  The Little Schemer
  1978  The C Programming Language
  1981  Programming in Prolog
  2005  Effective C++
```

## The Bug(s)

`Book::operator<` compares **only** the year:

```cpp
bool operator<(const Book& other) const
{
    return year < other.year;
}
```

## Why the Program Behaved Incorrectly

`std::set` has no notion of `==`. Two elements `a` and `b` are *equivalent*, and therefore duplicates, exactly when `!(a < b) && !(b < a)`. For `Effective C++` (2005) and `Learn Prolog Now` (2005) neither year is less than the other, so the set treats the second book as already present and `insert` returns `second == false`. The program's "Skipped" branch then prints the misleading message. The genuine duplicate (`The Little Schemer` added twice) is also rejected, as intended, so the output looks half right.

## The Concept This Illustrates

In the ordered STL containers (`std::set`, `std::map`, and in `std::sort` + `std::unique`) the comparison operator does double duty: it defines the order **and** it defines equality. An ordering that ignores part of the object silently merges distinct objects. The comparison must be a strict weak ordering *and* it must distinguish every pair of elements the program considers different, which usually means a lexicographic comparison over all identifying fields with a tie-breaker. Java's `TreeSet` behaves identically with `compareTo`, but Java students rarely write `compareTo` by hand for a set; here they must.

## The Correction

Compare by year, then break ties by title:

```cpp
// before
return year < other.year;

// after
if (year != other.year) {
    return year < other.year;
}
return title < other.title;
```

(`return std::tie(year, title) < std::tie(other.year, other.title);` with `<tuple>` is the idiomatic one-liner.)

## Instructor Notes

- A common wrong fix is `return year <= other.year;`. That makes the two 2005 books "different" but violates the strict-weak-ordering requirement (`a < a` becomes true); the set's behavior is then undefined and in practice you get duplicates of the *real* duplicate or a corrupted tree. Ask what `a < a` should return for any sane ordering.
- Another attempt: add `bool operator==` to `Book`. `std::set` never calls it; the output does not change. Good moment to ask which operations the container actually uses.
- Some students will "fix" the message rather than the ordering (print "Skipped: same year"). Point out that the requirement is five books in the catalog.
- Follow-up: if the catalog should treat two editions with the same title and year as the same book, the current fix is right. If ISBN were available, that would be the natural tie-breaker. The choice of what makes two objects "the same" is a design decision the ordering has to express.
- The ordering also decides the printed order within 2005 (`Effective C++` before `Learn Prolog Now`, alphabetically). Ask students to predict it before running the corrected version.

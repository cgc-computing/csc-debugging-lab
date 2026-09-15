# Solution: Word Counting with a Chained Hash Table

**Course/Module/Activity:** CSC310 · Module 4 Hash Tables · debug03
**Bug type(s):** runtime, logic (sign of hash-to-index mapping)
**Bug count:** 1

## Observed Behavior

```
libc++abi: terminating due to uncaught exception of type std::out_of_range: vector
```

The program aborts (exit status 134) before printing anything: the second word, `analysis`, produces a negative bucket index.

## The Bug(s)

`word_count_table.cpp`, `WordCountTable::hashCode` and `bucketIndex`:

```cpp
int hashCode(const std::string& key) const {
    std::uint32_t h = 0;
    for (unsigned char c : key) h = 31 * h + c;
    return static_cast<int>(h);                 // may be negative
}
int bucketIndex(const std::string& key) const {
    return hashCode(key) % static_cast<int>(table_.size());   // negative % 13 is <= 0
}
```

## Why the Program Behaved Incorrectly

The polynomial over an 8-letter word exceeds 2³¹, so when the unsigned 32-bit value is converted to `int` it becomes negative (for `analysis`, −1024445732). In C++ the remainder takes the sign of the dividend, so `-1024445732 % 13` is `-11`. `table_.at(-11)` converts the negative index to a huge `size_t` and throws `std::out_of_range`. Short words (`the`, `of`) never overflow, which is why the failure depends on the input text. Had the table used `operator[]`, this would have been an out-of-bounds pointer read (undefined behavior) rather than a clean exception.

## The Concept This Illustrates

A hash *code* is an arbitrary machine word; a bucket *index* must lie in `[0, m)`. The reduction step must be written so that it cannot go negative: do the arithmetic in an unsigned type and reduce before converting, or normalize with `((h % m) + m) % m`, or mask off the sign bit as Java's `HashMap` does. Students coming from Java often know that `hashCode()` can be negative but do not realize that C++'s `%` preserves the sign of the left operand, so `h % m` is not a valid index. The activity also shows why a table's correctness can depend on the *data* (word length) rather than on the code path.

## The Correction

```cpp
std::uint32_t hashCode(const std::string& key) const {
    std::uint32_t h = 0;
    for (unsigned char c : key) h = 31 * h + c;
    return h;
}
int bucketIndex(const std::string& key) const {
    return static_cast<int>(hashCode(key) % table_.size());
}
```

## Instructor Notes

- `std::abs(hashCode(key)) % m` is a popular fix; it fails for `INT_MIN` (undefined behavior in `std::abs`). `((h % m) + m) % m` is fine. Ask students to compare the three and say which is safest.
- The sample text was chosen so that the *second* word triggers the failure. Have students add a print inside `add` to find the offending word, then compute its hash by hand or in a tiny test program.
- Note that the unsigned accumulation is deliberate: unsigned overflow wraps modulo 2³², whereas `int` overflow is undefined behavior. The conversion of an out-of-range `std::uint32_t` to `int` is implementation-defined (modular on every mainstream compiler), so the failing word is the same on every platform students are likely to use.

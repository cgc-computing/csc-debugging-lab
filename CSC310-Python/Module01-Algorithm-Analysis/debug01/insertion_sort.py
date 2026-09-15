"""Insertion sort with a comparison counter.

Sorts a list in place following the INSERTION-SORT procedure from CLRS
(Chapter 2) and counts key comparisons so that best-case and worst-case
inputs can be compared against the Theta(n) and Theta(n^2) predictions.
"""


def insertion_sort(A):
    """Sort A in place; return the number of key comparisons performed."""
    comparisons = 0
    for j in range(1, len(A)):
        key = A[j]
        # Insert A[j] into the sorted prefix A[0 .. j-1].
        i = j - 1
        while i > 0 and A[i] > key:
            comparisons += 1
            A[i + 1] = A[i]
            i -= 1
        if i >= 0:
            comparisons += 1        # the comparison that stopped the loop
        A[i + 1] = key
    return comparisons


def main():
    samples = [
        [5, 2, 4, 6, 1, 3],
        [31, 41, 59, 26, 41, 58],
        [3, 1, 2],
        [9, 8, 7, 6, 5, 4, 3, 2, 1],
    ]
    for data in samples:
        original = list(data)
        count = insertion_sort(data)
        ok = data == sorted(original)
        print(f"{original} -> {data}")
        print(f"   sorted correctly: {ok}   comparisons: {count}")

    print()
    print("Comparison counts by input shape (n = 8):")
    n = 8
    best = list(range(n))
    worst = list(range(n, 0, -1))
    print(f"   already sorted : {insertion_sort(best)}   (expected n-1 = {n - 1})")
    print(f"   reverse sorted : {insertion_sort(worst)}   (expected n(n-1)/2 = {n * (n - 1) // 2})")


if __name__ == "__main__":
    main()

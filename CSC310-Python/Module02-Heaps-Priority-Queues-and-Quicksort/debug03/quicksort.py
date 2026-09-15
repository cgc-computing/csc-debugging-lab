"""Quicksort with Lomuto partitioning (CLRS Chapter 7).

PARTITION(A, p, r) uses A[r] as the pivot and rearranges A[p..r] so that
every element before the pivot is <= the pivot and every element after it
is > the pivot.  QUICKSORT then recurses on the two sides.  Indices p and
r are inclusive, matching the pseudocode.
"""


def partition(A, p, r):
    x = A[r]                     # pivot
    i = p - 1                    # end of the "<= pivot" region
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i


def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q - 1)
        quicksort(A, q + 1, r)


def sort(A):
    quicksort(A, 0, len(A) - 1)
    return A


def main():
    samples = [
        [13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11],
        [2, 8, 7, 1, 3, 5, 6, 4],
        [10, 80, 30, 90, 40, 50, 70],
        [3, 3, 1, 2, 3, 1],
    ]
    for data in samples:
        original = list(data)
        sort(data)
        print(f"{original}")
        print(f"  -> {data}   correct: {data == sorted(original)}")

    # Partition alone, as in the CLRS Figure 7.1 example.
    A = [2, 8, 7, 1, 3, 5, 6, 4]
    q = partition(A, 0, len(A) - 1)
    print()
    print("partition of [2, 8, 7, 1, 3, 5, 6, 4] with pivot 4:")
    print(f"  array {A}, pivot index {q}, A[q] = {A[q]}")


if __name__ == "__main__":
    main()

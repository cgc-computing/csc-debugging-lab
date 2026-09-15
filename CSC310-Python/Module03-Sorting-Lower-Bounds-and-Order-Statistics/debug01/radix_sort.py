"""LSD radix sort built on counting sort (CLRS Chapter 8).

counting_sort_by_digit sorts a list of non-negative integers by one
decimal digit using the COUNTING-SORT scheme: count occurrences, take
prefix sums, then place each element into the output array.  radix_sort
applies it to the ones digit, then the tens digit, and so on.
"""


def digit(x, place):
    """The decimal digit of x at the given place (0 = ones, 1 = tens, ...)."""
    return (x // 10 ** place) % 10


def counting_sort_by_digit(A, place):
    """Return a new list with A sorted by the digit at 'place'."""
    k = 10
    C = [0] * k
    for x in A:
        C[digit(x, place)] += 1
    # C[d] now holds the number of elements whose digit is <= d.
    for d in range(1, k):
        C[d] += C[d - 1]
    B = [None] * len(A)
    for x in A:
        d = digit(x, place)
        B[C[d] - 1] = x
        C[d] -= 1
    return B


def radix_sort(A, num_digits):
    for place in range(num_digits):
        A = counting_sort_by_digit(A, place)
    return A


def main():
    data = [329, 457, 657, 839, 436, 720, 355]
    print("input :", data)
    print("pass 1:", counting_sort_by_digit(data, 0))
    result = radix_sort(data, 3)
    print("sorted:", result)
    print("correct:", result == sorted(data))

    print()
    ids = [1043, 2087, 1049, 3011, 2043, 1011, 3087, 2011]
    result = radix_sort(ids, 4)
    print("student ids sorted:", result)
    print("correct:", result == sorted(ids))


if __name__ == "__main__":
    main()

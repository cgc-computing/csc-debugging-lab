"""Binary max-heap stored in a Python list.

Implements PARENT, LEFT, RIGHT, MAX-HEAPIFY and BUILD-MAX-HEAP from CLRS
Chapter 6 on a 0-based list, plus HEAP-INSERT (bubble up).  The main
block builds a heap two ways, bottom-up and by repeated insertion, and
extracts the elements in decreasing order from each.
"""


def parent(i):
    return (i - 1) // 2


def left(i):
    return 2 * i + 1


def right(i):
    return 2 * i + 2


def max_heapify(A, i, heap_size):
    """Float A[i] down until the subtree rooted at i is a max-heap."""
    l = left(i)
    r = right(i)
    largest = i
    if l < heap_size and A[l] > A[largest]:
        largest = l
    if r < heap_size and A[r] > A[largest]:
        largest = r
    if largest != i:
        A[i], A[largest] = A[largest], A[i]
        max_heapify(A, largest, heap_size)


def build_max_heap(A):
    n = len(A)
    for i in range(n // 2 - 1, -1, -1):
        max_heapify(A, i, n)


def heap_insert(A, key):
    """Append key and bubble it up toward the root."""
    A.append(key)
    i = len(A) - 1
    while i > 0 and A[parent(i)] < A[i]:
        A[i], A[parent(i)] = A[parent(i)], A[i]
        i = parent(i)


def extract_all(A):
    """Repeatedly remove the maximum; returns the values in the order removed."""
    heap_size = len(A)
    order = []
    while heap_size > 0:
        order.append(A[0])
        heap_size -= 1
        A[0] = A[heap_size]
        max_heapify(A, 0, heap_size)
    return order


def main():
    data = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 11]
    want = sorted(data, reverse=True)

    A = list(data)
    build_max_heap(A)
    print("bottom-up build   :", A)
    order = extract_all(list(A))
    print("extract order     :", order)
    print("descending order? :", order == want)
    print()

    B = []
    for key in data:
        heap_insert(B, key)
    print("built by insertion:", B)
    order = extract_all(list(B))
    print("extract order     :", order)
    print("descending order? :", order == want)


if __name__ == "__main__":
    main()

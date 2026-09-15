"""Heapsort and a max-priority queue sharing one MAX-HEAPIFY.

Follows CLRS Chapter 6: BUILD-MAX-HEAP, HEAPSORT, and the priority-queue
operations MAXIMUM, EXTRACT-MAX, INCREASE-KEY and INSERT, all on 0-based
Python lists.  The heap occupies A[0 .. heap_size-1]; anything past
heap_size belongs to the sorted region (heapsort) or is unused.
"""


def left(i):
    return 2 * i + 1


def right(i):
    return 2 * i + 2


def parent(i):
    return (i - 1) // 2


def max_heapify(A, i, heap_size):
    l, r = left(i), right(i)
    largest = i
    if l < len(A) and A[l] > A[largest]:
        largest = l
    if r < len(A) and A[r] > A[largest]:
        largest = r
    if largest != i:
        A[i], A[largest] = A[largest], A[i]
        max_heapify(A, largest, heap_size)


def build_max_heap(A):
    n = len(A)
    for i in range(0, n // 2):
        max_heapify(A, i, n)


def heapsort(A):
    build_max_heap(A)
    heap_size = len(A)
    for i in range(len(A) - 1, 0, -1):
        A[0], A[i] = A[i], A[0]
        heap_size -= 1
        max_heapify(A, 0, heap_size)


class MaxPriorityQueue:
    def __init__(self, items=()):
        self._A = list(items)
        build_max_heap(self._A)

    def __len__(self):
        return len(self._A)

    def maximum(self):
        return self._A[0]

    def extract_max(self):
        if not self._A:
            raise IndexError("heap underflow")
        top = self._A[0]
        last = self._A.pop()
        if self._A:
            self._A[0] = last
            max_heapify(self._A, 0, len(self._A))
        return top

    def increase_key(self, i, key):
        if key < self._A[i]:
            raise ValueError("new key is smaller than current key")
        self._A[i] = key
        while i > 0 and self._A[parent(i)] < self._A[i]:
            self._A[i], self._A[parent(i)] = self._A[parent(i)], self._A[i]
            i = parent(i)

    def insert(self, key):
        self._A.append(float("-inf"))
        self.increase_key(len(self._A) - 1, key)


def main():
    data = [16, 4, 10, 14, 7, 9, 3, 2, 8, 1]
    A = list(data)
    heapsort(A)
    print("heapsort:", A)
    print("sorted correctly:", A == sorted(data))

    B = [5, 13, 2, 25, 7, 17, 20, 8, 4]
    heapsort(B)
    print("heapsort:", B)
    print("sorted correctly:", B == sorted([5, 13, 2, 25, 7, 17, 20, 8, 4]))

    pq = MaxPriorityQueue([15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1])
    pq.insert(10)
    pq.increase_key(len(pq) - 1, 11)   # bump the newest key
    drained = []
    while len(pq) > 0:
        drained.append(pq.extract_max())
    print("priority queue drained:", drained)
    print("non-increasing:", all(drained[i] >= drained[i + 1] for i in range(len(drained) - 1)))


if __name__ == "__main__":
    main()

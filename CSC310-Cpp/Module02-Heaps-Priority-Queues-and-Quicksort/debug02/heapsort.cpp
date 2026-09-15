// heapsort.cpp
// HEAPSORT from CLRS on a 0-based array: build a max-heap in place, then
// repeatedly move the maximum to the end of the array and shrink the heap.
#include <iostream>
#include <utility>
#include <vector>

std::size_t left(std::size_t i) { return 2 * i + 1; }
std::size_t right(std::size_t i) { return 2 * i + 2; }

// Restores the max-heap property at index i, assuming the subtrees rooted
// at left(i) and right(i) are already max-heaps. Only indices below
// heapSize belong to the heap.
void maxHeapify(std::vector<int>& a, std::size_t i, std::size_t heapSize) {
    std::size_t l = left(i);
    std::size_t r = right(i);
    std::size_t largest = i;
    if (l < a.size() && a[l] > a[largest]) {
        largest = l;
    }
    if (r < a.size() && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        std::swap(a[i], a[largest]);
        maxHeapify(a, largest, heapSize);
    }
}

// Turns an arbitrary array into a max-heap by heapifying every internal node.
void buildMaxHeap(std::vector<int>& a) {
    std::size_t n = a.size();
    for (std::size_t i = 0; i < n / 2; ++i) {
        maxHeapify(a, i, n);
    }
}

void heapsort(std::vector<int>& a) {
    buildMaxHeap(a);
    std::size_t heapSize = a.size();
    for (std::size_t i = a.size(); i-- > 1;) {
        std::swap(a[0], a[i]);
        --heapSize;
        maxHeapify(a, 0, heapSize);
    }
}

void print(const std::vector<int>& a) {
    for (int x : a) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

bool isSorted(const std::vector<int>& a) {
    for (std::size_t i = 1; i < a.size(); ++i) {
        if (a[i - 1] > a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<int>> tests = {
        {4, 1, 3, 2, 16, 9, 10, 14, 8, 7},
        {5, 13, 2, 25, 7, 17, 20, 8, 4},
        {3, 3, 1, 2, 3, 1},
        {1, 2, 3, 4, 5, 6, 7}
    };
    for (auto& a : tests) {
        std::cout << "input:  ";
        print(a);
        heapsort(a);
        std::cout << "output: ";
        print(a);
        std::cout << (isSorted(a) ? "sorted\n\n" : "NOT SORTED\n\n");
    }
    return 0;
}

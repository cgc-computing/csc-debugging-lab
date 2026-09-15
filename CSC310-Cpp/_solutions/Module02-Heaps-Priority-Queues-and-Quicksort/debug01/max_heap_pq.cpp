// max_heap_pq.cpp
// A max-priority queue implemented on top of a binary max-heap stored in a
// 0-based std::vector. Supports insert, maximum, and extractMax, following
// the procedures MAX-HEAPIFY, HEAP-INCREASE-KEY and MAX-HEAP-INSERT.
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

class MaxHeapPQ {
public:
    bool empty() const { return heap_.empty(); }
    std::size_t size() const { return heap_.size(); }

    int maximum() const {
        if (heap_.empty()) {
            throw std::runtime_error("maximum of empty heap");
        }
        return heap_[0];
    }

    void insert(int key) {
        heap_.push_back(key);
        std::size_t i = heap_.size() - 1;
        // Float the new key up while it is larger than its parent.
        while (i > 0 && heap_[parent(i)] < heap_[i]) {
            std::swap(heap_[i], heap_[parent(i)]);
            i = parent(i);
        }
    }

    int extractMax() {
        if (heap_.empty()) {
            throw std::runtime_error("extractMax of empty heap");
        }
        int max = heap_[0];
        heap_[0] = heap_.back();
        heap_.pop_back();
        if (!heap_.empty()) {
            maxHeapify(0);
        }
        return max;
    }

private:
    static std::size_t parent(std::size_t i) { return (i - 1) / 2; }
    static std::size_t left(std::size_t i) { return 2 * i + 1; }
    static std::size_t right(std::size_t i) { return 2 * i + 2; }

    void maxHeapify(std::size_t i) {
        std::size_t l = left(i);
        std::size_t r = right(i);
        std::size_t largest = i;
        if (l < heap_.size() && heap_[l] > heap_[largest]) {
            largest = l;
        }
        if (r < heap_.size() && heap_[r] > heap_[largest]) {
            largest = r;
        }
        if (largest != i) {
            std::swap(heap_[i], heap_[largest]);
            maxHeapify(largest);
        }
    }

    std::vector<int> heap_;
};

int main() {
    MaxHeapPQ pq;
    int jobs[] = {5, 12, 8, 20, 15, 27, 31, 3, 24};
    for (int j : jobs) {
        pq.insert(j);
        std::cout << "insert " << j << "  (max is now " << pq.maximum() << ")\n";
    }

    std::cout << "extract order:";
    while (!pq.empty()) {
        std::cout << ' ' << pq.extractMax();
    }
    std::cout << '\n';
    return 0;
}

// linear_probing.cpp
// An open-addressing hash table of ints using linear probing:
// h(k, i) = (k mod m + i) mod m for probe number i = 0, 1, ..., m-1.
// Supports insert and contains; the table never grows (fixed capacity m).
#include <iostream>
#include <stdexcept>
#include <vector>

class LinearProbingTable {
public:
    explicit LinearProbingTable(int capacity)
        : slots_(capacity, EMPTY), capacity_(capacity), count_(0) {}

    bool insert(int key) {
        if (count_ == capacity_) {
            throw std::runtime_error("table is full");
        }
        int home = key % capacity_;
        for (int i = 0; i < capacity_; ++i) {
            int idx = (home + i) % capacity_;
            if (slots_.at(idx) == EMPTY) {
                slots_.at(idx) = key;
                ++count_;
                std::cout << "  insert " << key << " -> slot " << idx
                          << " after " << i << " probe(s)\n";
                return true;
            }
            if (slots_.at(idx) == key) {
                return false;   // already present
            }
        }
        return false;
    }

    bool contains(int key) const {
        int home = key % capacity_;
        for (int i = 0; i < capacity_; ++i) {
            int idx = (home + i) % capacity_;
            if (slots_.at(idx) == EMPTY) {
                return false;
            }
            if (slots_.at(idx) == key) {
                return true;
            }
        }
        return false;
    }

    void print() const {
        for (int i = 0; i < capacity_; ++i) {
            std::cout << '[' << i << "]=";
            if (slots_[i] == EMPTY) {
                std::cout << '-';
            } else {
                std::cout << slots_[i];
            }
            std::cout << ' ';
        }
        std::cout << '\n';
    }

private:
    static constexpr int EMPTY = -1;
    std::vector<int> slots_;
    int capacity_;
    int count_;
};

int main() {
    LinearProbingTable table(11);
    int keys[] = {5, 27, 16, 10, 21, 32, 43, 9};
    std::cout << "inserting into a table of capacity 11\n";
    for (int k : keys) {
        table.insert(k);
    }
    table.print();

    for (int k : {16, 21, 32, 43, 7, 54}) {
        std::cout << "contains(" << k << ") = "
                  << (table.contains(k) ? "true" : "false") << '\n';
    }
    return 0;
}

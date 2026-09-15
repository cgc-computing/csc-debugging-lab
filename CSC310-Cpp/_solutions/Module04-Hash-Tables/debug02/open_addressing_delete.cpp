// open_addressing_delete.cpp
// Open-addressing hash set of ints with linear probing that supports
// insert, contains, and remove. Slot states: a stored key, EMPTY (never
// used), or DELETED (a tombstone left behind by remove so that probe
// sequences passing through the slot are not cut short).
#include <iostream>
#include <vector>

class ProbingSet {
public:
    explicit ProbingSet(int capacity) : slots_(capacity, EMPTY), m_(capacity) {}

    bool insert(int key) {
        int firstFree = -1;
        for (int i = 0; i < m_; ++i) {
            int idx = (key % m_ + i) % m_;
            if (slots_[idx] == key) {
                return false;
            }
            if (slots_[idx] == DELETED && firstFree == -1) {
                firstFree = idx;   // may reuse, but keep probing for a duplicate
            }
            if (slots_[idx] == EMPTY) {
                slots_[firstFree == -1 ? idx : firstFree] = key;
                return true;
            }
        }
        if (firstFree != -1) {
            slots_[firstFree] = key;
            return true;
        }
        return false;   // full
    }

    bool contains(int key) const {
        for (int i = 0; i < m_; ++i) {
            int idx = (key % m_ + i) % m_;
            if (slots_[idx] == EMPTY) {
                return false;   // the probe sequence ended without finding key
            }
            if (slots_[idx] == key) {
                return true;
            }
        }
        return false;
    }

    bool remove(int key) {
        for (int i = 0; i < m_; ++i) {
            int idx = (key % m_ + i) % m_;
            if (slots_[idx] == EMPTY) {
                return false;
            }
            if (slots_[idx] == key) {
                slots_[idx] = DELETED;
                return true;
            }
        }
        return false;
    }

    void print() const {
        for (int i = 0; i < m_; ++i) {
            std::cout << '[' << i << "]=";
            if (slots_[i] == EMPTY) {
                std::cout << '-';
            } else if (slots_[i] == DELETED) {
                std::cout << 'x';
            } else {
                std::cout << slots_[i];
            }
            std::cout << ' ';
        }
        std::cout << '\n';
    }

private:
    static constexpr int EMPTY = -1;
    static constexpr int DELETED = -2;
    std::vector<int> slots_;
    int m_;
};

void report(const ProbingSet& s, int key) {
    std::cout << "contains(" << key << ") = " << (s.contains(key) ? "true" : "false") << '\n';
}

int main() {
    ProbingSet s(7);
    for (int k : {7, 14, 21, 3, 10}) {
        s.insert(k);
    }
    std::cout << "after inserts:   ";
    s.print();
    report(s, 21);
    report(s, 10);

    s.remove(14);
    s.remove(3);
    std::cout << "after removals:  ";
    s.print();
    report(s, 21);
    report(s, 10);
    report(s, 14);

    s.insert(28);
    std::cout << "after insert 28: ";
    s.print();
    report(s, 28);
    report(s, 21);
    return 0;
}

// union_find.cpp
// Disjoint-set forest with union by rank and path compression (CLRS 19.3).
// Elements are 0..n-1. The driver performs a sequence of unions and then
// answers connectivity queries and counts the remaining sets.
#include <iostream>
#include <vector>

class DisjointSets {
public:
    explicit DisjointSets(int n) : parent_(n), rank_(n, 0), sets_(n) {
        for (int i = 0; i < n; ++i) {
            parent_[i] = i;
        }
    }

    // Returns the representative of x's set, compressing the path on the way.
    int find(int x) {
        if (parent_[x] != x) {
            parent_[x] = find(parent_[x]);
        }
        return parent_[x];
    }

    void unite(int x, int y) {
        link(find(x), find(y));
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int setCount() const { return sets_; }

    void printParents() const {
        std::cout << "parent:";
        for (int p : parent_) {
            std::cout << ' ' << p;
        }
        std::cout << '\n';
    }

private:
    // Hangs the tree with the smaller rank under the root of the other.
    void link(int a, int b) {
        if (a == b) {
            return;
        }
        if (rank_[a] > rank_[b]) {
            parent_[b] = a;
        } else {
            parent_[a] = b;
            if (rank_[a] == rank_[b]) {
                ++rank_[b];
            }
        }
        --sets_;
    }

    std::vector<int> parent_;
    std::vector<int> rank_;
    int sets_;
};

int main() {
    DisjointSets ds(8);
    std::pair<int, int> unions[] = {{0, 1}, {0, 2}, {3, 4}, {1, 4}, {5, 6}, {2, 3}};
    for (auto [x, y] : unions) {
        ds.unite(x, y);
        std::cout << "union(" << x << ", " << y << ")   sets = " << ds.setCount() << '\n';
    }
    ds.printParents();

    std::pair<int, int> queries[] = {{0, 1}, {1, 2}, {0, 4}, {2, 3}, {5, 6}, {6, 7}, {4, 5}};
    for (auto [x, y] : queries) {
        std::cout << "connected(" << x << ", " << y << ") = "
                  << (ds.connected(x, y) ? "true" : "false") << '\n';
    }
    std::cout << "number of sets: " << ds.setCount() << '\n';
    return 0;
}

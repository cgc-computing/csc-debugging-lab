// floyd_warshall.cpp
// All-pairs shortest paths with the Floyd-Warshall algorithm (CLRS 23.2).
// d[i][j] is the shortest-path weight from i to j using only intermediate
// vertices from an ever-growing prefix of the vertex set.
#include <iomanip>
#include <iostream>
#include <vector>

const int INF = 1000000000;

void printMatrix(const std::vector<std::vector<int>>& d) {
    for (const auto& row : d) {
        for (int x : row) {
            if (x >= INF) std::cout << std::setw(5) << "inf";
            else std::cout << std::setw(5) << x;
        }
        std::cout << '\n';
    }
}

std::vector<std::vector<int>> floydWarshall(std::vector<std::vector<int>> d) {
    const int n = static_cast<int>(d.size());
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] < INF && d[k][j] < INF && d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    return d;
}

int main() {
    // CLRS's Floyd-Warshall example (§23.1), vertices numbered 0..4 (book's 1..5)
    const int n = 5;
    std::vector<std::vector<int>> w(n, std::vector<int>(n, INF));
    for (int i = 0; i < n; ++i) w[i][i] = 0;
    w[0][1] = 3;  w[0][2] = 8; w[0][4] = -4;
    w[1][3] = 1;  w[1][4] = 7;
    w[2][1] = 4;
    w[3][0] = 2;  w[3][2] = -5;
    w[4][3] = 6;

    std::cout << "weight matrix W:\n";
    printMatrix(w);
    std::vector<std::vector<int>> d = floydWarshall(w);
    std::cout << "shortest-path weights D:\n";
    printMatrix(d);
    return 0;
}

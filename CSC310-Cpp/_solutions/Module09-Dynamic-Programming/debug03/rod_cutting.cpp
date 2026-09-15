// rod_cutting.cpp
// Rod cutting (CLRS 14.1) with top-down memoization. price[i] is the price
// of a piece of length i (1 <= i <= 10). cutRod returns the maximum revenue
// for a rod of length n and records the first piece of an optimal cut so the
// full decomposition can be printed. The driver also counts recursive calls
// to show how much work memoization saves.
#include <algorithm>
#include <iostream>
#include <vector>

const std::vector<int> price = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
const int MAX_PIECE = 10;

int cutRodAux(int n, std::vector<int>& memo, std::vector<int>& firstPiece, long& calls) {
    ++calls;
    if (memo.at(n) >= 0) {
        return memo[n];
    }
    int best = 0;
    if (n > 0) {
        best = -1;
        for (int i = 1; i <= std::min(n, MAX_PIECE); ++i) {
            int candidate = price[i] + cutRodAux(n - i, memo, firstPiece, calls);
            if (candidate > best) {
                best = candidate;
                firstPiece[n] = i;
            }
        }
    }
    memo[n] = best;
    return best;
}

int cutRod(int n, std::vector<int>& firstPiece, long& calls) {
    std::vector<int> memo(n + 1, -1);
    firstPiece.assign(n + 1, 0);
    calls = 0;
    return cutRodAux(n, memo, firstPiece, calls);
}

int main() {
    for (int n : {1, 2, 3, 4, 7, 10, 13}) {
        std::vector<int> firstPiece;
        long calls = 0;
        int revenue = cutRod(n, firstPiece, calls);
        std::cout << "length " << n << ": revenue " << revenue << ", pieces:";
        int rest = n;
        while (rest > 0 && firstPiece[rest] > 0) {
            std::cout << ' ' << firstPiece[rest];
            rest -= firstPiece[rest];
        }
        std::cout << "   (" << calls << " calls)\n";
    }
    return 0;
}

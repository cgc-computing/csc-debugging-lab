# CSC310 — Algorithms (C++)

**Language / tooling:** C++17, compiled with `g++ -std=c++17 -Wall` (validated with Apple clang on macOS; any current g++ or clang works). No build system and no external libraries — every activity is a single `.cpp` file with its own `main`. Two activities (Module 1 debug02 and Module 10 debug01) ask you to add `-O2` because they measure running time or tally random outcomes; their READMEs say so. The algorithms follow CLRS (*Introduction to Algorithms*), and the programs use the textbook's names and examples wherever they exist.

## How to use these in the Work Lab

Each module directory holds one to three activities (`debug01`, `debug02`, `debug03`, in increasing difficulty). Open the activity's `README.md`, read the Goal and Expected Behavior, compile and run the program exactly as shown, and compare what you see with what was promised. Then read the source, form a hypothesis about *why* it behaves that way — trace the algorithm by hand on the sample input, check the invariant the textbook proof relies on — test the hypothesis, and fix the program so its output matches the Expected Behavior. The "Think About" questions are there to steer the group discussion; the point of the lab is being able to explain the behavior, not just make the output match. Do not rewrite programs wholesale — the structure is always sound and the bug is always tied to the module's concept (in the one activity where the *algorithm itself* is the problem, the README says you may restructure the function).

## Modules and activities

| Module | Activities | Topics |
|---|---|---|
| `Module00-Course-Introduction-and-Data-Structures-Review` | 1 | debug01: FIFO queue built from two stacks |
| `Module01-Algorithm-Analysis` | 2 | debug01: insertion sort with comparison counting · debug02: timing a distinct-value counter |
| `Module02-Heaps-Priority-Queues-and-Quicksort` | 3 | debug01: max-priority queue on a binary heap · debug02: heapsort · debug03: quicksort with Lomuto partition |
| `Module03-Sorting-Lower-Bounds-and-Order-Statistics` | 2 | debug01: LSD radix sort via counting sort · debug02: randomized select for order statistics |
| `Module04-Hash-Tables` | 3 | debug01: linear-probing hash table · debug02: open-addressing set with removal · debug03: chained hash table for word counts |
| `Module05-Advanced-Trees` | 2 | debug01: left rotation in a BST with parent pointers · debug02: BST deletion with successor |
| `Module06-Disjoint-Sets-and-Introduction-to-Graphs` | 2 | debug01: disjoint-set forest with union by rank · debug02: undirected graph as adjacency lists |
| `Module07-Greedy-Algorithms` | 2 | debug01: activity selection · debug02: fewest-coins change making |
| `Module09-Dynamic-Programming` | 3 | debug01: longest common subsequence table · debug02: 0/1 knapsack with a 1-D table · debug03: rod cutting with memoization |
| `Module10-Randomized-Algorithms` | 2 | debug01: shuffle uniformity tally · debug02: randomized quicksort |
| `Module11-Graph-Algorithms` | 3 | debug01: BFS distances and parents · debug02: DFS topological sort · debug03: directed cycle detection with DFS |
| `Module12-Spanning-Trees` | 2 | debug01: Kruskal's MST with union-find · debug02: Prim's MST with a priority queue |
| `Module13-Shortest-Paths` | 3 | debug01: Dijkstra on a weighted digraph · debug02: Bellman-Ford with negative edges · debug03: Floyd-Warshall all-pairs paths |
| `Module14-String-Algorithms` | 2 | debug01: naive string matcher · debug02: Knuth-Morris-Pratt matcher |
| `Module15-Computational-Geometry` | 2 | debug01: segment intersection by cross products · debug02: convex hull by Graham's scan |

**Total: 34 activities across 15 modules.** Modules 8 (midterm) and 16 (final) have no activities. Module directory names match the `CSC310-Python` tree activity for activity.

Solutions, corrected source files, and instructor notes are in `_solutions/` and are for instructors only.

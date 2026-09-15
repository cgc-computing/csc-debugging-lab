# CSC310 — Data Structures and Algorithms (Python) — Debugging Activities

**Course:** CSC310 Data Structures and Algorithms  
**Language / tooling:** Python 3 (tested with Python 3.9; any Python 3.9+ works, standard library only).
Run programs from a terminal with `python3 program.py`. Algorithms follow CLRS (4th edition); section
references appear in each program's header comment and README.

## How to use these in the CS Work Lab

Pick the module you are currently studying and open one of its `debugXX` folders. Each folder holds a
short, CLRS-faithful program (50–150 lines) with fixed test data and a `README.md` that says what the
program is *supposed* to do, shows the exact expected output, and tells you how to run it. Run the
program, compare its output with the Expected Behavior, then read the code and work out *why* it
behaves as it does before you change anything — the bugs are about the algorithm's invariants,
boundaries and state, not syntax. Activities are numbered by difficulty within a module (`debug01` is
the quickest; `debug03` can take a group most of a session). Work in pairs or small groups, use the
Think About questions to drive the discussion, and be ready to explain the original behavior, not just
the fix.

## Modules

| Module directory | Activities | Topic tags |
|---|---|---|
| `Module00-Course-Introduction-and-Data-Structures-Review` | 1 | debug01: queue built from two stacks |
| `Module01-Algorithm-Analysis` | 2 | debug01: insertion sort with comparison counts · debug02: unique readings from a stream (timing) |
| `Module02-Heaps-Priority-Queues-and-Quicksort` | 3 | debug01: max-heap stored in a list · debug02: heapsort and priority queue · debug03: quicksort with Lomuto partition |
| `Module03-Sorting-Lower-Bounds-and-Order-Statistics` | 2 | debug01: LSD radix sort via counting sort · debug02: randomized select for order statistics |
| `Module04-Hash-Tables` | 3 | debug01: linear-probing hash table · debug02: open-addressing table with deletion · debug03: chained hash map word counts |
| `Module05-Advanced-Trees` | 2 | debug01: BST rotations with parent pointers · debug02: AVL tree insert and delete |
| `Module06-Disjoint-Sets-and-Introduction-to-Graphs` | 2 | debug01: disjoint-set forest for connected components · debug02: undirected graph adjacency lists |
| `Module07-Greedy-Algorithms` | 2 | debug01: activity selection · debug02: greedy coin change |
| `Module09-Dynamic-Programming` | 3 | debug01: LCS table · debug02: 0/1 knapsack with a one-dimensional table · debug03: rod cutting, memoized vs bottom-up |
| `Module10-Randomized-Algorithms` | 2 | debug01: in-place shuffle tally · debug02: reservoir sampling |
| `Module11-Graph-Algorithms` | 3 | debug01: BFS distances on an undirected graph · debug02: DFS topological sort · debug03: strongly connected components |
| `Module12-Spanning-Trees` | 2 | debug01: Kruskal's MST with a disjoint-set forest · debug02: Prim's MST with a heap |
| `Module13-Shortest-Paths` | 3 | debug01: Dijkstra on a weighted digraph · debug02: Bellman-Ford with negative edges · debug03: Floyd-Warshall all-pairs paths |
| `Module14-String-Algorithms` | 2 | debug01: naive string matcher · debug02: KMP prefix function and matcher |
| `Module15-Computational-Geometry` | 2 | debug01: segment intersection by cross products · debug02: Graham scan convex hull |

**Total: 34 activities.** Modules 8 (Midterm) and 16 (Final) have no activities. The module directory
names and per-module counts match the parallel `CSC310-Cpp` tree.

Solutions, instructor notes, and the validation log are in `_solutions/` and are intended for
instructors only.

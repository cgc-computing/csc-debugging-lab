# CSC310-Python — Validation Log

Environment: macOS, Python 3.9 (`python3`), standard library only. GNU `timeout` is not installed on this
machine, so every buggy and corrected program was executed from a Python driver with
`subprocess.run([...], timeout=10)`; the corrected output was compared mechanically against the fenced block in
the README's Expected Behavior, and the buggy output against the fenced block in SOLUTION.md's Observed
Behavior. `__pycache__` directories were removed afterwards. All 34 activities were executed; none is
desk-checked only.

| Module | Activity | Source file | Bug type(s) | Buggy symptom confirmed? | Fixed output confirmed? | Method |
|---|---|---|---|---|---|---|
| Module00-Course-Introduction-and-Data-Structures-Review | debug01 | `two_stack_queue.py` | logic | Yes — jobs leave the queue out of FIFO order (`... 40, 41, 42, 43, 31, 32, 21`), `matches FIFO order: False` | Yes — matches README exactly | executed |
| Module01-Algorithm-Analysis | debug01 | `insertion_sort.py` | boundary | Yes — first element never moves; `sorted correctly: False` on all four lists | Yes — matches README exactly | executed |
| Module01-Algorithm-Analysis | debug02 | `unique_stream.py` | conceptual/design (asymptotic cost of primitive operations) | Yes — `time ratio (n doubled): 4.0x` (≈0.25 s → 1.0 s); exact seconds vary by machine | Yes — same list, 9995/19995 unique, ratio 2.2x this run (README states the ratio is approximate) | executed |
| Module02-Heaps-Priority-Queues-and-Quicksort | debug01 | `max_heap.py` | boundary (index arithmetic) | Yes — extract order not descending (`16, 14, 10, 9, 11, ...`), `descending order? : False` | Yes — matches README exactly | executed |
| Module02-Heaps-Priority-Queues-and-Quicksort | debug02 | `heapsort_pq.py` | logic, boundary | Yes — `heapsort: [16, 14, 7, 10, ...]`, `sorted correctly: False`; priority queue unaffected | Yes — matches README exactly | executed |
| Module02-Heaps-Priority-Queues-and-Quicksort | debug03 | `quicksort.py` | boundary (off-by-one in the returned index) | Yes — two of four lists unsorted; partition trace shows `pivot index 2, A[q] = 3` for pivot 4 | Yes — matches README exactly | executed |
| Module03-Sorting-Lower-Bounds-and-Order-Statistics | debug01 | `radix_sort.py` | logic (stability) | Yes — `sorted: [355, 329, 457, 436, ...]`, `correct: False` | Yes — matches README exactly | executed |
| Module03-Sorting-Lower-Bounds-and-Order-Statistics | debug02 | `randomized_select.py` | boundary (off-by-one in a count) | Yes — nine of ten order statistics `MISMATCH`, wrong median | Yes — matches README exactly | executed |
| Module04-Hash-Tables | debug01 | `linear_probe_table.py` | runtime (index out of range caused by a boundary error in the probe sequence) | Yes — `IndexError: list index out of range` on the tenth insert | Yes — matches README exactly | executed |
| Module04-Hash-Tables | debug02 | `open_addressing_delete.py` | conceptual/design (deletion in open addressing) | Yes — `search 33: None`, `search 44: None` after the deletes | Yes — matches README exactly | executed |
| Module04-Hash-Tables | debug03 | `chained_hash_map.py` | logic, conceptual/design (dictionary invariant: a key appears at most once) | Yes — every word counted once (`count['the'] = 1`), `distinct words : 24` | Yes — matches README exactly | executed |
| Module05-Advanced-Trees | debug01 | `bst_rotations.py` | logic (pointer bookkeeping in a structural operation) | Yes — keys 6 and 7 disappear after the last rotation, `parent links ok : False` | Yes — matches README exactly | executed |
| Module05-Advanced-Trees | debug02 | `avl_tree.py` | logic (order of state updates; stale cached values) | Yes — `stored height : 9` vs `measured height: 5`, `balanced : False` after inserts | Yes — matches README exactly | executed |
| Module06-Disjoint-Sets-and-Introduction-to-Graphs | debug01 | `disjoint_set.py` | logic (operating on set members instead of set representatives) | Yes — `set count : 4` but six groups listed, `same_set(0,5) = False` | Yes — matches README exactly | executed |
| Module06-Disjoint-Sets-and-Introduction-to-Graphs | debug02 | `undirected_graph.py` | conceptual/design (representation of undirected edges), logic | Yes — `has_edge(5, 2) : False`, `sum of degrees : 7`, `symmetric : False` | Yes — matches README exactly | executed |
| Module07-Greedy-Algorithms | debug01 | `activity_selection.py` | conceptual/design (wrong greedy choice) | Yes — `count : 3 (optimum 4)` on both activity sets | Yes — matches README exactly | executed |
| Module07-Greedy-Algorithms | debug02 | `coin_change.py` | conceptual/design (algorithm choice: the greedy-choice property does not hold) | Yes — `amount 6 -> 3 coins: [4, 1, 1]` for {4, 3, 1} (optimum 2) | Yes — matches README exactly | executed |
| Module09-Dynamic-Programming | debug01 | `lcs.py` | boundary (1-based table index vs 0-based string index) | Yes — last row and column of the table all 0, `LCS length = 3` instead of 4 | Yes — matches README exactly | executed |
| Module09-Dynamic-Programming | debug02 | `knapsack_01.py` | logic (iteration order in an in-place DP update) | Yes — `dp value = 300  brute force = 220  match = False` | Yes — matches README exactly | executed |
| Module09-Dynamic-Programming | debug03 | `rod_cutting.py` | conceptual/design (memo consulted after the work is done; exponential time) | Yes — call counts double each step (1024 at n = 10); rod of length 30 never finishes (killed at 10 s, README says it should be instant) | Yes — matches README exactly | executed |
| Module10-Randomized-Algorithms | debug01 | `shuffle_tally.py` | conceptual/design (biased random choice; loop invariant violated) | Yes — permutation counts range 14 723–18 567, `uniform within 3%: False` (fixed seed) | Yes — matches README exactly | executed |
| Module10-Randomized-Algorithms | debug02 | `reservoir_sampling.py` | boundary (off-by-one in the range of a random draw), conceptual/design | Yes — `item 1: 0 (0.00%)` for k = 1; deviation 26.5% for k = 3 (fixed seed) | Yes — matches README exactly | executed |
| Module11-Graph-Algorithms | debug01 | `bfs_distances.py` | conceptual/design (vertex state changed at the wrong moment: on dequeue instead of on discovery) | Yes — `times enqueued: 11`, `u: dist 4`, `y: dist 5` | Yes — matches README exactly | executed |
| Module11-Graph-Algorithms | debug02 | `topological_sort.py` | conceptual/design (vertex recorded at discovery instead of at finish), logic (finish list never reversed) | Yes — three edges out of order, `valid topological order: False` | Yes — matches README exactly | executed |
| Module11-Graph-Algorithms | debug03 | `strongly_connected.py` | conceptual/design (second pass searches the wrong graph and takes vertices in the wrong order) | Yes — `3 components`, `{c, d, f, g}` merged | Yes — matches README exactly | executed |
| Module12-Spanning-Trees | debug01 | `kruskal.py` | conceptual/design (comparing parent pointers instead of set representatives) | Yes — `tree edges: 11`, `total weight: 62` | Yes — matches README exactly | executed |
| Module12-Spanning-Trees | debug02 | `prim.py` | conceptual/design (key updated with a path weight instead of an edge weight) | Yes — `b-c (12)`, `total weight: 98` | Yes — matches README exactly | executed |
| Module13-Shortest-Paths | debug01 | `dijkstra.py` | conceptual/design (distance estimates not maintained; outdated heap entries treated as fresh) | Yes — `t: dist 10`, `x: dist 14`, 8 removals for 5 vertices | Yes — matches README exactly | executed |
| Module13-Shortest-Paths | debug02 | `bellman_ford.py` | boundary (one relaxation pass too few, so the negative-cycle check fires on an unfinished graph) | Yes — `chain: negative-weight cycle reachable from the source` | Yes — matches README exactly | executed |
| Module13-Shortest-Paths | debug03 | `floyd_warshall.py` | conceptual/design (dynamic-programming stages computed in the wrong order: `k` innermost) | Yes — row 1 of D is `0 3 8 2 -4`; paths 1→2 and 1→3 reconstructed as direct edges | Yes — matches README exactly | executed |
| Module14-String-Algorithms | debug01 | `naive_match.py` | boundary (exclusive `range` bound used for an inclusive pseudocode bound) | Yes — `"world" in "hello world": no match`, `"abc" in "abc": no match` | Yes — matches README exactly | executed |
| Module14-String-Algorithms | debug02 | `kmp.py` | boundary (fallback indexes `pi` by length instead of by position), logic | Yes — `pi = 0 0 1 2 2` for `ababb`, false match `shift 3 ("bbabb")`, shift 6 missed for `abacabab` | Yes — matches README exactly | executed |
| Module15-Computational-Geometry | debug01 | `segment_intersection.py` | boundary (strict inequalities in the collinear "between" test) | Yes — T junction, shared endpoint and collinear overlap all reported `disjoint` | Yes — matches README exactly | executed |
| Module15-Computational-Geometry | debug02 | `convex_hull.py` | boundary (collinear case: the pop condition ignores `cross == 0`), logic | Yes — `7 hull vertices` for both the square and the triangle | Yes — matches README exactly | executed |

**Total: 34 activities, 34 executed, 0 UNCHECKED.**

## Notes and items the lead may want to double-check

- `Module01-Algorithm-Analysis/debug02` (`unique_stream.py`) is a timing activity. Unique counts and the ≈4x
  (buggy) vs ≈2x (fixed) ratios reproduce; absolute seconds differ per run and per machine, and the README
  says so. The buggy ratio printed 4.0x on every run here.
- `Module09-Dynamic-Programming/debug03` (`rod_cutting.py`) is the tree's single deliberate hang (exponential
  recursion at n = 30). Under `subprocess` with a pipe the buffered table is lost when the process is killed;
  in a terminal the table appears and the last line never does, exactly as SOLUTION.md describes. The README's
  Expected Behavior states the last line should appear essentially instantly, so the hang is recognizable.
- `Module14-String-Algorithms/debug02` (`kmp.py`): the shipped patterns were chosen so the buggy prefix
  function terminates with wrong values. A pattern beginning with two equal characters (e.g. `aab`) makes the
  buggy version loop forever; this is noted in the Instructor Notes, not in the README.
- `Module10-Randomized-Algorithms` uses fixed seeds, so the tallies are reproducible on CPython 3.9+; they
  would change on an implementation with a different `random` generator.
- Line counts: `coin_change.py` (38), `knapsack_01.py` (46) and `naive_match.py` (49) are a little under the
  50-line guideline for CSC310; all others are 50–143 lines.
- Error-type mix for the tree (primary type per activity): runtime 1, logic/boundary 19, conceptual/design 14,
  compile/syntax 0. Runtime is below the A7 target because Python algorithm programs rarely crash; the hang and
  the `IndexError` are the only non-wrong-output symptoms.
- CLRS citations throughout READMEs, SOLUTIONs and source docstrings use 4th-edition numbering (Ch 14 DP, 15
  greedy, 19 disjoint sets, 20–23 graph algorithms, 32 strings, 33 geometry) with section-level wording; no
  figure/lemma/theorem numbers are cited.

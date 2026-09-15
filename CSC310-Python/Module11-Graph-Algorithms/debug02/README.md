# Topological Sort by Depth-First Search

**Course:** CSC310 &nbsp;|&nbsp; **Module 11:** Graph Algorithms &nbsp;|&nbsp; **Activity:** debug02
**Language:** Python 3

## Goal

`topological_sort.py` orders the vertices of a directed acyclic graph so that every edge `u -> v` has
`u` before `v`, using the depth-first-search method of CLRS Section 20.4. The example is the
textbook's getting-dressed graph (an edge means "put this on first"). After producing an order, `main`
checks every edge and lists any that point backwards.

## Expected Behavior

```
order:
  1. watch
  2. socks
  3. shirt
  4. tie
  5. undershorts
  6. pants
  7. shoes
  8. belt
  9. jacket
edges out of order: none
valid topological order: True
```

Many valid orders exist; this is the one produced by DFS when it visits vertices in the order they
appear in the dictionary and follows each adjacency list in the order given. Your corrected program
should print exactly this order.

## How to Run

```bash
python3 topological_sort.py
```

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the
depth-first-search approach; do not switch to an in-degree (queue-based) method.

## Think About

- A vertex's life in DFS has two moments: when the search first reaches it and when the search is
  completely done with it. At which of those two moments is it guaranteed that *every* vertex reachable
  from it has already been handled? What does that imply about where the vertex belongs in the order?
- Three edges are reported backwards: `shirt -> belt`, `tie -> jacket`, `socks -> shoes`. In the current
  output `belt` comes before `shirt`. Which vertex did DFS reach `belt` from, and why does that path
  tell you nothing about `shirt`?
- CLRS's TOPOLOGICAL-SORT builds its answer in a linked list. Read that pseudocode carefully: at which
  end of the list does each vertex go, and does this program's list end up in the same order?
- Suppose someone reorders the dictionary in `main`. Could the printed order change? Could the
  checker's verdict change? Why is one of those acceptable and the other not?

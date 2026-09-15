"""Activity selection (CLRS Section 15.1).

Given activities with start and finish times, choose a maximum-size set
of mutually compatible activities (no two overlap in time).  The greedy
procedure sorts the activities and then repeatedly takes the first one
that is compatible with the last one chosen.
"""


def select_activities(activities):
    """activities: list of (name, start, finish).  Returns chosen names."""
    ordered = sorted(activities, key=lambda a: a[1])
    chosen = [ordered[0]]
    last_finish = ordered[0][2]
    for act in ordered[1:]:
        name, start, finish = act
        if start >= last_finish:
            chosen.append(act)
            last_finish = finish
    return [a[0] for a in chosen]


def brute_force_best(activities):
    """Largest compatible subset by trying all subsets (for checking only)."""
    n = len(activities)
    best = 0
    for mask in range(1 << n):
        subset = [activities[i] for i in range(n) if mask >> i & 1]
        subset.sort(key=lambda a: a[1])
        ok = all(subset[i][2] <= subset[i + 1][1] for i in range(len(subset) - 1))
        if ok:
            best = max(best, len(subset))
    return best


def report(title, activities):
    chosen = select_activities(activities)
    print(f"{title}")
    print(f"  chosen  : {chosen}")
    print(f"  count   : {len(chosen)}   (optimum {brute_force_best(activities)})")


def main():
    # The eleven activities of the CLRS Section 15.1 example
    starts = [1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12]
    finishes = [4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16]
    clrs = [(f"a{i + 1}", s, f) for i, (s, f) in enumerate(zip(starts, finishes))]
    report("CLRS activity set", clrs)

    lab = [("setup", 0, 3), ("intro", 1, 2), ("lecture", 2, 5), ("demo", 4, 6),
           ("quiz", 5, 7), ("review", 6, 9), ("wrapup", 8, 10), ("long", 0, 9)]
    report("Lab schedule", lab)


if __name__ == "__main__":
    main()

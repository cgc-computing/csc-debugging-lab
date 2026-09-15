"""Line-segment intersection test (CLRS Section 33.1).

segments_intersect(p1, p2, p3, p4) decides whether segment p1p2 and
segment p3p4 share at least one point, using only cross products: no
division and no floating point.  Two segments intersect if they cross
properly, if an endpoint of one lies on the other, if they share an
endpoint, or if they overlap along the same line.  The main block tests
eight configurations.
"""


def direction(pi, pj, pk):
    """Cross product (pk - pi) x (pj - pi): the turn direction at pi."""
    return (pk[0] - pi[0]) * (pj[1] - pi[1]) - (pj[0] - pi[0]) * (pk[1] - pi[1])


def on_segment(pi, pj, pk):
    """Given that pk is collinear with pi and pj, is pk between them?"""
    return (min(pi[0], pj[0]) < pk[0] < max(pi[0], pj[0]) and
            min(pi[1], pj[1]) < pk[1] < max(pi[1], pj[1]))


def segments_intersect(p1, p2, p3, p4):
    d1 = direction(p3, p4, p1)
    d2 = direction(p3, p4, p2)
    d3 = direction(p1, p2, p3)
    d4 = direction(p1, p2, p4)
    if ((d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0)) and \
       ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 > 0)):
        return True
    if d1 == 0 and on_segment(p3, p4, p1):
        return True
    if d2 == 0 and on_segment(p3, p4, p2):
        return True
    if d3 == 0 and on_segment(p1, p2, p3):
        return True
    if d4 == 0 and on_segment(p1, p2, p4):
        return True
    return False


def main():
    cases = [
        ("crossing", (0, 0), (4, 4), (0, 4), (4, 0)),
        ("T junction", (0, 0), (4, 0), (2, 0), (2, 3)),
        ("shared endpoint", (0, 0), (3, 3), (3, 3), (6, 0)),
        ("collinear overlap", (0, 0), (4, 0), (2, 0), (6, 0)),
        ("diagonal overlap", (0, 0), (3, 3), (2, 2), (5, 5)),
        ("collinear apart", (0, 0), (2, 0), (3, 0), (5, 0)),
        ("parallel", (0, 0), (4, 0), (0, 1), (4, 1)),
        ("near miss", (0, 0), (4, 4), (5, 0), (6, 3)),
    ]
    for name, p1, p2, p3, p4 in cases:
        verdict = "intersect" if segments_intersect(p1, p2, p3, p4) else "disjoint"
        print(f"{name:<18}: {p1}-{p2} and {p3}-{p4} -> {verdict}")


if __name__ == "__main__":
    main()

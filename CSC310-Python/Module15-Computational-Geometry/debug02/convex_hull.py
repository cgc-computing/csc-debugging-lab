"""Convex hull by Graham's scan (CLRS Section 33.3).

convex_hull(points) picks the lowest point (leftmost on ties) as the
anchor, sorts the remaining points by polar angle around the anchor
(nearer points first when angles tie), and then sweeps through them with
a stack, popping whenever the top of the stack would fail to make a left
turn.  The result is the hull's corner points in counter-clockwise order
starting at the anchor; a point that lies on a hull edge but is not a
corner is not part of the answer.  The main block runs three point sets
and prints twice the polygon area as a check.
"""

import math


def cross(o, a, b):
    """Cross product (a - o) x (b - o): positive for a left turn o->a->b."""
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])


def convex_hull(points):
    anchor = min(points, key=lambda p: (p[1], p[0]))
    rest = [p for p in points if p != anchor]
    rest.sort(key=lambda p: (math.atan2(p[1] - anchor[1], p[0] - anchor[0]),
                             (p[0] - anchor[0]) ** 2 + (p[1] - anchor[1]) ** 2))
    hull = [anchor]
    for p in rest:
        while len(hull) > 1 and cross(hull[-2], hull[-1], p) < 0:
            hull.pop()
        hull.append(p)
    return hull


def twice_area(polygon):
    total = 0
    for i in range(len(polygon)):
        x1, y1 = polygon[i]
        x2, y2 = polygon[(i + 1) % len(polygon)]
        total += x1 * y2 - x2 * y1
    return total


def report(title, points):
    hull = convex_hull(points)
    listing = " ".join(f"({x},{y})" for x, y in hull)
    print(f"{title}: {len(hull)} hull vertices: {listing}   "
          f"twice the area = {twice_area(hull)}")


def main():
    square = [(0, 0), (4, 0), (4, 4), (0, 4), (2, 0), (4, 2), (2, 4), (0, 2),
              (1, 1), (2, 2), (3, 1)]
    triangle = [(0, 0), (6, 0), (3, 3), (2, 0), (4, 0), (1, 1), (2, 2),
                (5, 1), (4, 2), (3, 1)]
    pentagon = [(1, 0), (4, 1), (5, 4), (2, 6), (0, 3), (2, 2), (3, 3),
                (1, 4), (3, 1)]
    report("square with edge points", square)
    report("triangle with edge points", triangle)
    report("pentagon", pentagon)


if __name__ == "__main__":
    main()

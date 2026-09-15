// convex_hull.cpp
// Convex hull by Graham's scan (CLRS 33.3). The anchor is the lowest point
// (leftmost on ties); the remaining points are sorted by polar angle around
// the anchor and scanned with a stack, popping whenever the top of the stack
// would not make a left turn. The hull is reported counter-clockwise from
// the anchor and contains only its corner points.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Point {
    long x, y;
};

// Cross product (b - a) x (c - a): > 0 for a left turn a->b->c, 0 if collinear.
long cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

long distSquared(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

std::vector<Point> convexHull(std::vector<Point> pts) {
    if (pts.size() < 3) {
        return pts;
    }
    // Anchor: minimum y, then minimum x.
    auto anchorIt = std::min_element(pts.begin(), pts.end(), [](Point a, Point b) {
        return a.y < b.y || (a.y == b.y && a.x < b.x);
    });
    std::swap(*anchorIt, pts[0]);
    const Point anchor = pts[0];

    // Sort by polar angle around the anchor.
    std::sort(pts.begin() + 1, pts.end(), [&](Point a, Point b) {
        long c = cross(anchor, a, b);
        if (c != 0) return c > 0;
        return distSquared(anchor, a) > distSquared(anchor, b);
    });

    std::vector<Point> hull;
    for (const Point& p : pts) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), p) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }
    return hull;
}

// Twice the signed area (shoelace formula); positive for counter-clockwise.
long twiceArea(const std::vector<Point>& poly) {
    long sum = 0;
    for (std::size_t i = 0; i < poly.size(); ++i) {
        const Point& a = poly[i];
        const Point& b = poly[(i + 1) % poly.size()];
        sum += a.x * b.y - b.x * a.y;
    }
    return sum;
}

void report(const std::string& label, const std::vector<Point>& pts) {
    std::vector<Point> hull = convexHull(pts);
    std::cout << label << ": " << hull.size() << " hull vertices:";
    for (const Point& p : hull) {
        std::cout << " (" << p.x << "," << p.y << ")";
    }
    std::cout << "   twice the area = " << twiceArea(hull) << '\n';
}

int main() {
    report("square with edge points",
           {{2, 2}, {4, 0}, {0, 2}, {1, 1}, {4, 4}, {2, 0}, {3, 1}, {0, 4}, {4, 2}, {2, 4}, {0, 0}, {1, 3}});
    report("triangle with edge points",
           {{3, 3}, {1, 1}, {6, 0}, {3, 0}, {2, 2}, {0, 0}, {4, 2}, {2, 1}});
    report("pentagon", {{1, 0}, {4, 1}, {5, 4}, {2, 6}, {0, 3}, {2, 3}, {3, 2}});
    return 0;
}

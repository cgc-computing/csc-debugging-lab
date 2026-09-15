// segment_intersection.cpp
// Decides whether two line segments intersect (CLRS 33.1) using cross
// products only, with no division and no floating point. Two segments
// intersect if they share at least one point, including touching at an
// endpoint or overlapping along a line.
#include <algorithm>
#include <iostream>
#include <string>

struct Point {
    long x, y;
};

struct Segment {
    Point p, q;
};

// Sign of the cross product (b - a) x (c - a): positive when a->b->c turns
// left (counter-clockwise), negative when it turns right, zero when collinear.
long direction(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Given that c is collinear with a and b, is c on the segment a-b?
bool onSegment(Point a, Point b, Point c) {
    return std::min(a.x, b.x) <= c.x && c.x <= std::max(a.x, b.x) &&
           std::min(a.y, b.y) <= c.y && c.y <= std::max(a.y, b.y);
}

bool intersects(const Segment& s1, const Segment& s2) {
    long d1 = direction(s2.p, s2.q, s1.p);
    long d2 = direction(s2.p, s2.q, s1.q);
    long d3 = direction(s1.p, s1.q, s2.p);
    long d4 = direction(s1.p, s1.q, s2.q);
    bool s1Straddles = (d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0);
    bool s2Straddles = (d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0);
    if (s1Straddles && s2Straddles) {
        return true;
    }
    // Boundary cases: an endpoint of one segment lies on the line of the other.
    if (d1 == 0 && onSegment(s2.p, s2.q, s1.p)) return true;
    if (d2 == 0 && onSegment(s2.p, s2.q, s1.q)) return true;
    if (d3 == 0 && onSegment(s1.p, s1.q, s2.p)) return true;
    if (d4 == 0 && onSegment(s1.p, s1.q, s2.q)) return true;
    return false;
}

void report(const std::string& label, Segment a, Segment b) {
    std::cout << label << ": (" << a.p.x << "," << a.p.y << ")-(" << a.q.x << "," << a.q.y
              << ") and (" << b.p.x << "," << b.p.y << ")-(" << b.q.x << "," << b.q.y << ") -> "
              << (intersects(a, b) ? "intersect" : "disjoint") << '\n';
}

int main() {
    report("crossing        ", {{0, 0}, {4, 4}}, {{0, 4}, {4, 0}});
    report("T junction      ", {{0, 0}, {4, 0}}, {{2, 0}, {2, 3}});
    report("shared endpoint ", {{0, 0}, {3, 3}}, {{3, 3}, {6, 0}});
    report("collinear overlap", {{0, 0}, {4, 0}}, {{2, 0}, {6, 0}});
    report("collinear apart ", {{0, 0}, {2, 0}}, {{3, 0}, {5, 0}});
    report("parallel        ", {{0, 0}, {4, 0}}, {{0, 1}, {4, 1}});
    report("near miss       ", {{0, 0}, {4, 4}}, {{5, 0}, {6, 3}});
    return 0;
}

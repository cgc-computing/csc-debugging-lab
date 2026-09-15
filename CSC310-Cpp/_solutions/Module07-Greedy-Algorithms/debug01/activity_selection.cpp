// activity_selection.cpp
// Greedy activity selection (CLRS 15.1). Each activity has a start time and a
// finish time; two activities are compatible if their half-open intervals
// [start, finish) do not overlap. The goal is a maximum-size set of mutually
// compatible activities.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Activity {
    std::string name;
    int start;
    int finish;
};

// Returns a maximum set of compatible activities, in the order chosen.
std::vector<Activity> selectActivities(std::vector<Activity> acts) {
    std::sort(acts.begin(), acts.end(), [](const Activity& a, const Activity& b) {
        return a.finish < b.finish;
    });

    std::vector<Activity> chosen;
    if (acts.empty()) {
        return chosen;
    }
    chosen.push_back(acts[0]);
    int lastFinish = acts[0].finish;
    for (std::size_t i = 1; i < acts.size(); ++i) {
        if (acts[i].start >= lastFinish) {
            chosen.push_back(acts[i]);
            lastFinish = acts[i].finish;
        }
    }
    return chosen;
}

void report(const std::string& label, const std::vector<Activity>& acts) {
    std::vector<Activity> chosen = selectActivities(acts);
    std::cout << label << ": " << chosen.size() << " activities:";
    for (const Activity& a : chosen) {
        std::cout << ' ' << a.name << "[" << a.start << "," << a.finish << ")";
    }
    std::cout << '\n';
}

int main() {
    std::vector<Activity> clrs = {
        {"a1", 1, 4},  {"a2", 3, 5},  {"a3", 0, 6},   {"a4", 5, 7},
        {"a5", 3, 9},  {"a6", 5, 9},  {"a7", 6, 10},  {"a8", 8, 11},
        {"a9", 8, 12}, {"a10", 2, 14}, {"a11", 12, 16}};
    report("textbook set", clrs);

    std::vector<Activity> room = {
        {"lecture", 9, 10}, {"seminar", 8, 13}, {"lab", 10, 11},
        {"office-hours", 11, 12}, {"club", 12, 13}};
    report("room schedule", room);

    std::vector<Activity> nested = {
        {"all-day", 0, 10}, {"short-1", 1, 2}, {"short-2", 2, 3}, {"short-3", 3, 4}};
    report("nested set", nested);
    return 0;
}

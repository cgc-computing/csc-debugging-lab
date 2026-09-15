/*
 * score_list.cpp
 * A small class that owns a heap-allocated array of quiz scores.
 * Demonstrates a class that manages its own memory: the constructor
 * allocates, the destructor releases.
 */
#include <iostream>
#include <string>

class ScoreList {
public:
    explicit ScoreList(int size) : size_(size), scores_(new int[size])
    {
        for (int i = 0; i < size_; i++) {
            scores_[i] = 0;
        }
    }

    ~ScoreList()
    {
        delete[] scores_;
    }

    int size() const { return size_; }
    int get(int i) const { return scores_[i]; }
    void set(int i, int value) { scores_[i] = value; }

    void print(const std::string& label) const
    {
        std::cout << label << ":";
        for (int i = 0; i < size_; i++) {
            std::cout << " " << scores_[i];
        }
        std::cout << std::endl;
    }

private:
    int size_;
    int* scores_;
};

double average(ScoreList list)
{
    int sum = 0;
    for (int i = 0; i < list.size(); i++) {
        sum += list.get(i);
    }
    return static_cast<double>(sum) / list.size();
}

int main()
{
    ScoreList quiz(4);
    quiz.set(0, 88);
    quiz.set(1, 92);
    quiz.set(2, 75);
    quiz.set(3, 100);

    quiz.print("Quiz 1");
    std::cout << "Average: " << average(quiz) << std::endl;

    ScoreList backup = quiz;

    for (int i = 0; i < quiz.size(); i++) {
        int curved = quiz.get(i) + 5;
        quiz.set(i, curved > 100 ? 100 : curved);
    }

    quiz.print("Curved");
    backup.print("Backup");

    return 0;
}

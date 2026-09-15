/*
 * grade_book.c
 * Loads a set of exam scores into a dynamically allocated array and
 * prints the scores, the class average, and how many passed.
 */
#include <stdio.h>
#include <stdlib.h>

#define PASSING 70

void load_scores(int **scores, int *count)
{
    const int raw[] = { 88, 62, 95, 74, 70, 59, 81 };
    int n = (int) (sizeof(raw) / sizeof(raw[0]));

    *scores = malloc(n * sizeof(int));
    if (*scores == NULL) {
        *count = 0;
        return;
    }
    for (int i = 0; i < n; i++) {
        (*scores)[i] = raw[i];
    }
    *count = n;
}

double average(const int *scores, int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += scores[i];
    }
    return count > 0 ? (double) sum / count : 0.0;
}

int count_passing(const int *scores, int count)
{
    int passed = 0;
    for (int i = 0; i < count; i++) {
        if (scores[i] >= PASSING) {
            passed++;
        }
    }
    return passed;
}

int main(void)
{
    int *scores = NULL;
    int count = 0;

    load_scores(&scores, &count);
    printf("Loaded %d scores\n", count);

    printf("Scores:");
    for (int i = 0; i < count; i++) {
        printf(" %d", scores[i]);
    }
    printf("\n");

    printf("Average: %.2f\n", average(scores, count));
    printf("Passing: %d of %d\n", count_passing(scores, count), count);

    free(scores);
    return 0;
}

/*
 * word_copies.c
 * Makes heap-allocated copies of a list of words, records each word's
 * length in a dynamically allocated array, and prints a summary.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copy_string(const char *source)
{
    size_t length = strlen(source);
    char *copy = malloc(length + 1);
    if (copy == NULL) {
        return NULL;
    }
    for (size_t i = 0; i <= length; i++) {
        copy[i] = source[i];
    }
    return copy;
}

int *make_length_table(char *words[], int count)
{
    int *lengths = malloc(count * sizeof(int));
    if (lengths == NULL) {
        return NULL;
    }
    for (int i = 0; i < count; i++) {
        lengths[i] = (int) strlen(words[i]);
    }
    return lengths;
}

int main(void)
{
    const char *originals[] = { "pointer", "malloc", "segmentation", "free", "heap" };
    const int count = 5;
    char *copies[5];

    for (int i = 0; i < count; i++) {
        copies[i] = copy_string(originals[i]);
        if (copies[i] == NULL) {
            printf("Out of memory\n");
            return 1;
        }
    }

    int *lengths = make_length_table(copies, count);
    if (lengths == NULL) {
        printf("Out of memory\n");
        return 1;
    }

    int total = 0;
    for (int i = 0; i < count; i++) {
        printf("%-14s length %2d\n", copies[i], lengths[i]);
        total += lengths[i];
    }
    printf("Total characters: %d\n", total);

    for (int i = 0; i < count; i++) {
        free(copies[i]);
    }
    free(lengths);

    return 0;
}

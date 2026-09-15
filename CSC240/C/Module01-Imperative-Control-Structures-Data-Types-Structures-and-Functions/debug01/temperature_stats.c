/*
 * temperature_stats.c
 * Reads a count followed by that many whole-degree temperature readings
 * and reports the minimum, maximum, and average reading.
 */
#include <stdio.h>

#define MAX_READINGS 100

int find_min(int values[], int count)
{
    int min = values[0];
    for (int i = 1; i < count; i++) {
        if (values[i] < min) {
            min = values[i];
        }
    }
    return min;
}

int find_max(int values[], int count)
{
    int max = values[0];
    for (int i = 1; i < count; i++) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    return max;
}

double find_average(int values[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += values[i];
    }
    return (double) sum / count;
}

int main(void)
{
    int readings[MAX_READINGS];
    int n = 0;

    printf("How many readings? ");
    scanf("%d", n);

    if (n <= 0 || n > MAX_READINGS) {
        printf("Count must be between 1 and %d.\n", MAX_READINGS);
        return 1;
    }

    printf("Enter %d readings: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &readings[i]);
    }

    printf("Count:   %d\n", n);
    printf("Minimum: %d\n", find_min(readings, n));
    printf("Maximum: %d\n", find_max(readings, n));
    printf("Average: %.1f\n", find_average(readings, n));

    return 0;
}

/*
 * sensor_report.c
 * Summarizes a run of sensor readings: the area of the square border
 * around each sensor plot, and the peak reading seen during the run.
 * Small arithmetic helpers are written as macros to avoid call overhead.
 */
#include <stdio.h>

#define SQUARE(x) x * x
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define BORDER_WIDTH 2

static const int readings[] = { 14, 27, 9, 31, 22, 18, 40, 5 };
static const int reading_count = 8;
static int next_index = 0;

/* Returns the next reading in the run, or -1 once the run is exhausted. */
int read_sensor(void)
{
    if (next_index < reading_count) {
        return readings[next_index++];
    }
    return -1;
}

/* Area of a border of BORDER_WIDTH cells around a side x side plot. */
int border_area(int side)
{
    return SQUARE(side + 2 * BORDER_WIDTH) - SQUARE(side);
}

int peak_reading(void)
{
    int peak = 0;
    int consumed = 0;

    while (consumed < reading_count) {
        peak = MAX(read_sensor(), peak);
        consumed++;
    }
    return peak;
}

int main(void)
{
    int sides[] = { 3, 5, 10 };

    printf("Border areas (width %d):\n", BORDER_WIDTH);
    for (int i = 0; i < 3; i++) {
        printf("  side %2d -> %3d cells\n", sides[i], border_area(sides[i]));
    }

    printf("Peak reading: %d\n", peak_reading());
    return 0;
}

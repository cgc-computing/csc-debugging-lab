/*
 * sort_three.c
 * Reads three integers and prints them in ascending order, using a
 * swap helper that exchanges two variables through pointers.
 */
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_three(int *x, int *y, int *z)
{
    if (*x > *y) {
        swap(x, y);
    }
    if (*y > *z) {
        swap(y, z);
    }
    if (*x > *y) {
        swap(x, y);
    }
}

int main(void)
{
    int first, second, third;

    printf("Enter three integers: ");
    if (scanf("%d %d %d", &first, &second, &third) != 3) {
        printf("Please enter exactly three integers.\n");
        return 1;
    }

    printf("Before: %d %d %d\n", first, second, third);
    sort_three(&first, &second, &third);
    printf("After:  %d %d %d\n", first, second, third);

    return 0;
}

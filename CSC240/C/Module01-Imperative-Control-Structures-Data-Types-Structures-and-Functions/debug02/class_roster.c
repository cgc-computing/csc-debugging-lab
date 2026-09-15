/*
 * class_roster.c
 * Keeps a small table of course sections and lets an advisor add
 * students to a section, reporting the seats that remain.
 */
#include <stdio.h>
#include <string.h>

#define SECTION_COUNT 3

struct class_t {
    char code[10];
    int  enrolled;
    int  capacity;
};

void print_section(struct class_t c)
{
    printf("%-8s %2d/%2d enrolled, %2d seats open\n",
           c.code, c.enrolled, c.capacity, c.capacity - c.enrolled);
}

void add_students(struct class_t c, int count)
{
    if (c.enrolled + count > c.capacity) {
        printf("Cannot add %d to %s: only %d seats open\n",
               count, c.code, c.capacity - c.enrolled);
        return;
    }
    c.enrolled += count;
    printf("Added %d to %s\n", count, c.code);
}

int main(void)
{
    struct class_t sections[SECTION_COUNT];

    strcpy(sections[0].code, "CSC110");
    sections[0].enrolled = 18;
    sections[0].capacity = 24;

    strcpy(sections[1].code, "CSC205");
    sections[1].enrolled = 12;
    sections[1].capacity = 20;

    strcpy(sections[2].code, "CSC240");
    sections[2].enrolled = 9;
    sections[2].capacity = 16;

    printf("--- Before ---\n");
    for (int i = 0; i < SECTION_COUNT; i++) {
        print_section(sections[i]);
    }

    printf("\n--- Enrolling ---\n");
    add_students(sections[0], 4);
    add_students(sections[1], 10);
    add_students(sections[2], 5);

    printf("\n--- After ---\n");
    for (int i = 0; i < SECTION_COUNT; i++) {
        print_section(sections[i]);
    }

    return 0;
}

/*
 * expense_report.c
 * Totals a month of expenses by category and prints a summary table.
 * Categories are an enum so they can be used directly as array indexes.
 */
#include <stdio.h>

enum category {
    FOOD,
    RENT,
    TRAVEL,
    UTILITIES,
    OTHER,
    CATEGORY_COUNT
};

typedef struct {
    const char   *description;
    double        amount;
    enum category category;
} expense_t;

static const char *category_names[CATEGORY_COUNT] = {
    "Food", "Other", "Rent", "Travel", "Utilities"
};

void add_expense(double totals[], const expense_t *e)
{
    totals[e->category] += e->amount;
}

void print_report(const double totals[])
{
    double grand_total = 0.0;

    printf("%-10s %10s\n", "Category", "Total");
    for (int c = FOOD; c < OTHER; c++) {
        printf("%-10s %10.2f\n", category_names[c], totals[c]);
        grand_total += totals[c];
    }
    printf("%-10s %10.2f\n", "ALL", grand_total);
}

int main(void)
{
    expense_t month[] = {
        { "groceries",      212.40, FOOD },
        { "apartment",     1150.00, RENT },
        { "bus pass",        64.00, TRAVEL },
        { "electricity",     88.15, UTILITIES },
        { "takeout",         47.60, FOOD },
        { "concert ticket",  55.00, OTHER },
        { "water",           31.20, UTILITIES },
        { "train to campus", 18.50, TRAVEL },
    };
    int expense_count = (int) (sizeof(month) / sizeof(month[0]));
    double totals[CATEGORY_COUNT] = { 0.0 };

    for (int i = 0; i < expense_count; i++) {
        add_expense(totals, &month[i]);
    }

    print_report(totals);
    return 0;
}

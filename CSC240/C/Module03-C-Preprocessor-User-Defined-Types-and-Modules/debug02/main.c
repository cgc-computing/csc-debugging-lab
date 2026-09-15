/*
 * main.c
 * Uses the stack module to reverse a short sequence of numbers and to
 * evaluate a small postfix expression, then reports how many stack
 * operations were performed.
 */
#include <stdio.h>
#include "stack.h"

extern int op_count;

static void reverse_demo(void)
{
    struct stack s;
    int values[] = { 3, 1, 4, 1, 5, 9 };

    stack_init(&s);
    for (int i = 0; i < 6; i++) {
        stack_push(&s, values[i]);
    }

    printf("Reversed:");
    while (!stack_is_empty(&s)) {
        printf(" %d", stack_pop(&s));
    }
    printf("\n");
}

/* Evaluates "7 3 - 4 *" : (7 - 3) * 4 */
static void postfix_demo(void)
{
    struct stack s;
    stack_init(&s);

    stack_push(&s, 7);
    stack_push(&s, 3);
    int b = stack_pop(&s);
    int a = stack_pop(&s);
    stack_push(&s, a - b);

    stack_push(&s, 4);
    b = stack_pop(&s);
    a = stack_pop(&s);
    stack_push(&s, a * b);

    printf("7 3 - 4 * = %d\n", stack_peek(&s));
}

int main(void)
{
    reverse_demo();
    postfix_demo();
    printf("Stack operations performed: %d\n", op_count);
    return 0;
}

/*
 * stack.c
 * Implementation of the integer stack declared in stack.h.
 */
#include "stack.h"

int op_count = 0;    /* pushes and pops performed since program start */

void stack_init(struct stack *s)
{
    s->top = 0;
}

int stack_is_empty(const struct stack *s)
{
    return s->top == 0;
}

int stack_is_full(const struct stack *s)
{
    return s->top == STACK_CAPACITY;
}

int stack_push(struct stack *s, int value)
{
    if (stack_is_full(s)) {
        return 0;
    }
    s->items[s->top] = value;
    s->top++;
    op_count++;
    return 1;
}

int stack_pop(struct stack *s)
{
    s->top--;
    op_count++;
    return s->items[s->top];
}

int stack_peek(const struct stack *s)
{
    return s->items[s->top - 1];
}

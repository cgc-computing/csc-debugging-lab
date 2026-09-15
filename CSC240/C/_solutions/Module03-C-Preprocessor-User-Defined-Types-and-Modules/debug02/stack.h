/*
 * stack.h
 * Interface for a fixed-capacity stack of integers.
 */
#ifndef STACK_H
#define STACK_H

#define STACK_CAPACITY 8

struct stack {
    int items[STACK_CAPACITY];
    int top;            /* number of items currently stored */
};

void stack_init(struct stack *s);
int  stack_is_empty(const struct stack *s);
int  stack_is_full(const struct stack *s);
int  stack_push(struct stack *s, int value);   /* returns 1 on success, 0 if full */
int  stack_pop(struct stack *s);               /* caller must check stack_is_empty first */
int  stack_peek(const struct stack *s);

extern int op_count;   /* pushes and pops performed since program start */

#endif

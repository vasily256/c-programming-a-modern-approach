#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

#define SIZE 10

struct stack_type {
    int contents[SIZE];
    int top;
};

Stack create(void)
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Cannot create a stack");
    return s;
}

void destroy(Stack s)
{
    free(s);
}

static void terminate(char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

bool is_empty(Stack s)
{
    return s->top == 0;
}

bool is_full(Stack s)
{
    return s->top == SIZE;
}

void push(Stack s, int i)
{
    if (is_full(s))
        terminate("Stack is full");

    s->contents[s->top++] = i;
}

int pop(Stack s)
{
    if (is_empty(s))
        terminate("Stack is empty");

    return s->contents[--s->top];
}

void make_empty(Stack s)
{
    s->top = 0;
}

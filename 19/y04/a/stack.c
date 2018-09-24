#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

struct node {
    int data;
    struct node *next;
};

struct stack_type {
    struct node *top;
};

Stack create(void)
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Cannot create a stack");
    s->top = NULL;
    return s;
}

void destroy(Stack s)
{
    make_empty(s);
    free(s);
}

static void terminate(char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

bool is_empty(Stack s)
{
    return s->top == NULL;
}

bool is_full(Stack s)
{
    return false;
}

void push(Stack s, int i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Cannot push value");

    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(Stack s)
{
    if (is_empty(s))
        terminate("Stack is empty");

    int i = s->top->data;
    Stack old_node = s->top;

    s->top = s->top->next;
    free(old_node);
    return i;
}

void make_empty(Stack s)
{
    while (!is_empty(s))
        pop(s);
}

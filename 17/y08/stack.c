#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node *operand = NULL;

void push(int n)
{
    struct node *new_node = malloc(sizeof(*new_node));

    if (new_node == NULL) {
        printf("malloc: allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = n;
    new_node->next = operand;
    operand = new_node;
}

int pop(void)
{
    int n;
    struct node *tmp_ptr;

    if (is_stk_empty())
        stk_underflow();

    n = operand->value;
    tmp_ptr = operand->next;
    free(operand);
    operand = tmp_ptr;

    return n;
}

void stk_clear(void)
{
    struct node *tmp_ptr; 

    while (operand != NULL) {
        tmp_ptr = operand;
        operand = operand->next;
        free(tmp_ptr);
    }
}

bool is_stk_empty(void)
{
    return operand == NULL;
}

void stk_underflow(void)
{
    printf("Not enough operands\n");
    exit(EXIT_SUCCESS);
}

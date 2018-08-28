#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 10

int operand[STACK_SIZE], top = 0;

void push(int n)
{
    if (is_stk_overflow())
        stk_overflow();
    else
        operand[top++] = n;
}

int pop(void)
{
    if (is_stk_empty())
        stk_underflow();
    else
        return operand[--top];
}

void stk_clear(void)
{
    top = 0;
}

bool is_stk_empty(void)
{
    return !top;
}

bool is_stk_overflow(void)
{
    return top == STACK_SIZE ? true : false;
}

void stk_overflow(void)
{
    printf("Expression is too complex\n");
    exit(EXIT_SUCCESS);
}

void stk_underflow(void)
{
    printf("Not enough operands\n");
    exit(EXIT_SUCCESS);
}

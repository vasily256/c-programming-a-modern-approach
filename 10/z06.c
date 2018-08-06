#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

int operand[STACK_SIZE], top = 0;

void push(int ch);
int pop(void);
bool is_stk_empty(void);
bool is_stk_overflow(void);
void stk_overflow(void);
void stk_underflow(void);
void stk_clear(void);

int main(void)
{ 
    char ch;
    bool is_end;
    int a, b;

    for (;;) { 
        printf("Enter an RPN expression: ");
        is_end = false;
        while (is_end == false) {
            scanf(" %c", &ch);
            switch (ch) {
                case '0': case '1': case '2': case '3': case '4': 
                case '5': case '6': case '7': case '8': case '9': 
                    push(ch - '0');
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    b = pop();
                    a = pop();
                    push(a / b);
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    b = pop();
                    a = pop();
                    push(a - b);
                    break;
                case '=':
                    is_end = true;
                    break;
                default:
                    return 0;
            }
        }

        stk_clear();
        printf("Value of expression: %d\n", operand[top]);
    }
}

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

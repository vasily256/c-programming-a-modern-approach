#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10
#define EXP_LEN 30

int operand[STACK_SIZE], top = 0;

int evaluate_RPN_expression(const char *expression);
void push(int n);
int pop(void);
bool is_stk_empty(void);
bool is_stk_overflow(void);
void stk_overflow(void);
void stk_underflow(void);
void stk_clear(void);
int read_line_m(char str[], int n);

int main(void)
{
    char expression[EXP_LEN + 1] = "";

    for (;;) {
        printf("Enter an RPN expression: ");
        read_line_m(expression, EXP_LEN);

        printf("Value of expression: %d\n",
                    evaluate_RPN_expression(expression));
    }
}

int evaluate_RPN_expression(const char *expression)
{ 
    int a, b;

    for (bool is_end = false; is_end == false; expression++) {
        switch (*expression) {
            case '0': case '1': case '2': case '3': case '4': 
            case '5': case '6': case '7': case '8': case '9': 
                push(*expression - '0');
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
                exit(EXIT_SUCCESS);
        }
    } 
    stk_clear();
    return operand[top];
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

int read_line_m(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (ch != ' ' && i < n)
            str[i++] = ch;
    str[i] = '\0';

    return i;
}

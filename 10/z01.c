#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

char ch_stk[STACK_SIZE];
int top = 0;

void push(char ch);
char pop(void);
bool is_stk_empty(void);
bool is_stk_overflow(void);
void stk_overflow(void);
void matched(void);
void not_matched(void);


int main(void)
{
    printf("Enter parentheses and/or braces: ");

    char ch;
    while ((ch = getchar()) != '\n') {
        switch(ch) {
            case '(': case '{':
                push(ch);
                break;
            case ')':
                if (pop() != '(')
                    not_matched();
                break;
            case '}':
                if (pop() != '{')
                    not_matched();
                break;
            default:
                break; //skip other characters
        }
    }

    if (is_stk_empty())
        matched();
    else
        not_matched();
}

void push(char ch)
{
    if (is_stk_overflow())
        stk_overflow();
    else
        ch_stk[top++] = ch;
}

char pop(void)
{
    if (is_stk_empty())
        not_matched();
    else
        return ch_stk[--top];
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
    printf("Stack overflow\n");
    exit(EXIT_SUCCESS);
}

void matched(void)
{
    printf("Matched\n");
    exit(EXIT_SUCCESS);
}

void not_matched(void)
{
    printf("Not matched\n");
    exit(EXIT_SUCCESS);
}

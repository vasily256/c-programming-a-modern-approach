#include <stdbool.h>
#include <stdio.h>

#define N 5

int stack[N], *top_ptr = stack;

void push(int value);
int pop(void);
void make_empty(void);
bool is_full(void);
bool is_empty(void);
void stack_overflow(void);
void stack_underflow(void);
void stack_print(void);
void help(void);

int main(void)
{
    char command;
    int value;

    for(;;) {
        printf("Enter a command ('h' - help): ");
        scanf(" %c", &command);
        switch(command) {
            case '+':
                scanf("%d", &value);
                push(value);
                break;
            case '-':
                if (is_empty())
                    stack_underflow();
                else
                    printf("%d\n", pop()); 
                break;
            case 'e':
                make_empty();
                stack_underflow();
                break;
            case 'p':
                stack_print();
                break;
            case 'h':
                help();
                break;
            case 'q':
                return 0;
        }
    }
}
void push(int value)
{
    if (is_full())
        stack_overflow();
    else
        *top_ptr++ = value;
}

int pop(void)
{
    return *--top_ptr;
}

void make_empty(void)
{
    top_ptr = stack;
}

bool is_full(void)
{
    return top_ptr == stack + N;
}

bool is_empty(void)
{
    return top_ptr == stack;
}

void stack_overflow(void)
{
    printf("Stack overflow\n");
}

void stack_underflow(void)
{
    int i = printf("Stack underflow\n");
}

void stack_print(void)
{
    if (is_empty()) {
        stack_underflow();
    } else {
        for(int *p = top_ptr - 1; p >= stack; p--)
            printf("%d ", *p);
        printf("\n");
    }
}

void help(void)
{
    printf("'+ [value]' - push a value\n'-' - pop a value\n"
            "'e' - make the stack empty\n'p' - print the stack\n"
            "'q' - quite\n\n");
}

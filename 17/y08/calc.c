#include <stdbool.h>
#include <stdio.h>
#include "stack.h"

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

        printf("Value of expression: %d\n",
                operand != NULL ? operand->value : 0);
        stk_clear();
    }
}

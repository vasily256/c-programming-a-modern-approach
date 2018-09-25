#include <stdbool.h>
#include <stdio.h>
#include "stackADT.h"

int main(void)
{ 
    char ch;
    bool is_end;
    Item a, b;
    Stack s = create();

    for (;;) { 
        printf("Enter an RPN expression: ");
        is_end = false;
        while (is_end == false) {
            scanf(" %c", &ch);
            switch (ch) {
                case '0': case '1': case '2': case '3': case '4': 
                case '5': case '6': case '7': case '8': case '9': 
                    push(s, ch - '0');
                    break;
                case '*':
                    push(s, pop(s) * pop(s));
                    break;
                case '/':
                    b = pop(s);
                    a = pop(s);
                    push(s, a / b);
                    break;
                case '+':
                    push(s, pop(s) + pop(s));
                    break;
                case '-':
                    b = pop(s);
                    a = pop(s);
                    push(s, a - b);
                    break;
                case '=':
                    is_end = true;
                    break;
                default:
                    return 0;
            }
        }

        printf("Value of expression: %d\n",
                !is_empty(s) ? pop(s) : 0);

        destroy(s);

        return 0;
    }
}

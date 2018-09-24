#include <stdio.h>
#include "stackADT.h"

int main(void)
{
    Item ch;
    Stack s = create();

    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n') {
        switch(ch) {
            case '(': case '{':
                push(s, ch);
                break;
            case ')':
                if (is_empty(s) || pop(s) != '(') {
                    printf("Not matched\n");
                    return 0;
                }
                break;
            case '}':
                if (is_empty(s) || pop(s) != '{') {
                    printf("Not matched\n");
                    return 0;
                }
                break;
            default:
                break; //skip other characters
        }
    }
    if (is_empty(s))
        printf("Matched\n");
    else
        printf("Not matched\n");

    destroy(s);

    return 0;
}

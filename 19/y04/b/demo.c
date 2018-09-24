#include <stdio.h>
#include <stdbool.h>
#include "stack.h" 


int main(void)
{
    int cmd;
    int i;
    Stack s = create();

    for (;;) {
        printf("Enter a command (1 - push, 2 - pop, 0 - return): ");
        scanf(" %d", &cmd);
        switch (cmd) {
            case 0:
                return 0;
            case 1:
                printf("Enter a value to be pushed: ");
                scanf("%d", &i);
                push(s, i);
                break;
            case 2:
                printf("Popped value: %d\n", pop(s));
                break;
            default:
                break;
        }
    }

    destroy(s); 

    return 0;
}

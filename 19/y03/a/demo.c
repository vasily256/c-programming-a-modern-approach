#include <stdio.h>
#include <stdbool.h>
#include "queue.h" 


int main(void)
{
    int cmd;
    Item i;
    Queue q = create();

    for (;;) {
        printf("Enter a command: ");
        scanf(" %d", &cmd);
        switch (cmd) {
            case 0:
                return 0;
            case 1:
                printf("Enter a last value to be inserted: ");
                scanf("%d", &i);
                insert_last(q, i);
                break;
            case 2:
                printf("Removed first value: %d\n", remove_first(q));
                break;
            case 3:
                printf("First value: %d\n", return_first(q));
                break;
            case 4:
                printf("Last value: %d\n", return_last(q));
                break;
            default:
                break;
        }
    }

    destroy(q); 

    return 0;
}

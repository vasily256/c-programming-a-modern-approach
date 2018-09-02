#include <stdio.h>

int main(void)
{
    int x = 0, y = 0, command;
    enum {NORTH, SOUTH, EAST, WEST} direction;

    for (;;) { 
        printf("Current coordinates: (%d,%d)\n", x, y);
        printf("Choose direction (0 - north, 1 - south, 2 - east, 3 - west):\n");
        scanf("%1d", &direction);
        switch (direction) {
            case NORTH: y++; break;
            case SOUTH: y--; break;
            case EAST:  x++; break;
            case WEST:  x--; break;
            default:         return 0;
        }
    }
}

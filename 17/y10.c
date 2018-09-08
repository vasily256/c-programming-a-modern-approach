#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
};

void print_part_orig(struct part p)
{ 
    printf("Part number: %d\n", p.number);
    printf("Part name: %s\n", p.name);
    printf("Quantity on hand: %d\n", p.on_hand);
}

void print_part_mod(struct part *p)
{ 
    printf("Part number: %d\n", p->number);
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
}

int main(void)
{
    struct part p = {101, "Polyethylene", 5000};

    print_part_orig(p);
    print_part_mod(&p);

    return 0;
}

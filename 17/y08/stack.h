#ifndef STACK_H
#define STACK_H

//extern int operand[], top;
extern struct node {
    int value;
    struct node *next;
} *operand;

void push(int ch);
int pop(void);
bool is_stk_empty(void);
void stk_clear(void);
void stk_underflow(void);

#endif

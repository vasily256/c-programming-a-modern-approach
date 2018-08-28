#ifndef STACK_H
#define STACK_H

extern int operand[], top;

void push(int ch);
int pop(void);
bool is_stk_empty(void);
bool is_stk_overflow(void);
void stk_overflow(void);
void stk_underflow(void);
void stk_clear(void);

#endif

#ifndef STACK_H
#define STACK_H

#define STACK_TYPE int

void push(STACK_TYPE value);
void pop(void);
STACK_TYPE top(void);
int is_stack_empty(void);
int is_stack_full(void);
void create_stack(size_t size);
void destroy_stack(void);

#endif
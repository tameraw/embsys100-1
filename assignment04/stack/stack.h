#ifndef __STACK_H__
#define __STACK_H__

#ifndef NULL
#define NULL 0x00
#endif

#define MAX_STACK_SIZE 2

void stack_ctor(void);
int stack_push(int data);
int stack_pop(int *data);
int stack_size(void);
int stack_empty(void);
int stack_full(void);

#endif

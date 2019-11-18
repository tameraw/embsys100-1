#include "stack.h"

int intStack[MAX_STACK_SIZE];
int *pIntStack; // Pointer to intStack

void stack_ctor(void) {
    // ctor for intStack sets all elmnts to 0
    pIntStack = NULL;

    for (int i = 0; i < MAX_STACK_SIZE; ++i) {
        intStack[i] = 0;
    }
}

int stack_push(int elmnt) { // LIFO stack
    // push elmnt to stack, returns 0 for success and 1 for failure
    if (stack_full()) {
        return 1; // full -> true there is an error
    } else if (pIntStack == NULL) {
        pIntStack = &intStack[0];
    }
    *pIntStack = elmnt;
    ++pIntStack;
    return 0;
}

int stack_pop(int *elmnt) { // LIFO stack
    if (pIntStack == NULL) {
        return 1; // empty -> true there is an error
    }

    --pIntStack;
    *elmnt = *pIntStack;
    if (pIntStack == &intStack[0]) {
        pIntStack = NULL;
    }
    return 0;
}

int stack_size(void) { // LIFO stack
    return pIntStack == NULL ? 0 : pIntStack - &intStack[0];
}

int stack_empty(void) { // LIFO stack
    return stack_size() == 0 ? 1 : 0;
}

int stack_full(void) { // LIFO stack
    return stack_size() == MAX_STACK_SIZE ? 1 : 0;
}

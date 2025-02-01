#include "stack.h"
#include <stdio.h>

/* Single global and static stack */
static Stack stack;

/* Initialize correctly the stack*/
void stack_init(void) { stack.size = 0; }

/* Returns the current size of the stack. */
int stack_size(void) { return stack.size; }

/* Returns 1 if the stack is empty, returns 0 otherwise. */
int stack_is_empty(void) {
    if (stack.size == 0) {
        return 1;
    }
    return 0;
}

/* Returns the element at the top of the stack. */
int stack_top(void) {
    if (stack.size == 0) {
        return 0;
    }
    return stack.values[stack.size - 1];
}

/* Pops the element at the top of the stack and returns it. */
int stack_pop(void) {
    if (stack.size == 0) {
        return 0;
    }
    int bufferTopElement = stack_top();
    stack.size--;
    return bufferTopElement;
}

/* Pushes a given integer `n` at the top of the stack. */
void stack_push(int n) {
    if (stack.size >= MAX_SIZE) {
        return;
    }
    stack.values[stack.size] = n;
    stack.size++;
}

/* Displays the content of the stack on the standard output. */
void stack_display(void) {
    printf("Affichage de la pile\n");
    printf("---------------------------------\n|\tIndex\t|\tValue\t|\n---------"
           "------------------------\n");
    int i;
    for (i = stack.size - 1; i >= 0; i--) {
        printf("|\t%d\t|\t%d\t|\n", i + 1, stack.values[i]);
        printf("---------------------------------\n");
    }
}

/* Returns the element at index `index` inside the stack. The user is
   responsible of the use of this function. The answers may be not
   relevant if a call is done outside the current size of the
   stack. */
int stack_get_element(int index) { return stack.values[index]; }
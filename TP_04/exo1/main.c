#include "stack.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    stack_init();
    int i;
    for (i = 0; i < 10; i++) {
        stack_push(i);
    }

    stack_display();

    stack_push(5);
    stack_display();

    int popped_value = stack_pop();
    printf("popped value : %d\n", popped_value);
    stack_display();
    return 0;
}
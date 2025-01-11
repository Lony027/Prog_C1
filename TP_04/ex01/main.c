#include "stack.c"
#include "stack.h"

int main (int argc, char* argv[]) {
    /* write tests */

    stack_init();
    int i;
    for (i=0; i<55;i++) {
        stack_push(5);
    }
    stack_push(5);
    stack_display();

    /* stack_push(1);
    stack_display();
    stack_push(1);
    stack_display(); */
    return 0;
}
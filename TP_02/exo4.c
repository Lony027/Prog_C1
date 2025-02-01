#include <stdio.h>

/* Print value of N */
void print_var(int n) { printf("Value of the variable : %d\n", n); }

/* Print the address of the pointer, then the value at the adress */
void print_pointer(int *p) {
    printf("Pointer address : %p and Pointed value : %d\n", p, *p);
}

/* Set the value inside the pointer */
void set_pointer(int *p, int n) { *p = n; }

int main(int argc, char *argv[]) {
    int a;
    int *p = &a;

    print_var(a);
    a = 53;
    print_var(a);
    print_pointer(p);
    set_pointer(p, 42);
    print_pointer(p);
    print_var(a);

    return 0;
}
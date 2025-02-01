#include <stdio.h>

void print_iterative(int n) {
    int i;
    for (i = n; i > 0; i--) {
        printf("%d ", i);
    }
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    putchar('\n');
    return;
}

void print_rec(int n) {
    if (n > 0) {
        printf("%d ", n);
        print_rec(n - 1);
        printf("%d ", n);
    }
    return;
}

int main(int argc, char *argv[]) {
    int n = 10;
    printf("Iterative :\n");
    print_iterative(n);
    printf("Recursive :\n");
    print_rec(n);
    putchar('\n');
    return 0;
}

#include <stdio.h>

void printIterative (int n);

int main (int argc, char* argv[]) {
    printIterative(10);
    return 0;
}

void printIterative (int n) {
    int i;
    for (i = n; i > 0; i--) {
        printf("%d ", i);
    }
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    return;
}





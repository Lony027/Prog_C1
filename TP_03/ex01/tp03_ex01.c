#include <stdio.h>

int puissance_iteratif(int a, unsigned int n) {
    if (n == 0) {
        return 0;
    }
    int result = 1;
    int i;
    for (i = 0; i < n; i++) {
        result *= a;
    }

    return result;
}

int puissance_recursif (int a, unsigned int n) {
    if (n == 0) {
        return 1;
    }
    int puissance = puissance_recursif(a, n/2);
    if (n%2 == 0) {
        return puissance * puissance;
    } else {
        return a * puissance * puissance;
    }
    
}

int main (int argc, char* argv[]) {
    int a = 3;
    unsigned int n = 5;

    printf("puissance_iteratif : %d\n", puissance_iteratif(a, n));
    printf("puissance_recursif : %d\n", puissance_recursif(a, n));
    return 0;
}

/*  power(x, n) = power(x, n / 2) * power(x, n / 2);        // if n is even
    power(x, n) = x * power(x, n / 2) * power(x, n / 2);    // if n is odd */
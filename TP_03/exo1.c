#include <stdio.h>

int power_iter(int a, unsigned int n) {
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

int power_rec(int a, unsigned int n) {
    if (n == 0) {
        return 1;
    }
    int pow = power_rec(a, n / 2);
    if (n % 2 == 0) {
        return pow * pow;
    } else {
        return a * pow * pow;
    }
}

int main(int argc, char *argv[]) {
    int a = 2;
    unsigned int n = 10;

    printf("power_iter : %d\n", power_iter(a, n));
    printf("power_rec : %d\n", power_rec(a, n));
    return 0;
}
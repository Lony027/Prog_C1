#include <stdio.h>
#include <stdlib.h>

int compute_and_print_sum(int integerOne, int integerTwo) {
    printf("Sum of the two values %d\n", integerOne + integerTwo);
    return 0;
}

void ask_and_print_sum() {
    int integerOne, integerTwo;

    printf("Enter first value : ");
    scanf("%d", &integerOne);

    printf("Enter second value : ");
    scanf("%d", &integerTwo);
    putchar('\n');

    compute_and_print_sum(integerOne, integerTwo);
}

int main(int argc, char *argv[]) {
    switch (argc) {
    case 3:
        compute_and_print_sum(atoi(argv[1]), atoi(argv[2]));
        return 0;
    case 1:
        ask_and_print_sum();
        return 0;
    default:
        printf("The input should be 0 or 2 args\n");
        return 1;
    }
}

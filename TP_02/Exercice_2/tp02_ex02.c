#include <stdio.h>
#include <stdlib.h>

/* @to-do effet de bord */
/* ask and print sum should return a tab */
/* make file */

int computeAndPrintSum (int integerOne, int integerTwo);
void askAndPrintSum();

int main (int argc, char* argv[]) {
    /*should do a switch */
    
    if (argc == 3) {
        computeAndPrintSum(
            atoi(argv[1]), atoi(argv[2])
        );
        return 0;
    } else if (argc == 1) {
        askAndPrintSum();
        return 0;
    } else {
        printf("The input should be 0 or 2 args");
        return 1;
    }

}

void askAndPrintSum () {
    int integerOne, integerTwo;
    
    printf("Enter first value : ");
    scanf("%d", &integerOne);
    
    printf("Enter second value : ");
    scanf("%d", &integerTwo);
    printf("\n");

    computeAndPrintSum(integerOne, integerTwo);
}

int computeAndPrintSum (int integerOne, int integerTwo) {
    printf("Sum of the two values %d", integerOne + integerTwo);
    return 0;
}





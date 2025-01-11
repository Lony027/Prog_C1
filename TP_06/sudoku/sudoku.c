#include <stdio.h>

#include "sudoku.h"
/* SIZE SHOULD BE DYNAMIC? */

void initialize_empty_board(Board grid){
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            grid[i][j]=0;
        }
    }
}

void print_board(Board grid){
    int i, j, val;
    for (i = 0; i < 9; i++) {
        printf("-------------------------------------\n");
        for (j = 0; j < 9; j++) {
            val = grid[i][j];
            if (val == 0) {
                printf("|   ");
            } else {
                printf("| %d ", grid[i][j]);
            }
        }
        printf("|\n");
    }
     printf("-------------------------------------\n");
}

#include <stdio.h>

#include "sudoku.h"

void initialize_empty_board(Board grid) {
  int i, j;
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      grid[i][j] = 0;
    }
  }
}

void print_empty_line() {
  int i;
  for (i = 0; i < 9; i++) {
    if (i == 0 || i == 3 || i == 6) {
      putchar('|');
    }
    printf("|     ");
  }
  printf("||\n");
}

void print_line(Board grid, int y) {
  int i, val;
  for (i = 0; i < 9; i++) {
    val = grid[y][i];
    if (i == 0 || i == 3 || i == 6) {
      putchar('|');
    }

    if (val == 0) {
      printf("|     ");
    } else {
      printf("|  %d  ", val);
    }
  }
  printf("||\n");
}

void print_simple_separator() {
  printf("-----------------------------------------------------------\n");
}

void print_bold_separator() {
  printf("===========================================================\n");
}

void print_board(Board grid) {
  int i;
  print_bold_separator();
  for (i = 0; i < 9; i++) {
    print_empty_line();
    print_line(grid, i);
    print_empty_line();
    if (i == 2 || i == 5 || i == 8) {
      print_bold_separator();
    } else {
      print_simple_separator();
    }
  }
}

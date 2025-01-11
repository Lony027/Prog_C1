#include <stdio.h>

#include "in_out.h"
#include "sudoku.h"

/*
  -1 If new case create incoherence
  1 if new case is coherent
 */
int is_coherent(Board grid, int x, int y) {
  int val = grid[x][y];
  int i;
  for (i = 0; i < 9; i++) {
    if (grid[i][y] == val || grid[x][i] == val) {
      printf("l");
      return 0;
    }
  }
  printf("LAAAAAAAAAAAAAAAAAAAAAAAAAAA");
  return 1;
}

void solve(Board grid, int current_x, int max, int y) {
  if (y >= 9) {
    print_board(grid);
    return;
  }
  if (current_x >= max) {
    return;
  }

  int i, val;
  for (i = 0; i < max; i++) {
    val = grid[i][y];
    if (val == 0) {
      grid[i][y] = current_x;
      if (is_coherent(grid, i, y)) {
        solve(grid, current_x + 1, max, y);
        /* val = 0; */
      } else {
        grid[i][y] = 0;
      }
    }
  }
  solve(grid, 1, max, y + 1);
}

int main(int argc, char *argv[]) {
  Board B;

  fread_board(argv[1], B);
  print_board(B);

  initialize_empty_board(B);
  print_board(B);

  solve(B, 1, 9, 0);
  print_board(B);
  return 0;
}

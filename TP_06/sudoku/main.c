#include "in_out.h"
#include "sudoku.h"

int is_coherent(Board grid, int x, int y, int val) {
  int i;
  for (i = 0; i < 9; i++) {
    if (grid[i][y] == val || grid[x][i] == val) {
      return 0;
    }
  }

  int block_x = (x / 3) * 3;
  int block_y = (y / 3) * 3;

  int j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (grid[block_x + i][block_y + j] == val) {
        return 0;
      }
    }
  }

  return 1;
}

void solve(Board grid, int x, int y) {

  if (x >= 9) {
    solve(grid, 0, y + 1);
    return;
  }

  if (y >= 9) {
    print_board(grid);
    return;
  }

  if (grid[x][y] != 0) {
    solve(grid, x + 1, y);
    return;
  }

  int i;
  for (i = 1; i <= 9; i++) {
    if (is_coherent(grid, x, y, i) == 1) {
      grid[x][y] = i;
      solve(grid, x + 1, y);
      grid[x][y] = 0;
    }
  }
}

int main(int argc, char *argv[]) {
  Board B;

  int error = fread_board(argv[1], B);
  if (error == 0) {
    return -1;
  }
  /* print_board(B); */

  /* initialize_empty_board(B); */
  /*   print_board(B); */

  solve(B, 0, 0);
  /* grid 5 à 7 solutions */
  return 0;
}

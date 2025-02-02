#include "sudoku.h"

void initialize_empty_board(Board grid) {
  int i, j;
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      grid[i][j] = 0;
    }
  }
}

void copy_grid(Board og_board, Board dest_board) {
    for (int x=0; x<9; x++) {
        for (int y=0; y<9; y++) {
            dest_board[x][y] = og_board[x][y];
        }
    }

}

int is_coherent(Board grid, int x, int y) {
    int val = grid[x][y];
    int i;

    for (i = 0; i < 9; i++) {
        if (i != x && grid[i][y] == val) {
            return 0;
        }
        if (i != y && grid[x][i] == val) {
            return 0;
        }
    }

    int block_x = (x / 3) * 3;
    int block_y = (y / 3) * 3;

    int j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int bx = block_x + i;
            int by = block_y + j;
            if (bx == x && by == y)
                continue;
            if (grid[bx][by] == val) {
                return 0;
            }
        }
    }

    return 1;
}

int is_won(Board grid) {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (grid[y][x] == 0 || !is_coherent(grid, y, x)) {
                return 0;
            }
        }
    }
    return 1;
}

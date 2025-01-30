#include "in_out.h"
#include "sudoku.h"
#include "stdio.h"
#include "view.h"
#include <stdlib.h>

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
  Board grid;

  int error = fread_board(argv[1], grid);
  if (error == 0) {
    return -1;
  } 

  init_view(grid);
    Board ref_grid;
    copy_grid(grid, ref_grid);
    int x_case;
    int y_case;
    int clicked_x;
    int clicked_y;
    int* val =  malloc(sizeof(int));
    while (1) { // while is solvalble
      get_clicked_case(&x_case, &y_case);
      if (x_case > 8 || y_case > 8) {
          if (x_case >= 10 && x_case <= 12 && y_case >= 3 && y_case <=5) {
              // prevoir si clicked_x = 0
              printf("clicked_x: %d, clicked_y:%d\n", clicked_x, clicked_y);
              
              assign_val_selector(x_case, y_case, clicked_x, clicked_y, val);
              grid[clicked_x][clicked_y] = *val;
              draw_board(grid, ref_grid);
              erase_selector();
          }
          continue;
      } else if (ref_grid[x_case][y_case] != 0) {
          continue;
      }
      /* if (grid[clicked_x][clicked_y] == 0) {
        reset_cell(clicked_x, clicked_y);
      } */
      clicked_x = x_case;
      clicked_y = y_case;
      draw_question_mark(clicked_x, clicked_y);
      draw_selector();
  }
  free_window();


  /* solve(B, 0, 0); */
  return 0;
}

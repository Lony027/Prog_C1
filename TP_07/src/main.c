#include "in_out.h"
#include "stdio.h"
#include "sudoku.h"
#include "view.h"
#include <stdlib.h>

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
            if (!is_coherent(grid, x, y)) {
                return 0;
            }
        }
    }
    return 1;
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
    int *val = malloc(sizeof(int));
    while (!is_won(ref_grid)) {   // while is solvalble
        get_clicked_case(&x_case, &y_case);
        if (x_case > 8 || y_case > 8) {
            if (x_case >= 10 && x_case <= 12 && y_case >= 3 && y_case <= 5) {
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
        draw_board(grid, ref_grid);
        clicked_x = x_case;
        clicked_y = y_case;
        draw_question_mark(clicked_x, clicked_y);
        draw_selector();
    }
    printf("Partie gagné !\n");
    free_window();
    return 0;
}

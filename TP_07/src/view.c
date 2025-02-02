#include "view.h"
#include "sudoku.h"
#include <MLV/MLV_all.h>

#define WINDOW_WIDTH  1400
#define WINDOW_HEIGTH 910

#define OFFSET     5
#define CELL_SCALE 100

void free_window() { MLV_free_window(); }

void reset_cell(int x, int y) {
    MLV_draw_filled_rectangle(x + 1, y + 1, CELL_SCALE - 2, CELL_SCALE - 2,
                              MLV_COLOR_BLACK);
}

void draw_cell(int x, int y, int scale, MLV_Color color) {
    MLV_draw_rectangle(scale * x + OFFSET, scale * y + OFFSET, scale, scale,
                       color);
}

void draw_number_on_cell(int val, int x, int y, MLV_Color color) {
    reset_cell(x, y);

    char v[2] = {val + '0', '\0'};
    MLV_draw_text(x + CELL_SCALE / 2 - 8, y + CELL_SCALE / 2 - 8, v, color);
}

void draw_question_mark(int x, int y) {
    x = CELL_SCALE * x + OFFSET;
    y = CELL_SCALE * y + OFFSET;
    reset_cell(x, y);
    MLV_draw_text(x + CELL_SCALE / 2 - 8, y + CELL_SCALE / 2 - 8, "?",
                  MLV_COLOR_WHITE);
    MLV_update_window();
}

void draw_selector() {
    int x_start = WINDOW_WIDTH / 1.4;
    int y_start = (WINDOW_HEIGTH / 2) - (CELL_SCALE * 1.5);
    int i = 1;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            MLV_draw_rectangle((x_start + CELL_SCALE * x),
                               y_start + CELL_SCALE * y, CELL_SCALE, CELL_SCALE,
                               MLV_COLOR_WHITE);
            draw_number_on_cell(i, (x_start + CELL_SCALE * y),
                                (y_start + CELL_SCALE * x), MLV_COLOR_WHITE);
            i++;
        }
    }
    MLV_actualise_window();
}

void erase_selector() {
    int x_start = WINDOW_WIDTH / 1.4;
    int y_start = (WINDOW_HEIGTH / 2) - (CELL_SCALE * 1.5);
    MLV_draw_filled_rectangle((x_start), (y_start), CELL_SCALE * 3,
                              CELL_SCALE * 3, MLV_COLOR_BLACK);
    MLV_actualise_window();
}

void draw_empty_board() {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            draw_cell(x, y, CELL_SCALE, MLV_COLOR_GRAY50);
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            draw_cell(x, y, CELL_SCALE * 3, MLV_COLOR_WHITE);
        }
    }
    MLV_update_window();
}

void draw_board(Board grid, Board ref_grid) {
    int val, ref_val;
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            val = grid[x][y];
            ref_val = ref_grid[x][y];
            if (ref_val != 0) {
                draw_number_on_cell(val, CELL_SCALE * y + OFFSET,
                                    CELL_SCALE * x + OFFSET, MLV_COLOR_GRAY50);
            } else if (val != 0) {
                MLV_Color color = MLV_COLOR_WHITE;
                if (is_coherent(grid, x, y) == 0) {
                    color = MLV_COLOR_RED;
                }
                draw_number_on_cell(val, CELL_SCALE * y + OFFSET,
                                    CELL_SCALE * x + OFFSET, color);
            } else if (val == 0) {
                reset_cell(CELL_SCALE * y + OFFSET, CELL_SCALE * x + OFFSET);
            }
        }
    }
    MLV_update_window();
}

void get_clicked_case(int *x, int *y) {
    MLV_wait_mouse(x, y);
    *x = (*x - OFFSET) / CELL_SCALE;
    *y = (*y - OFFSET) / CELL_SCALE;   // OFFSET ?
}

void init_view(Board grid) {
    MLV_create_window("Sudoku", "Sudoku", WINDOW_WIDTH, WINDOW_HEIGTH);
    draw_empty_board();
    draw_board(grid, grid);
    MLV_update_window();
}
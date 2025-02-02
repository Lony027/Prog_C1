#include "in_out.h"
#include "stdio.h"
#include "sudoku.h"
#include "view.h"

int main(int argc, char *argv[]) {
    Board grid;

    int error = fread_board(argv[1], grid);
    if (error == 0) {
        return -1;
    }

    Board ref_grid;
    copy_grid(grid, ref_grid);

    init_view(grid);
    int x_case, y_case, clicked_x, clicked_y;
    while (!is_won(grid)) {
        get_clicked_case(&x_case, &y_case);
        draw_board(grid, ref_grid);
        if (x_case > 8 || y_case > 8) {
            if (x_case >= 10 && x_case <= 12 && y_case >= 3 && y_case <= 5) {
                grid[clicked_y][clicked_x] = (3 * (y_case - 3) + (x_case - 10) + 1);
                draw_board(grid, ref_grid);
                erase_selector();
            }
            continue;
        } else if (ref_grid[y_case][x_case] != 0) {
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

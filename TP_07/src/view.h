#ifndef __VIEW__
#define __VIEW__

#include "sudoku.h"


void init_view(Board grid);
void free_window();
void draw_empty_board();
void draw_board(Board grid, Board ref_grid);
void get_clicked_case(int *x, int *y);
void drawed_clicked_number(int x_case, int y_case, int clicked_x, int clicked_y);
void erase_selector();
void draw_selector();
void draw_question_mark(int x, int y);
void reset_cell(int x, int y);

#endif

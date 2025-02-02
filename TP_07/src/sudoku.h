#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];

void initialize_empty_board(Board grid);
void print_board(Board grid);
void copy_grid(Board og_board, Board dest_board);
int is_coherent(Board grid, int x, int y);
int is_won(Board grid);

#endif

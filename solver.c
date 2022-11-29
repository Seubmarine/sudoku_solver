#include <stdio.h>
#include "sudoku_verify.h"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;
	int sudoku[9][9] = {{0, 7, 0,  0, 0, 9,  0, 0, 0},
						{2, 3, 6,  0, 0, 0,  7, 0, 8},
						{0, 5, 0,  2, 0, 0,  0, 0, 0},

						{0, 9, 0,  0, 0, 6,  2, 0, 0},
						{6, 0, 0,  0, 2, 0,  0, 0, 0},
						{0, 0, 0,  5, 1, 8,  4, 0, 0},
						
						{0, 0, 0,  0, 0, 1,  0, 3, 0},
						{0, 6, 0,  8, 0, 0,  0, 5, 2},
						{0, 0, 0,  0, 9, 0,  0, 0, 1},
						};
	int x = 3;
	int	y = 5;
	int is_valid = sudoku_is_valid_at_index(x, y, sudoku);
	printf("is_valid = %i\n", is_valid);
	return 0;
}

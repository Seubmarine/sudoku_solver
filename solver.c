#include <stdio.h>
#include "sudoku_verify.h"

int	solver_backtrack(int sudoku[9][9], int x, int y)
{
	if (sudoku[y][x] == 0)
	{
		size_t i;
		for (i = 1; i <= 9; i++)
		{
			sudoku[y][x] = i;
			if (sudoku_is_valid_at_index(x, y, sudoku) == 1)
			{
				int next_x = x + 1;
				int next_y = y;
				if (next_x == 9)
				{
					next_x = 0;
					next_y += 1;
				}
				if (next_y >= 9 || solver_backtrack(sudoku, next_x, next_y))
					return (1);
			}
			sudoku[y][x] = 0;
		}
		return (0);
	}
	else
	{
		x++;
		if (x == 9)
		{
			x = 0;
			y += 1;
		}
		if (y >= 9)
			return (1);
		return (solver_backtrack(sudoku, x, y));
	}
}

int	solver(int sudoku[9][9])
{
	return (solver_backtrack(sudoku, 0, 0));
}

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

	if (!solver(sudoku))
	{
		printf("Sudoku is invalid\n");
		return (1);
	}
	for (size_t y = 0; y < 9; y++)
	{
		for (size_t x = 0; x < 9; x++)
		{
			printf("%i, ", sudoku[y][x]);
			if (x % 3 == 2)
				printf("||");
		}
		if (y % 3 == 2)
			printf("\n================================");
		printf("\n");
	}
	printf("\n");
	return 0;
}

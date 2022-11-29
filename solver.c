#include <stddef.h>
#include <stdio.h>
#include <string.h>

int	sudoku_is_nine_different_number(int numbers[9])
{
	for (size_t i = 0; i < 9; i++)
	{
		int current = numbers[i];
		if (current != 0)
		{
			int is_same = 0;
			is_same = 0;
			for (size_t j = 0; j < 9; j++)
			{
				if (current == numbers[j])
					is_same++;
				if (is_same >= 2)
				{
					// printf("Error: number %i at index %zu repeat at index %zu\n", numbers[j], i, j);
					return (0);
				}
			}
		}
	}
	return (1);
}

void	print_buffer(int buffer[9])
{
	for (size_t i = 0; i < 9; i++)
	{
		printf("%i, ", buffer[i]);
	}
	printf("\n");
}

void	sudoku_get_row(int x, int y, int buffer[9], int sudoku_board[9][9])
{
	memcpy(buffer, &sudoku_board[y][0], sizeof(int) * 9);
}

void	sudoku_get_column(int x, int y, int buffer[9], int sudoku_board[9][9])
{
	for (size_t i = 0; i < 9; i++)
	{
		buffer[i] = sudoku_board[i][x];
	}
}

void	sudoku_get_box(int x, int y, int buffer[9], int sudoku_board[9][9])
{
	int begin_x = x / 3;
	int begin_y = y / 3;
	for (size_t i = 0; i < 3; i++)
	{
		memcpy(&buffer[i * 3], &sudoku_board[(begin_y * 3) + (i)][begin_x * 3], sizeof(int) * 3);
	}	
}

int	sudoku_is_valid_at_index(int x, int y, int sudoku_board[9][9])
{
	int buffer[9] = {};
	sudoku_get_row(x, y, buffer, sudoku_board);
	if (!sudoku_is_nine_different_number(buffer))
		return (0);
	sudoku_get_column(x, y, buffer, sudoku_board);
	if (!sudoku_is_nine_different_number(buffer))
		return (0);
	sudoku_get_box(x, y, buffer, sudoku_board);
	if (!sudoku_is_nine_different_number(buffer))
		return (0);
	return (1);
}

int main(int argc, char const *argv[])
{
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

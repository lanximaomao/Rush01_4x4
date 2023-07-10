
#include "rush01.h"

int	existing_digit(t_skyscraper *hm, int row, int col)
{
	if ((col + 1) < hm->actual_size)
		return (solve_it(hm, row, col + 1));
	else if ((row + 1) < hm->actual_size)
		return (solve_it(hm, row + 1, 0));
	else
		return (1);
}

// case of 0 digit: checks digits 1..actual size
int	new_digit(t_skyscraper *hm, int row, int col)
{
	int	max_index;
	int	digit;

	max_index = hm->actual_size;
	digit = 1;
	while (digit <= max_index)
	{
		if (valid_placement(hm, row, col, digit))
		{
			hm->grid[row][col] = digit;
			if (check_all_bounds(hm, row, col) == 1)
			{
				if (solve_it(hm, row, col))
					return (1);
			}
			hm->grid[row][col] = 0;
		}
		digit++;
	}
	return (0);
}

// Returns 1 if the solution is found, otherwise 0.
// Parameters: program struct, row, column.
int	solve_it(t_skyscraper *hm, int row, int col)
{
	if (row >= hm->actual_size || col >= hm->actual_size)
		return (1);
	else
	{
		if (hm->grid[row][col] != 0)
			return (existing_digit(hm, row, col));
		else
			return (new_digit(hm, row, col));
		return (0);
	}
}

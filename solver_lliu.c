#include "rush01.h"

int	solve_it(t_skyscraper *hm, int row, int col)
{
	int	n;

	n = 1;
	if (row == hm->actual_size && col == hm->actual_size)
		return (1);
	if (col == hm->actual_size)
	{
		row++;
		col = 0;
	}
	if (hm->grid[row][col] != 0)
		return (solve_it(hm, row, col + 1));
	while (n <= hm->actual_size)
	{
		if (valid_placement(hm, row, col, n))
		{
			hm->grid[row][col] = n;
			if (check_all_bounds(hm, row, col) == 1 && solve_it(hm, row, col))
				return (1);
		}
		hm->grid[row][col] = 0;
		n++;
	}
	return (0);
}

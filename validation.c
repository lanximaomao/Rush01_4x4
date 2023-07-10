
#include "rush01.h"

//if col or row is full we may need to validate that number visible == boundary

int	check_colup(t_skyscraper *hm, int col)
{
	t_boundary_checker	checker;
	int i;

	checker.boundary = hm->boundaries[0][col];
	checker.number_visible = 0;
	checker.base = 0;
	i = 0;
	while (i < hm->actual_size)
	{
		if (hm->grid[i][col] == 0)
			i++;
		else if (checker.base == 0)
		{
			checker.base = hm->grid[i++][col];
			checker.number_visible++;
		}
		else if (hm->grid[i++][col] > checker.base)
		{
			checker.base = hm->grid[i - 1][col];
			checker.number_visible++;
		}
		if (checker.number_visible > checker.boundary)
			return (0);
	}
	return (1);
}


int	check_coldown(t_skyscraper *hm, int col)
{
	t_boundary_checker	checker;
	int i;

	checker.boundary = hm->boundaries[1][col];
	checker.number_visible = 0;
	checker.base = 0;
	i = hm->actual_size - 1;
	while (i >= 0)
	{
		if (hm->grid[i][col] == 0)
			i--;
		else if (checker.base == 0)
		{
			checker.base = hm->grid[i--][col];
			checker.number_visible++;
		}
		else if (hm->grid[i--][col] > checker.base)
		{
			checker.base = hm->grid[i + 1][col];
			checker.number_visible++;
		}
		if (checker.number_visible > checker.boundary)
			return (0);
	}
	return (1);
}

int	check_rowleft(t_skyscraper *hm, int row)
{
	t_boundary_checker	checker;
	int i;

	checker.boundary = hm->boundaries[2][row];
	checker.number_visible = 0;
	checker.base = 0;
	i = 0;
	while (i < hm->actual_size)
	{
		if (hm->grid[row][i] == 0)
			i++;
		else if (checker.base == 0)
		{
			checker.base = hm->grid[row][i++];
			checker.number_visible++;
		}
		else if (hm->grid[row][i++] > checker.base)
		{
			checker.base = hm->grid[row][i - 1];
			checker.number_visible++;
		}
		if (checker.number_visible > checker.boundary)
			return (0);
	}
	return (1);
}

int	check_rowright(t_skyscraper *hm, int row)
{
	t_boundary_checker	checker;
	int i;

	checker.boundary = hm->boundaries[3][row];
	checker.number_visible = 0;
	checker.base = 0;
	i = hm->actual_size - 1;
	while (i >= 0)
	{
		if (hm->grid[row][i] == 0)
			i--;
		else if (checker.base == 0)
		{
			checker.base = hm->grid[row][i--];
			checker.number_visible++;
		}
		else if (hm->grid[row][i--] > checker.base)
		{
			checker.base = hm->grid[row][i + 1];
			checker.number_visible++;
		}
		if (checker.number_visible > checker.boundary)
			return (0);
	}
	return (1);
}

int	check_all_bounds(t_skyscraper *hm, int row, int col)
{
	if (check_coldown(hm, col) == 0)
		return (0);
	if (check_colup(hm, col) == 0)
		return (0);
	if (check_rowleft(hm, row) == 0)
		return (0);
	if (check_rowright(hm, row) == 0)
		return (0);
	return (1);
}
	// checker[1].boundary = hm->boundaries[1][x];
	// checker[2].boundary = hm->boundaries[2][y];
	// checker[3].boundary = hm->boundaries[3][y];

	// hm->boundaries[0][x] -> from top to down
	// hm->boundaries[1][x] -> from bottom to up
	// hm->boundaries[2][y] -> from left to right
	// hm->boundaries[3][y] -> from right to left

int	valid_placement(t_skyscraper *hm, int row, int col, int to_check)
{
	int	i;

	i = 0;
	// check for duplicate in col or row
	while (i < hm->actual_size)
	{
		if (hm->grid[row][i] == to_check || hm->grid[i][col] == to_check)
			return (0);
		i++;
	}
	return (1);
}

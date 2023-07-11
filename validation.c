
#include "rush01.h"
#include <stdio.h>
#include "utils.h"

int	check_colup(t_skyscraper *hm, int col)
{
	t_boundary_checker	checker;
	int i;
	int block;
	int zeros = 1;

	checker.boundary = hm->boundaries[0][col];
	//char c = checker.boundary + '0';
	//ft_putstr_fd("cup:", 1);
	//write(1, &c, 1);
	//ft_putstr_fd("\n", 1);
	checker.number_visible = 0;
	checker.base = 0;
	i = 0;
	while (i < hm->actual_size)
	{
		if (hm->grid[i][col] == 0)
		{
			i++;
			zeros = -1;
		}
		else if (i <= hm->actual_size && hm->grid[i++][col] > checker.base)
		{
			checker.base = hm->grid[i - 1][col];
			checker.number_visible++;
		}
		if (checker.number_visible > checker.boundary)
		{
			block = hm->actual_size - checker.base;
			if (block == 0)
				return (0);
		}
	}
	if (zeros == 1) // full filled row/col
	{
		if (checker.number_visible != checker.boundary)
			return(0);
	}
	return (1);
}

int	check_coldown(t_skyscraper *hm, int col)
{
	t_boundary_checker	checker;
	int i;
	int block;
	int zeros = 1;

	checker.boundary = hm->boundaries[1][col];
	//char c = checker.boundary + '0';
	//ft_putstr_fd("cdown:", 1);
	//write(1, &c, 1);
	//ft_putstr_fd("\n", 1);
	checker.number_visible = 0;
	checker.base = 0;
	i = hm->actual_size - 1;
	while (i >= 0)
	{
		if (hm->grid[i][col] == 0)
		{
			i--;
			zeros = -1;
		}
		else if (i >= 0 && hm->grid[i--][col] > checker.base)
		{
			checker.base = hm->grid[i + 1][col];
			checker.number_visible++;
		}
		if (checker.number_visible > checker.boundary)
		{
			block = hm->actual_size - checker.base;
			if (block == 0)
				return (0);
		}
	}
	if (zeros == 1) // full filled row/col
	{
		if (checker.number_visible != checker.boundary)
			return(0);
	}
	return (1);
}

int	check_rowleft(t_skyscraper *hm, int row)
{
	t_boundary_checker	checker;
	int i;
	int block;
	int zeros = 1;

	checker.boundary = hm->boundaries[2][row];
	//char c = checker.boundary + '0';
	//ft_putstr_fd("rleft:", 1);
	//write(1, &c, 1);
	//ft_putstr_fd("\n", 1);
	checker.number_visible = 0;
	checker.base = 0;
	i = 0;
	while (i < hm->actual_size)
	{
		if (hm->grid[row][i] == 0)
		{
			i++;
			zeros = -1;
		}
		else if (i <= hm->actual_size && hm->grid[row][i++] > checker.base)
		{
			checker.base = hm->grid[row][i - 1];
			checker.number_visible++;
		}
		if (checker.number_visible > checker.boundary)
		{
			block = hm->actual_size - checker.base;
			if (block == 0)
				return (0);
		}
	}
	if (zeros == 1) // full filled row/col
	{
		if (checker.number_visible != checker.boundary)
			return(0);
	}
	return (1);
}

int	check_rowright(t_skyscraper *hm, int row)
{
	t_boundary_checker	checker;
	int i;
	int block;
	int zeros;

	checker.boundary = hm->boundaries[3][row];
	//char c = checker.boundary + '0';
	//ft_putstr_fd("rright:", 1);
	//write(1, &c, 1);
	//ft_putstr_fd("\n", 1);
	checker.number_visible = 0;
	checker.base = 0;
	i = hm->actual_size - 1;
	zeros = 1;
	while (i >= 0)
	{
		if (hm->grid[row][i] == 0)
		{
			i--;
			zeros = -1;
		}
		else if (i >= 0 && hm->grid[row][i--] > checker.base)
		{
			checker.base = hm->grid[row][i+1];
			checker.number_visible++;
		}
		if (checker.number_visible > checker.boundary)
		{
			block = hm->actual_size - checker.base;
			if (block == 0)
				return (0);
		}
	}
	if (zeros == 1) // full filled row/col
	{
		if (checker.number_visible != checker.boundary)
			return(0);
	}
	return (1);
}

int	check_all_bounds(t_skyscraper *hm, int row, int col)
{
	if (check_coldown(hm, col) == 0)
	{
		//write(1, "CD\n", 3);
		return (0);
	}
	if (check_colup(hm, col) == 0)
	{
		//write(1, "CU\n", 3);
		return (0);
	}
	if (check_rowleft(hm, row) == 0)
	{
		//write(1, "RL\n", 3);
		return (0);
	}
	if (check_rowright(hm, row) == 0)
	{
		//write(1, "RR\n", 3);
		return (0);
	}
	return (1);
}

int	valid_placement(t_skyscraper *hm, int row, int col, int to_check)
{
	int	i;

	i = 0;
	while (i < hm->actual_size)
	{
		if (hm->grid[row][i] == to_check || hm->grid[i][col] == to_check)
			return (0);
		i++;
	}
	return (1);
}

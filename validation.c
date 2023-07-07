
#include "rush01.h"

void	get_relevant_boundaries(t_false *whatever, int y, int x)
{
	whatever->boundaries[0][x] -> from top to down
	whatever->boundaries[1][x] -> from bottom to up 
	whatever->boundaries[2][y] -> from left to right
	whatever->boundaries[3][y] -> from right to left
}

int	validate_placement(t_false *whatever, int x, int y, int to_check)
{
	int	i;
	int	boundary_vals[4];

	i = 0;
	// check for duplicate in col or row
	while (i < whatever->actual_size)
	{
		if (whatever->grid[x][i] == to_check || whatever->grid[i][y] == to_check)
			return (0);
		i++;
	}
	// check if it meets visibility reqs

}

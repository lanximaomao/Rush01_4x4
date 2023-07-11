
#ifndef RUSH_01_H
# define RUSH_01_H

# define GRID_SIZE 9
# define BOUNDARY_SIZE 4
# define ERROR 1
# define SUCCESS 0

#include <unistd.h>

typedef	struct s_skyscraper
{
	int	grid[GRID_SIZE][GRID_SIZE];
	int	boundaries[BOUNDARY_SIZE][GRID_SIZE];
	int actual_size;

}	t_skyscraper;

typedef struct s_boundry_checker
{
	int	boundary;
	int	base;
	int	number_visible;
}		t_boundary_checker;

int	valid_placement(t_skyscraper *hm, int y, int x, int to_check);
int	check_all_bounds(t_skyscraper *hm, int y, int x);
int	solve_it(t_skyscraper *hm, int row, int col);
void print_result(t_skyscraper *hm);

#endif

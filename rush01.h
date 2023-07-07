
#ifndef RUSH_01_H
# define RUSH_01_H

# define GRID_SIZE 9
# define BOUNDARY_SIZE 4
# define ERROR 1
# define SUCCESS 0

typedef	struct s_false_sudoku
{
	int	grid[GRID_SIZE][GRID_SIZE];
	int	boundaries[BOUNDARY_SIZE][GRID_SIZE];
	int actual_size;

}	t_false;

// typedef union u_grid {
// 	int	grid_4[4][4];
// 	int grid_5[5][5];
// 	int	grid_6[6][6];
// 	int	grid_7[7][7];
// 	int grid_8[8][8];
// 	int grid_9[9][9];
// }	u_grid;

#endif
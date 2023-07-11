
#include "rush01.h"
#include "utils.h"

int	to_int(char **str, int flag)
{
	int	arg;

	arg = -1;
	if (is_whitespace(**str) && flag != 0)
		(*str)++;
	else if (!is_whitespace(**str) && flag != 0)
		return (arg);
	if (**str == '+')
		(*str)++;
	if (ft_is_digit(**str))
	{
		arg = **str - '0';
		(*str)++;
	} // TODO maybe add condition for leading zero
	return (arg);
}

int	find_size(int index)
{
	if (index == 16)
		return (4);
	else if (index == 20)
		return (5);
	else if (index == 24)
		return (6);
	else if (index == 28)
		return (7);
	else if (index == 32)
		return (8);
	else if (index == 36)
		return (9);
	else
		return (ERROR);
}

int	copy_and_validate(int raw_input[], t_skyscraper *hm, int index)
{
	int i;
	int j;
	int	k;

	j = 0;
	i = 0;
	k = 0;
	hm->actual_size = find_size(index);
	if (hm->actual_size == ERROR)
	{
		ft_putendl_fd("what is your grid size?!", 2);
		return (ERROR);
	}
	while (i < BOUNDARY_SIZE)
	{
		while (j < hm->actual_size)
		{
			if (raw_input[k] <= 0 || raw_input[k] > hm->actual_size)
			{
				ft_putendl_fd("No zero is accepted", 2);
				return (ERROR);
			}
			hm->boundaries[i][j] = raw_input[k];
			j++;
			k++;
		}
		j = 0;
		i++;
	}
	return (SUCCESS);
}

int	process_input(char *input, t_skyscraper *hm)
{
	char	*input_ptr;
	int		raw_input[36]; // TODO make macro for this
	int 	index;

	input_ptr = input;
	index = 0;
	while (*input_ptr && index < 36)
	{
		raw_input[index] = to_int(&input_ptr, index);
		if (raw_input[index] == -1)
		{
			ft_putstr_fd("not a valid digit", 2);
			return (ERROR);
		}
		index++;
	}
	if (*input_ptr || copy_and_validate(raw_input, hm, index) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
void	zero_arrays(t_skyscraper *hm)
{
	int i;
	int j;

	i = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			hm->grid[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < BOUNDARY_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			hm->boundaries[i][j] = 0;
			j++;
		}
		i++;
	}
}

void print_result(t_skyscraper *hm)
{
	int i;
	int j;
	char c;


	i = 0;
	while (i < hm->actual_size)
	{
		j = 0;
		while (j < hm->actual_size)
		{
			c = hm->grid[i][j] + '0';
			write(1, &c, 1);
			if (j != hm->actual_size - 1)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	//write(1, "\n", 1);
}

//int	boundaries[BOUNDARY_SIZE][GRID_SIZE];
void display_boundaries(t_skyscraper *hm)
{
	int i;
	int j;
	char c;

	i = 0;
	ft_putendl_fd("\nmy boundary conditions are:", 1);
	while (i < BOUNDARY_SIZE)
	{
		j = 0;
		while (j < hm->actual_size)
		{
			c = hm->boundaries[i][j] + '0';
			write(1, &c, 1);
			if (j != hm->actual_size - 1)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	//write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_skyscraper	 hm;

	if (argc != 2)
	{
		ft_putendl_fd("wrong number of arguments.", 2);
		return (ERROR);
	}
	zero_arrays(&hm);
	if (process_input(argv[1], &hm) == ERROR)
		return (ERROR);
	//display_boundaries(&hm);
	if (solve_it(&hm, 0, 0) == 1)
		print_result(&hm);
	else
		ft_putendl_fd("no solution found.", 1);
	return (SUCCESS);
}

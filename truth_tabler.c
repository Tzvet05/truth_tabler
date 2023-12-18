#include "truth_tabler.h"

size_t	exponent(size_t n, size_t exponent)
{
	size_t	power;

	power = 1;
	while (exponent)
	{
		power *= n;
		exponent--;
	}
	return (power);
}

void	free_barr(t_barr **array)
{
	size_t	*i;
	t_barr	tmp;

	i = 0;
	tmp = array[i];
	while (tmp)
	{
		free(tmp);
		i++;
		tmp = array[i];
	}
	free(array);
}

t_barr	**alloc_barr(size_t height, size_t width)
{
	t_barr	**array;
	t_barr	*new;

	array = malloc((height + 1) * sizeof(t_barr *));
	if (!array)
		return (NULL);
	array[height] = NULL;
	while (height)
	{
		new = array[height - 1];
		new = malloc((width + 1) * sizeof(t_barr));
		if (!new)
		{
			free_arr(array);
			return (NULL);
		}
		new[width] = NULL;
		height--;
	}
	return (array);
}

t_barr	**alloc_input(size_t n_inputs)
{
	t_barr	**inputs;
	size_t	combinations;
	size_t	i;

	combinations = exponent(2, n_inputs);
	inputs = alloc_barr(combinations, n_inputs);
	if (!inputs)
		return (0);
	while (combinations)
	{
		i = 0;
		while (i < n_inputs)
		{
			inputs[combinations - 1][i] = (combinations >> i) % 2;
			i++;
		}
		combinations--;
	}
	return (inputs);
}

size_t	count_inputs(char *expression)
{
	size_t	inputs;
	size_t	i;

	inputs = 0;
	i = 0;
	while ()
	{
		
		i++;
	}
	return (inputs);
}

int	main(int argc, char **argv)// n_inputs <= 64
{
	size_t	n_inputs;
	t_barr	**inputs;

	(void)argc;
	n_inputs = count_inputs(argv[1]);
	if (!n_inputs)
		return (1);
	inputs = alloc_inputs(n_inputs);
	if (!inputs)
		return (1);
	
	free(inputs);
	return (0);
}

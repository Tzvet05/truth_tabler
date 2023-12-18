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
	size_t	i;
	bool	*tmp;

	i = 0;
	tmp = array[i]->array;
	while (tmp)
	{
		free(tmp);
		i++;
		tmp = array[i]->array;
	}
	free(array);
}

t_barr	**alloc_barr(size_t height, size_t width)
{
	t_barr	**array;

	array = malloc((height + 1) * sizeof(t_barr *));
	if (!array)
		return (NULL);
	array[height] = NULL;
	write(1, "heh", 3);
	while (height)
	{
		write(1, "hih", 3);
		array[height - 1]->array = malloc(width * sizeof(bool));
		write(1, "oof", 3);
		if (!array[height - 1]->array)
		{
			free_barr(array);
			return (NULL);
		}
		height--;
	}
	write(1, "hah", 3);
	return (array);
}

t_barr	**alloc_barr_inputs(size_t n_inputs)
{
	t_barr	**inputs;
	size_t	combinations;
	size_t	i;

	combinations = exponent(2, n_inputs);
	write(1, "huh", 3);
	inputs = alloc_barr(combinations, n_inputs);
	write(1, "hoh", 3);
	if (!inputs)
		return (0);
	while (combinations)
	{
		i = n_inputs;
		while (i)
		{
			inputs[combinations - 1]->array[i - 1] = ((combinations - 1) >> i) % 2;
			i--;
		}
		combinations--;
	}
	return (inputs);
}

size_t	count_inputs(char *expression)
{
	size_t	inputs;
	size_t	i;

	inputs = 6;/*
	i = 0;
	while ()
	{
		
		i++;
	}*/
	return (inputs);
}

int	main(int argc, char **argv)// n_inputs <= 64
{
	size_t	n_inputs;
	t_barr	**inputs;

	if (argc != 2)
	{
		write(1, "Error : incorrect number of arguments provided.", 47);
		return (1);
	}
	n_inputs = count_inputs(argv[1]);
	if (!n_inputs || n_inputs > 64)
	{
		write(1, "Error : invalid number of input bits (< 1 || > 64).", 51);
		return (1);
	}
	inputs = alloc_barr_inputs(n_inputs);
	if (!inputs)
	{
		write(1, "Error : failed memory allocation.", 33);
		return (1);
	}
	int i = 0;
	while (inputs[i])
	{
		printf("%p   ",inputs[i]->array);
		i++;
	}
	free_barr(inputs);
	return (0);
}

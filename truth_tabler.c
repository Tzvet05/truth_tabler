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
	t_barr	*tmp;

	i = 0;
	tmp = array[i];
	while (tmp)
	{
		free(tmp->array);
		free(tmp);
		i++;
		tmp = array[i];
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
	while (height)
	{
		array[height - 1] = malloc(sizeof(t_barr));
		if (!array[height - 1])
		{
			free_barr(array);
			return (NULL);
		}
		array[height - 1]->array = malloc(width * sizeof(bool));
		if (!array[height - 1]->array)
		{
			free_barr(array);
			return (NULL);
		}
		height--;
	}
	return (array);
}

t_barr	**alloc_barr_inputs(size_t n_inputs)
{
	t_barr	**input_comb;
	size_t	combinations;
	size_t	i;

	combinations = exponent(2, n_inputs);
	input_comb = alloc_barr(combinations, n_inputs);
	if (!input_comb)
		return (0);
	while (combinations)
	{
		i = n_inputs;
		while (i)
		{
			input_comb[combinations - 1]->array[i - 1] = ((combinations - 1) >> i) % 2;
			i--;
		}
		combinations--;
	}
	return (input_comb);
}

bool	is_gate(char *s)
{
	char	gates = {"not","or","nor","xor","xnor","and","nand"};
	short	gate;
	short	i;

	gate = 0;
	while (gate < 7)
	{
		i = 0;
		while (s[i] && gates[gate][i] == s[i])
		{
			if (!gates[gate][i])
				return (1);
			i++;
		}
		gate++;
	}
	return (0);
}

bool	in(char c, char *s)
{
	size_t	i;
	char	c_tmp;

	i = 0;
	c_tmp = s[0];
	while (c_tmp && c_tmp != c)
	{
		i++;
		c_tmp = s[i];
	}
	return (c_tmp == c);
}

char	lower(char c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

size_t	count_inputs(char *expression)
{
	size_t	n_inputs;
	size_t	i;
	char	c;

	n_inputs = 0;
	i = 0;
	c = lower(expression[i]);
	while (c)
	{
		if (in(c, "noxa") && is_gate(&c))
			//start of a gate
		i++;
		c = lower(expression[i]);
	}
	return (n_inputs);
}

char	*input_census(char *expression)
{
	char	*input_name;
	size_t	n_inputs;

	n_inputs = count_inputs(expression);
	input_name = malloc((n_input + 1) * sizeof(char *));
	if (!input_name)
		return (NULL);
	input_name[n_input] = NULL;
	while ()
	{
		
	}
	return (input_name);
}



int	main(int argc, char **argv)// n_inputs <= 64
{
	size_t	n_inputs;
	char	*input_name;
	t_barr	**input_comb;

	if (argc != 2)
	{
		write(1, "Error : incorrect number of arguments provided.", 47);
		return (1);
	}
	if (check_syntax(argv[1]))
	{
		write(1, "Error : incorrect syntax.", 24);
		return (1);
	}
	input_name = input_census(argv[1]);
	if (!input_name)
	{
		write(1, "Error : failed memory allocation.", 33);
		return (1);
	}
	n_inputs = count_inputs(argv[1]);
	if (!n_inputs || n_inputs > 64)
	{
		write(1, "Error : invalid number of input bits (< 1 or > 64).", 51);
		return (1);
	}
	input_comb = alloc_barr_inputs(n_inputs);
	if (!input_comb)
	{
		write(1, "Error : failed memory allocation.", 33);
		return (1);
	}
	free_barr(input_comb);
	return (0);
}

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
		while (s[i] && gates[gate][i] == lower(s[i]))
			i++;
		if (!gates[gate][i])
			return (gate);
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
	size_t	count;
	size_t	i;
	char	c;

	count = 0;
	i = 0;
	c = expression[i];
	while (c)
	{
		if (!in(c, " \t\n\v\r\f(),") && !is_gate(&c))
			count++;//deplacer, mais pk pas utiliser listes chainees au final ?
		i++;
		c = expression[i];
	}
	return (count);
}

char	*input_census(char *expression, size_t n_inputs)
{
	char	*input_name;

	input_name = malloc((n_input + 1) * sizeof(char *));
	if (!input_name)
		return (NULL);
	input_name[n_input] = NULL;
	while ()
	{
		
	}
	return (input_name);
}

bool	print_error(short error_code)
{
	char	*errors[4] = {"Error : incorrect number of arguments provided.",
		"Error : incorrect syntax.",
		"Error : invalid number of input bits (< 1 or > 64).",
		"Error : failed memory allocation."}

	write(1, errors[error_code], strlen(errors[error_code]));
	return (1);
}

int	main(int argc, char **argv)// n_inputs <= 64
{
	size_t	n_inputs;
	char	*input_name;
	t_barr	**input_comb;

	if (argc != 2)
		return (print_error(0));
	if (check_syntax(argv[1]))
		return (print_error(1));
	n_inputs = count_input(argv[1]);
	if (!n_inputs || n_input > 64)
		return (print_error(2));
	input_name = input_census(argv[1], n_input);
	if (!input_name)
		return (print_error(3));
	input_comb = alloc_barr_inputs(n_inputs);
	if (!input_comb)
		return (print_error(3));
	free_barr(input_comb);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:05:11 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/13 08:57:08 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_elements(char **split_input)
{
	int		num_elements;
	char	**ptr;

	num_elements = 0;
	ptr = split_input;
	while (*ptr != NULL)
	{
		num_elements++;
		ptr++;
	}
	return (num_elements);
}

int	replace_argv(int argc, int num_elements, char *argv[], char **split_input)
{
	int		i;
	char	**ptr;

	i = 1;
	ptr = split_input;
	while (*ptr != NULL)
	{
		argv[i] = *ptr;
		i++;
		ptr++;
	}
	argc += num_elements - 1;
	return (argc);
}

int	checker(char *argv[], int argc)
{
	char	**split_input;
	int		num_elements;

	if (is_second_format(argc, argv))
	{
		split_input = ft_split(argv[1], ' ');
		num_elements = count_elements(split_input);
		argc = replace_argv(argc, num_elements, argv, split_input);
		return (argc);
	}
	return (-1);
}

int	superchecker(char *argv[], int argc)
{
	int	retour;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	retour = checker(argv, argc);
	if (retour != -1)
		argc = retour;
	if (!is_valid_input(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (retour);
}

void	instantiation(int argc)
{
	g_push_swap.sizea = argc - 1;
	g_push_swap.sizeb = 0;
	g_push_swap.stacka = (int *)malloc(g_push_swap.sizea * sizeof(int)
			* g_push_swap.sizea + 2);
	g_push_swap.stackb = (int *)malloc(g_push_swap.sizea * sizeof(int)
			* g_push_swap.sizea + 2);
}

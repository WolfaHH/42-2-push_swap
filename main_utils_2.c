/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:06:33 by ngodard           #+#    #+#             */
/*   Updated: 2023/05/23 20:19:07 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (false);
	}
	if (*str == '-')
	{
		str++;
	}
	if (*str == '\0')
	{
		return (false);
	}
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (false);
		}
		str++;
	}
	return (true);
}

bool	has_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (strcmp(argv[i], argv[j]) == 0)
			{
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_valid_input(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i]))
		{
			return (false);
		}
		i++;
	}
	if (has_duplicates(argc, argv))
	{
		return (false);
	}
	return (true);
}

bool	is_second_format(int argc, char *argv[])
{
	if (argc == 2 && strchr(argv[1], ' ') != NULL)
	{
		return (true);
	}
	return (false);
}

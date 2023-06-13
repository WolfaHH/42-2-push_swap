/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:06:33 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/13 08:46:17 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_integer(const char *str)
{
	char		*end;
	long long	num;

	if (str == NULL || *str == '\0')
		return (false);
	errno = 0;
	num = ft_strtoll(str, &end);
	if (errno == ERANGE || *end != '\0' || num > INT_MAX || num < INT_MIN)
		return (false);
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '-' && *str != '+')
			return (false);
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
			if (ft_strcmp(argv[i], argv[j]) == 0)
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
	if (argc == 2 && ft_strchr(argv[1], ' ') != NULL)
	{
		return (true);
	}
	return (false);
}

void	norminettedecestmortsadaronnejenaimarredec(void)
{
	swap_a();
	rotate_a();
	swap_a();
	reverse_rotate_a();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_code4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:15:16 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/12 15:50:55 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

int	ttthh(int n, int i)
{
	if (n - i == 2)
	{
		push_a();
		push_a();
		return (1);
	}
	else if (n - i == 1)
	{
		push_a();
		push_a();
		return (1);
	}
	return (0);
}

void	main_algorithm(int n, int i)
{
	int			k[3];
	int			*best_order;
	static int	default_order[] = {0, 1, 2};

	ft_memcpy(best_order, default_order, sizeof(default_order));
	while (n - 1 - i >= 0)
	{
		k[0] = pushSwap.sorted_list[n - 1 - i];
		k[1] = pushSwap.sorted_list[n - 2 - i];
		k[2] = pushSwap.sorted_list[n - 3 - i];
		if (pushSwap.sizeB >= 6)
			best_order = best_combination(k, n - i, pushSwap.sizeB);
		if (ttthh(n, i) == 1)
			break ;
		main_algorithm_1(n, i, best_order);
		i += 3;
		main_algorithm_2();
	}
}

void	push_swap_multi(int n, int nbr, int *stackA, int sizeA)
{
	int	*test;

	test = (int *)malloc(sizeA * sizeof(int) * sizeA + 2);
	ft_memcpy(pushSwap.stackA, stackA, sizeof(int) * sizeA + 2);
	ft_memcpy(pushSwap.stackB, test, sizeof(int) * sizeA + 2);
	pushSwap.sizeA = sizeA;
	pushSwap.sizeB = 0;
	ft_strcpy(pushSwap.result_to_display, "");
	handle_4_chunks_division(n, nbr);
	while (pushSwap.sizeA > 0)
	{
		push_b();
	}
	main_algorithm(n, 0);
	if (pushSwap.stackA[0] > pushSwap.stackA[1])
	{
		swap_a();
	}
	free(test);
}

void	push_swap_big(int n, int *stackA, int sizeA)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = (char *)malloc(999999);
	while (i < 9)
	{
		if (strlen(pushSwap.result_to_display) == 0)
		{
			push_swap_multi(n, i, stackA, sizeA);
			ft_strcpy(tmp, pushSwap.result_to_display);
		}
		else
		{
			push_swap_multi(n, i, stackA, sizeA);
			if (strlen(pushSwap.result_to_display) < strlen(tmp))
			{
				ft_strcpy(tmp, pushSwap.result_to_display);
			}
		}
		i++;
	}
	strcpy(pushSwap.result_to_display, "");
	strcpy(pushSwap.result_to_display, tmp);
	free(tmp);
}

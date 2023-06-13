/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_code2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:15:02 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/12 15:55:49 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk(int n, int nbr, int i)
{
	int	e;
	int	j;

	if (i == 1)
		e = 0;
	else
		e = (n / nbr) * (i - 1);
	if (i == nbr)
		j = n;
	else
		j = (n / nbr) * i;
	while (e < j)
	{
		if (g_push_swap.stacka[0] == g_push_swap.sorted_list[e])
			push_b();
		e++;
	}
}

void	handle_4_chunks_division(int n, int nbr)
{
	int	i;

	i = 1;
	while (i <= nbr)
	{
		while (g_push_swap.sizea > n - ((n / nbr) * i) + 5)
		{
			push_chunk(n, nbr, i);
			rotate_a();
		}
		i++;
	}
}

int	get_k(int n, int i, int best_order_value)
{
	return (k_k(n, i, best_order_value));
}

int	push_and_update_k(int n, int i, int *best_order, int index)
{
	int	k_value;

	push_a();
	k_value = get_k(n, i, (best_order[index] + 1));
	return (k_value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_code3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:15:09 by ngodard           #+#    #+#             */
/*   Updated: 2023/05/24 19:18:31 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rerestack(int euh[2], int *best_order, int x, int p)
{
	int	k;

	k = push_and_update_k(euh[0], euh[1], best_order, x);
	return (k);
}

void	main_algorithm_1(int n, int i, int *best_order)
{
	int	p;
	int	k;
	int	euh[2];

	p = 1;
	k = get_k(n, i, (best_order[0] + 1));
	euh[0] = n;
	euh[1] = i;
	while (p < 4)
	{
		if (pushSwap.stackB[0] == pushSwap.sorted_list[euh[0] - (
					best_order[0] + 1) - euh[1]])
			k = rerestack(euh, best_order, 1, p++);
		else if (pushSwap.stackB[0] == pushSwap.sorted_list[euh[0] - (
					best_order[1] + 1) - euh[1]])
			k = rerestack(euh, best_order, 2, p++);
		else if (pushSwap.stackB[0] == pushSwap.sorted_list[euh[0] - (
					best_order[2] + 1) - euh[1]] && p++)
			push_a();
		else if (k == -1 || k == -3)
			rotate_b();
		else if (k == -2)
			reverse_rotate_b();
	}
}

void	main_algorithm_2_1(void)
{
	swap_a();
	rotate_a();
	swap_a();
	reverse_rotate_a();
	swap_a();
}

void	toubitouba(void)
{
	if (pushSwap.stackA[0] < pushSwap.stackA[1] && pushSwap.stackA[1]
		> pushSwap.stackA[2] && pushSwap.stackA[0] > pushSwap.stackA[2])
	{
		rotate_a();
		swap_a();
		reverse_rotate_a();
		swap_a();
	}
}

void	main_algorithm_2(void)
{
	if (pushSwap.stackA[0] > pushSwap.stackA[1] && pushSwap.stackA[1]
		< pushSwap.stackA[2] && pushSwap.stackA[0] < pushSwap.stackA[2])
		swap_a();
	if (pushSwap.stackA[0] > pushSwap.stackA[1] && pushSwap.stackA[1]
		> pushSwap.stackA[2] && pushSwap.stackA[0] > pushSwap.stackA[2])
		main_algorithm_2_1();
	if (pushSwap.stackA[0] > pushSwap.stackA[1] && pushSwap.stackA[1]
		< pushSwap.stackA[2] && pushSwap.stackA[0] > pushSwap.stackA[2])
	{
		swap_a();
		rotate_a();
		swap_a();
		reverse_rotate_a();
	}
	if (pushSwap.stackA[0] < pushSwap.stackA[1] && pushSwap.stackA[1]
		> pushSwap.stackA[2] && pushSwap.stackA[0] < pushSwap.stackA[2])
	{
		rotate_a();
		swap_a();
		reverse_rotate_a();
	}
	toubitouba();
}

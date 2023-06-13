/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_code1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:14:55 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/12 15:55:49 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(void)
{
	int	i;

	i = 0;
	while (i <= g_push_swap.sizea)
	{
		if (g_push_swap.sorted_list[i] != g_push_swap.stacka[i])
		{
			break ;
		}
		if (i == g_push_swap.sizea)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	handle_case_3_2(void)
{
	if (g_push_swap.stacka[0] < g_push_swap.stacka[1]
		&& g_push_swap.stacka[1] > g_push_swap.stacka[2]
		&& g_push_swap.stacka[0] < g_push_swap.stacka[2])
	{
		swap_a();
		rotate_a();
	}
	else if (g_push_swap.stacka[0] < g_push_swap.stacka[1]
		&& g_push_swap.stacka[1] > g_push_swap.stacka[2]
		&& g_push_swap.stacka[0] > g_push_swap.stacka[2])
	{
		reverse_rotate_a();
	}	
}

void	handle_case_3(void)
{
	if (g_push_swap.stacka[0] > g_push_swap.stacka[1]
		&& g_push_swap.stacka[1] < g_push_swap.stacka[2]
		&& g_push_swap.stacka[0] < g_push_swap.stacka[2])
	{
		swap_a();
	}
	else if (g_push_swap.stacka[0] > g_push_swap.stacka[1]
		&& g_push_swap.stacka[1] > g_push_swap.stacka[2]
		&& g_push_swap.stacka[0] > g_push_swap.stacka[2])
	{
		swap_a();
		reverse_rotate_a();
	}
	else if (g_push_swap.stacka[0] > g_push_swap.stacka[1]
		&& g_push_swap.stacka[1] < g_push_swap.stacka[2]
		&& g_push_swap.stacka[0] > g_push_swap.stacka[2])
	{
		rotate_a();
	}
	else
	{
		handle_case_3_2();
	}
}

void	sort_five_elements(void)
{
	int	i;

	i = 0;
	while (i <= g_push_swap.sizea)
	{
		if (g_push_swap.stacka[0] == g_push_swap.sorted_list[0])
		{
			push_b();
		}
		if (g_push_swap.stacka[0] == g_push_swap.sorted_list[1])
		{
			push_b();
		}
		else
			rotate_a();
		i++;
	}
	handle_case_3();
	push_a();
	push_a();
	if (g_push_swap.stacka[0] > g_push_swap.stacka[1])
	{
		swap_a();
	}
}

void	push_swap_small(int n)
{
	int	i;
	int	j;

	if (n == 5)
	{
		sort_five_elements();
		return ;
	}
	i = 0;
	j = 0;
	while (g_push_swap.sorted_list[j] != g_push_swap.sorted_list[n - 1])
	{
		if (g_push_swap.sorted_list[j] == g_push_swap.stacka[0])
		{
			push_b();
			j++;
		}
		else
			rotate_a();
	}
	while (i < n)
	{
		push_a();
		i++;
	}
}

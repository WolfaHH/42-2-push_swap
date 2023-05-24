/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_code1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:14:55 by ngodard           #+#    #+#             */
/*   Updated: 2023/05/23 19:53:58 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(void)
{
	int	i;

	i = 0;
	while (i <= pushSwap.sizeA)
	{
		if (pushSwap.sorted_list[i] != pushSwap.stackA[i])
		{
			break ;
		}
		if (i == pushSwap.sizeA)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	handle_case_3_2(void)
{
	if (pushSwap.stackA[0] < pushSwap.stackA[1]
		&& pushSwap.stackA[1] > pushSwap.stackA[2]
		&& pushSwap.stackA[0] < pushSwap.stackA[2])
	{
		swap_a();
		rotate_a();
	}
	else if (pushSwap.stackA[0] < pushSwap.stackA[1]
		&& pushSwap.stackA[1] > pushSwap.stackA[2]
		&& pushSwap.stackA[0] > pushSwap.stackA[2])
	{
		reverse_rotate_a();
	}	
}

void	handle_case_3(void)
{
	if (pushSwap.stackA[0] > pushSwap.stackA[1]
		&& pushSwap.stackA[1] < pushSwap.stackA[2]
		&& pushSwap.stackA[0] < pushSwap.stackA[2])
	{
		swap_a();
	}
	else if (pushSwap.stackA[0] > pushSwap.stackA[1]
		&& pushSwap.stackA[1] > pushSwap.stackA[2]
		&& pushSwap.stackA[0] > pushSwap.stackA[2])
	{
		swap_a();
		reverse_rotate_a();
	}
	else if (pushSwap.stackA[0] > pushSwap.stackA[1]
		&& pushSwap.stackA[1] < pushSwap.stackA[2]
		&& pushSwap.stackA[0] > pushSwap.stackA[2])
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
	while (i <= pushSwap.sizeA)
	{
		if (pushSwap.stackA[0] == pushSwap.sorted_list[0])
		{
			push_b();
		}
		if (pushSwap.stackA[0] == pushSwap.sorted_list[1])
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
	if (pushSwap.stackA[0] > pushSwap.stackA[1])
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
	while (pushSwap.sorted_list[j] != pushSwap.sorted_list[n - 1])
	{
		if (pushSwap.sorted_list[j] == pushSwap.stackA[0])
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

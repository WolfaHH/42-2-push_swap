/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:31:20 by ngodard           #+#    #+#             */
/*   Updated: 2023/05/23 19:38:41 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(void)
{
	int	i;

	if (pushSwap.sizeB > 0)
	{
		i = 0;
		while (i < pushSwap.sizeA)
		{
			pushSwap.stackA[pushSwap.sizeA - i] = pushSwap.stackA
			[pushSwap.sizeA - 1 - i];
			i++;
		}
		pushSwap.stackA[0] = pushSwap.stackB[0];
		pushSwap.sizeB -= 1;
		pushSwap.sizeA += 1;
		i = 0;
		while (i < pushSwap.sizeB)
		{
			pushSwap.stackB[i] = pushSwap.stackB[i + 1];
			i++;
		}
		ft_strcat(pushSwap.result_to_display, "pa\n");
	}
}

void	push_b(void)
{
	int	i;

	if (pushSwap.sizeA > 0)
	{
		i = 0;
		while (i < pushSwap.sizeB)
		{
			pushSwap.stackB[pushSwap.sizeB - i] = pushSwap.stackB
			[pushSwap.sizeB - 1 - i];
			i++;
		}
		pushSwap.stackB[0] = pushSwap.stackA[0];
		pushSwap.sizeA -= 1;
		pushSwap.sizeB += 1;
		i = 0;
		while (i < pushSwap.sizeA)
		{
			pushSwap.stackA[i] = pushSwap.stackA[i + 1];
			i++;
		}
		ft_strcat(pushSwap.result_to_display, "pb\n");
	}
}

int	k_k(int n, int i, int e)
{
	int	k;
	int	target_index;

	k = 0;
	target_index = -1;
	while (k < n)
	{
		if (pushSwap.sorted_list[n - e - i] == pushSwap.stackB[k])
		{
			target_index = k;
			break ;
		}
		k++;
	}
	if (target_index == -1)
		return (-3);
	if (target_index <= (n - i) / 2)
		return (-1);
	else
		return (-2);
}

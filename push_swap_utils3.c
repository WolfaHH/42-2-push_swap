/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:44:48 by ngodard           #+#    #+#             */
/*   Updated: 2023/05/23 19:53:58 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(void)
{
	int	temp;
	int	i;

	temp = pushSwap.stackB[0];
	i = 0;
	while (i < pushSwap.sizeB - 1)
	{
		pushSwap.stackB[i] = pushSwap.stackB[i + 1];
		i++;
	}
	pushSwap.stackB[pushSwap.sizeB - 1] = temp;
	ft_strcat(pushSwap.result_to_display, "rb\n");
}

void	rotate_both(void)
{
	rotate_a();
	rotate_b();
	ft_strcat(pushSwap.result_to_display, "rr\n");
}

void	reverse_rotate_a(void)
{
	int	temp;
	int	i;

	temp = pushSwap.stackA[pushSwap.sizeA - 1];
	i = pushSwap.sizeA - 1;
	while (i > 0)
	{
		pushSwap.stackA[i] = pushSwap.stackA[i - 1];
		i--;
	}
	pushSwap.stackA[0] = temp;
	ft_strcat(pushSwap.result_to_display, "rra\n");
}

void	reverse_rotate_b(void)
{
	int	temp;
	int	i;

	temp = pushSwap.stackB[pushSwap.sizeB - 1];
	i = pushSwap.sizeB - 1;
	while (i > 0)
	{
		pushSwap.stackB[i] = pushSwap.stackB[i - 1];
		i--;
	}
	pushSwap.stackB[0] = temp;
	ft_strcat(pushSwap.result_to_display, "rrb\n");
}

void	reverse_rotate_both(void)
{
	reverse_rotate_a();
	reverse_rotate_b();
	ft_strcat(pushSwap.result_to_display, "rrr\n");
}

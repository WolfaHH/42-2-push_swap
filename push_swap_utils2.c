/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:44:35 by ngodard           #+#    #+#             */
/*   Updated: 2023/05/23 19:54:07 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strcat(char *dest, const char *src)
{
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

void	swap_a(void)
{
	int	temp;

	temp = pushSwap.stackA[0];
	pushSwap.stackA[0] = pushSwap.stackA[1];
	pushSwap.stackA[1] = temp;
	ft_strcat(pushSwap.result_to_display, "sa\n");
}

void	swap_b(void)
{
	int	temp;

	temp = pushSwap.stackB[0];
	pushSwap.stackB[0] = pushSwap.stackB[1];
	pushSwap.stackB[1] = temp;
	ft_strcat(pushSwap.result_to_display, "sb\n");
}

void	swap_both(void)
{
	swap_a();
	swap_b();
	ft_strcat(pushSwap.result_to_display, "ss\n");
}

void	rotate_a(void)
{
	int	temp;
	int	i;

	temp = pushSwap.stackA[0];
	i = 0;
	while (i < pushSwap.sizeA - 1)
	{
		pushSwap.stackA[i] = pushSwap.stackA[i + 1];
		i++;
	}
	pushSwap.stackA[pushSwap.sizeA - 1] = temp;
	ft_strcat(pushSwap.result_to_display, "ra\n");
}

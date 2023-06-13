/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:44:35 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/12 15:55:54 by ngodard          ###   ########.fr       */
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

	temp = g_push_swap.stacka[0];
	g_push_swap.stacka[0] = g_push_swap.stacka[1];
	g_push_swap.stacka[1] = temp;
	ft_strcat(g_push_swap.result_to_display, "sa\n");
}

void	swap_b(void)
{
	int	temp;

	temp = g_push_swap.stackb[0];
	g_push_swap.stackb[0] = g_push_swap.stackb[1];
	g_push_swap.stackb[1] = temp;
	ft_strcat(g_push_swap.result_to_display, "sb\n");
}

void	swap_both(void)
{
	swap_a();
	swap_b();
	ft_strcat(g_push_swap.result_to_display, "ss\n");
}

void	rotate_a(void)
{
	int	temp;
	int	i;

	temp = g_push_swap.stacka[0];
	i = 0;
	while (i < g_push_swap.sizea - 1)
	{
		g_push_swap.stacka[i] = g_push_swap.stacka[i + 1];
		i++;
	}
	g_push_swap.stacka[g_push_swap.sizea - 1] = temp;
	ft_strcat(g_push_swap.result_to_display, "ra\n");
}

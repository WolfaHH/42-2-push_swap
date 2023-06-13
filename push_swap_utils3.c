/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:44:48 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/12 15:55:54 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(void)
{
	int	temp;
	int	i;

	temp = g_push_swap.stackb[0];
	i = 0;
	while (i < g_push_swap.sizeb - 1)
	{
		g_push_swap.stackb[i] = g_push_swap.stackb[i + 1];
		i++;
	}
	g_push_swap.stackb[g_push_swap.sizeb - 1] = temp;
	ft_strcat(g_push_swap.result_to_display, "rb\n");
}

void	rotate_both(void)
{
	rotate_a();
	rotate_b();
	ft_strcat(g_push_swap.result_to_display, "rr\n");
}

void	reverse_rotate_a(void)
{
	int	temp;
	int	i;

	temp = g_push_swap.stacka[g_push_swap.sizea - 1];
	i = g_push_swap.sizea - 1;
	while (i > 0)
	{
		g_push_swap.stacka[i] = g_push_swap.stacka[i - 1];
		i--;
	}
	g_push_swap.stacka[0] = temp;
	ft_strcat(g_push_swap.result_to_display, "rra\n");
}

void	reverse_rotate_b(void)
{
	int	temp;
	int	i;

	temp = g_push_swap.stackb[g_push_swap.sizeb - 1];
	i = g_push_swap.sizeb - 1;
	while (i > 0)
	{
		g_push_swap.stackb[i] = g_push_swap.stackb[i - 1];
		i--;
	}
	g_push_swap.stackb[0] = temp;
	ft_strcat(g_push_swap.result_to_display, "rrb\n");
}

void	reverse_rotate_both(void)
{
	reverse_rotate_a();
	reverse_rotate_b();
	ft_strcat(g_push_swap.result_to_display, "rrr\n");
}

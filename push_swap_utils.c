/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:31:20 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/12 15:55:54 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(void)
{
	int	i;

	if (g_push_swap.sizeb > 0)
	{
		i = 0;
		while (i < g_push_swap.sizea)
		{
			g_push_swap.stacka[g_push_swap.sizea - i] = g_push_swap.stacka
			[g_push_swap.sizea - 1 - i];
			i++;
		}
		g_push_swap.stacka[0] = g_push_swap.stackb[0];
		g_push_swap.sizeb -= 1;
		g_push_swap.sizea += 1;
		i = 0;
		while (i < g_push_swap.sizeb)
		{
			g_push_swap.stackb[i] = g_push_swap.stackb[i + 1];
			i++;
		}
		ft_strcat(g_push_swap.result_to_display, "pa\n");
	}
}

void	push_b(void)
{
	int	i;

	if (g_push_swap.sizea > 0)
	{
		i = 0;
		while (i < g_push_swap.sizeb)
		{
			g_push_swap.stackb[g_push_swap.sizeb - i] = g_push_swap.stackb
			[g_push_swap.sizeb - 1 - i];
			i++;
		}
		g_push_swap.stackb[0] = g_push_swap.stacka[0];
		g_push_swap.sizea -= 1;
		g_push_swap.sizeb += 1;
		i = 0;
		while (i < g_push_swap.sizea)
		{
			g_push_swap.stacka[i] = g_push_swap.stacka[i + 1];
			i++;
		}
		ft_strcat(g_push_swap.result_to_display, "pb\n");
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
		if (g_push_swap.sorted_list[n - e - i] == g_push_swap.stackb[k])
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

char	*ft_strcpy(char *destination, const char *source)
{
	char	*dest;

	dest = destination;
	if (destination == NULL || source == NULL)
	{
		return (NULL);
	}
	while (*source)
	{
		*dest++ = *source++;
	}
	*dest = '\0';
	return (destination);
}

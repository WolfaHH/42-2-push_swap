/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_combinations2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:12:56 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/09 17:33:37 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_stack(int *stackK, int *sizeK)
{
	int	i;

	i = 0;
	while (i < *sizeK)
	{
		stackK[i] = pushSwap.stackB[i];
		i++;
	}
}

int	pepe(int *stackK, int *sizeK, int *arg)
{
	int	k;

	k = k_k_k(stackK, arg[3], arg[0], sizeK);
	while (arg[7] < 3)
	{
		if (stackK[0] == arg[4] && arg[7] == 0 && arg[7]++)
			k = k_k_k(stackK, arg[3], arg[1], sizeK);
		if (stackK[0] == arg[5] && arg[7] == 1 && arg[7]++)
			k = k_k_k(stackK, arg[3], arg[2], sizeK);
		if (stackK[0] == arg[6] && arg[7] == 2)
			arg[7]++;
		if (k == -2 && arg[8]--)
			reverse_rotate_k(stackK, sizeK);
		if (k == -1 && arg[8]++)
			rotate_k(stackK, sizeK);
		if (k == -3)
			break ;
		arg[9]++;
	}
	while (arg[8] < 0 && arg[8]++)
		rotate_k(stackK, sizeK);
	while (arg[8] > 0 && arg[8]--)
		reverse_rotate_k(stackK, sizeK);
	return (arg[9]);
}

// Top number goes to bottom of Stack K
void	rotate_k(int *stackB, int *sizeB)
{
	int	temp;
	int	i;

	i = 0;
	temp = stackB[0];
	while (i < *sizeB - 1)
	{
		stackB[i] = stackB[i + 1];
		i++;
	}
	stackB[*sizeB - 1] = temp;
}

void	reverse_rotate_k(int *stackB, int *sizeB)
{
	int	temp;
	int	i;

	temp = stackB[*sizeB - 1];
	i = *sizeB - 1;
	while (i > 0)
	{
		stackB[i] = stackB[i - 1];
		i--;
	}
	stackB[0] = temp;
}

int	k_k_k(int *stackK, int n, int e, int *sizeB)
{
	int	k;
	int	target_index;
	int	i;

	i = 1;
	k = 0;
	target_index = -1;
	while (k < n)
	{
		if (pushSwap.sorted_list[n - e - i] == stackK[k])
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

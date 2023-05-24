/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:54:35 by ngodard           #+#    #+#             */
/*   Updated: 2023/05/23 20:18:57 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap two elements in the list
void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

// Partition function
int	partition(int *list, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = list[end];
	i = (start - 1);
	j = start;
	while (j <= end - 1)
	{
		if (list[j] < pivot)
		{
			i++;
			swap(&list[i], &list[j]);
		}
		j++;
	}
	swap(&list[i + 1], &list[end]);
	return (i + 1);
}

// QuickSort function
void	merge_sort(int *list, int start, int end)
{
	int	pi;

	if (start < end)
	{
		pi = partition(list, start, end);
		merge_sort(list, start, pi - 1);
		merge_sort(list, pi + 1, end);
	}
}

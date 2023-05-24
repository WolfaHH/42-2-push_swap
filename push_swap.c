/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:10:00 by ngodard           #+#    #+#             */
/*   Updated: 2023/05/23 19:53:31 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int *stackA, int sizeA)
{
	int	i;
	int	e;
	int	n;

	i = 0;
	n = pushSwap.sizeA;
	if (check_sorted() == 0)
		return (0);
	if (n <= 10)
	{
		if (n == 2)
			swap_a();
		else if (n == 3)
			handle_case_3();
		else
			push_swap_small(n);
	}
	else if (n > 10)
		push_swap_big(n, stackA, sizeA);
	return (0);
}

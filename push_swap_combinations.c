/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_combinations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:46:26 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/12 15:09:09 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_order(int index, int permutations[6][3])
{
	int	i;

	i = permutations[index][0];
	g_order[0] = i;
	i = permutations[index][1];
	g_order[1] = i;
	i = permutations[index][2];
	g_order[2] = i;
}

void	useperm(int permutations[6][3])
{
	permutations[0][0] = 0;
	permutations[0][1] = 1;
	permutations[0][2] = 2;
	permutations[1][0] = 0;
	permutations[1][1] = 2;
	permutations[1][2] = 1;
	permutations[2][0] = 1;
	permutations[2][1] = 0;
	permutations[2][2] = 2;
	permutations[3][0] = 1;
	permutations[3][1] = 2;
	permutations[3][2] = 0;
	permutations[4][0] = 2;
	permutations[4][1] = 0;
	permutations[4][2] = 1;
	permutations[5][0] = 2;
	permutations[5][1] = 1;
	permutations[5][2] = 0;
}

int	check_distance(int *stackK, int *k, int *sizeK, int *aarg)
{
	int	t;
	int	permutations[6][3];
	int	*arg;

	useperm(permutations);
	arg = malloc(sizeof(int) * 10);
	arg[0] = permutations[aarg[2]][0];
	arg[1] = permutations[aarg[2]][1];
	arg[2] = permutations[aarg[2]][2];
	arg[3] = aarg[0];
	arg[4] = k[permutations[aarg[2]][0]];
	arg[5] = k[permutations[aarg[2]][1]];
	arg[6] = k[permutations[aarg[2]][2]];
	arg[7] = 0;
	arg[8] = 0;
	arg[9] = 0;
	t = pepe(stackK, sizeK, arg);
	if (t < aarg[1])
	{
		aarg[1] = t;
		assign_order(aarg[2], permutations);
	}
	free(arg);
	return (aarg[1]);
}

void	calculate_order(int *stackK, int *k, int *sizeK, int n)
{
	int	distance;
	int	t;
	int	i;
	int	*aarg;

	aarg = malloc(sizeof(int) * 100);
	distance = 90000;
	i = 0;
	aarg[0] = n;
	aarg[1] = distance;
	aarg[2] = i;
	while (aarg[2] < 6)
	{
		aarg[1] = check_distance(stackK, k, sizeK, aarg);
		aarg[2]++;
	}
	free (aarg);
}

int	*best_combination(int k[3], int n, int size)
{
	int	*stackk;
	int	sizek;

	sizek = size;
	stackk = malloc(900000);
	copy_stack(stackk, &sizek);
	calculate_order(stackk, k, &sizek, n);
	free(stackk);
	return (g_order);
}

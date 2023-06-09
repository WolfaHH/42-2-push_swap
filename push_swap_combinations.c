/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_combinations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:46:26 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/09 15:01:52 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int g_order[3];

void copy_stack(int *stackK, int *sizeK) {
    for(int i = 0; i < *sizeK; i++)
        stackK[i] = pushSwap.stackB[i];
}


// Function to assign order
void assign_order(int index, int	permutations[6][3]) {
    int i;
    i = permutations[index][0];
    g_order[0] = i;
    i = permutations[index][1];
    g_order[1] = i;
    i = permutations[index][2];
    g_order[2] = i;
}

void useperm(int	permutations[6][3])
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

// Function to check distance
int check_distance(int *stackK, int *k, int *sizeK, int * aarg) {
    int t;
	int	permutations[6][3];
	int *arg;

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
    if (t < aarg[1]) {
        aarg[1] = t;
        assign_order(aarg[2], permutations);
    }
    return aarg[1];
}

void calculate_order(int *stackK, int *k, int *sizeK, int n) {
    int distance;
	int t;
	int i;
	int *aarg;

	aarg = malloc(sizeof(int) * 10);
    distance = 90000;
    i = 0;
	aarg[0] = n;
	aarg[1] = distance;
	aarg[2] = i;
    while (aarg[2] < 6) {
        aarg[1] = check_distance(stackK, k, sizeK, aarg);
        aarg[2]++;
    }
}

int *best_combination(int k[3], int n, int size) {
    int *stackK = malloc(9000000);
    int sizeK = size;

    copy_stack(stackK, &sizeK);
    calculate_order(stackK, k, &sizeK, n);
    free(stackK);
    return g_order;
}

int pepe(int *stackK, int *sizeK, int *arg)
{
	int k;

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
			reverse_rotate_K(stackK, sizeK);
		if (k == -1 && arg[8]++)
			rotate_K(stackK, sizeK);
		if (k == -3)
			break;
		arg[9]++;
	}
	while (arg[8] < 0 && arg[8]++)
		rotate_K(stackK, sizeK);

	while (arg[8] > 0 && arg[8]--)
		reverse_rotate_K(stackK, sizeK);
	return arg[9];
}

// Top number goes to bottom of Stack K
void rotate_K(int *stackB, int *sizeB)
{
	int temp = stackB[0];
	for (int i = 0; i < *sizeB - 1; i++)
	{
		stackB[i] = stackB[i + 1];
	}
	stackB[*sizeB - 1] = temp;
}
// bottom number goes to top of Stack K
void reverse_rotate_K(int *stackB, int *sizeB)
{
	int temp = stackB[*sizeB - 1];
	for (int i = *sizeB - 1; i > 0; i--)
	{
		stackB[i] = stackB[i - 1];
	}
	stackB[0] = temp;
}

int k_k_k(int *stackK, int n, int e, int *sizeB)
{
	int k;
	int target_index;
	int i;
	
	i = 1;
	k = 0;
	target_index = -1;
	while (k < n)
	{
		if (pushSwap.sorted_list[n - e - i] == stackK[k])
		{
			target_index = k;
			break;
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

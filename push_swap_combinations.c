/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_combinations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:46:26 by ngodard           #+#    #+#             */
/*   Updated: 2023/05/24 22:12:35 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int order[3];

void copy_stack(int *stackK, int *sizeK) {
    for(int i = 0; i < *sizeK; i++)
        stackK[i] = pushSwap.stackB[i];
}

void calculate_order(int *stackK, int *k, int *sizeK, int n) {
    int distance = 90000, t;
    int permutations[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    for(int i = 0; i < 6; i++) {
        t = pepe(stackK, k[permutations[i][0]], k[permutations[i][1]], k[permutations[i][2]], sizeK, n, permutations[i][0], permutations[i][1], permutations[i][2]);
        if(t < distance) {
            distance = t;
            order[0] = permutations[i][0];
            order[1] = permutations[i][1];
            order[2] = permutations[i][2];
        }
    }
}

int *best_combination(int k[3], int n, int size) {
    int *stackK = malloc(9000000);
    int sizeK = size;

    copy_stack(stackK, &sizeK);
    calculate_order(stackK, k, &sizeK, n);
    free(stackK);
    return order;
}

int pepe(int *stackK, int k1, int k2, int k3, int *sizeK, int n, int e1, int e2, int e3)
{
	int p = 0;
	int d = 0;
	int k = k_k_k(stackK, pushSwap.sorted_list, n, 1, e1, sizeK);
	int b = 0;

	while (p < 3)
	{
		if (stackK[0] == k1 && p == 0 && p++)
			k = k_k_k(stackK, pushSwap.sorted_list, n, 1, e2, sizeK);
		if (stackK[0] == k2 && p == 1 && p++)
			k = k_k_k(stackK, pushSwap.sorted_list, n, 1, e3, sizeK);
		if (stackK[0] == k3 && p == 2)
			p++;
		if (k == -2 && b--)
			reverse_rotate_K(stackK, sizeK);
		if (k == -1 && b++)
			rotate_K(stackK, sizeK);
		if (k == -3)
			break;
		d++;
	}
	while (b < 0 && b++)
		rotate_K(stackK, sizeK);

	while (b > 0 && b--)
		reverse_rotate_K(stackK, sizeK);
	return d;
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

int k_k_k(int *stackK, int *sorted_list, int n, int i, int e, int *sizeB)
{
	int k;
	int target_index;

	k = 0;
	target_index = -1;
	while (k < n)
	{
		if (sorted_list[n - e - i] == stackK[k])
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

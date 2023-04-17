/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:10:00 by ngodard           #+#    #+#             */
/*   Updated: 2023/04/17 22:36:48 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(void)
{
	int	i;

	i = 0;
	while (i <= pushSwap.sizeA)
	{
		if (pushSwap.sorted_list[i] != pushSwap.stackA[i])
		{
			break ;
		}
		if (i == pushSwap.sizeA)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	handle_case_3_2(void)
{
	if (pushSwap.stackA[0] < pushSwap.stackA[1]
		&& pushSwap.stackA[1] > pushSwap.stackA[2]
		&& pushSwap.stackA[0] < pushSwap.stackA[2])
	{
		swap_A();
		rotate_A();
	}
	else if (pushSwap.stackA[0] < pushSwap.stackA[1]
		&& pushSwap.stackA[1] > pushSwap.stackA[2]
		&& pushSwap.stackA[0] > pushSwap.stackA[2])
	{
		reverse_rotate_A();
	}	
}

void	handle_case_3(void)
{
	if (pushSwap.stackA[0] > pushSwap.stackA[1]
		&& pushSwap.stackA[1] < pushSwap.stackA[2]
		&& pushSwap.stackA[0] < pushSwap.stackA[2])
	{
		swap_A();
	}
	else if (pushSwap.stackA[0] > pushSwap.stackA[1]
		&& pushSwap.stackA[1] > pushSwap.stackA[2]
		&& pushSwap.stackA[0] > pushSwap.stackA[2])
	{
		swap_A();
		reverse_rotate_A();
	}
	else if (pushSwap.stackA[0] > pushSwap.stackA[1]
		&& pushSwap.stackA[1] < pushSwap.stackA[2]
		&& pushSwap.stackA[0] > pushSwap.stackA[2])
	{
		rotate_A();
	}
	else
	{
		handle_case_3_2();
	}
}

void	sort_five_elements(void)
{
	int	i;

	i = 0;
	while (i <= pushSwap.sizeA)
	{
		if (pushSwap.stackA[0] == pushSwap.sorted_list[0])
		{
			push_B();
		}
		if (pushSwap.stackA[0] == pushSwap.sorted_list[1])
		{
			push_B();
		}
		else
			rotate_A();
		i++;
	}
	handle_case_3();
	push_A();
	push_A();
	if (pushSwap.stackA[0] > pushSwap.stackA[1])
	{
		swap_A();
	}
}

void	push_swap_small(int n)
{
	int	i;
	int	j;

	if (n == 5)
	{
		sort_five_elements();
		return ;
	}
	i = 0;
	j = 0;
	while (pushSwap.sorted_list[j] != pushSwap.sorted_list[n - 1])
	{
		if (pushSwap.sorted_list[j] == pushSwap.stackA[0])
		{
			push_B();
			j++;
		}
		else
			rotate_A();
	}
	while (i < n)
	{
		push_A();
		i++;
	}
}

void	push_chunk(int n, int nbr, int i)
{
	int	e;
	int	j;

	if (i == 1)
		e = 0;
	else
		e = (n / nbr) * (i - 1);
	if (i == nbr)
		j = n;
	else
		j = (n / nbr) * i;
	while (e < j)
	{
		if (pushSwap.stackA[0] == pushSwap.sorted_list[e])
			push_B();
		e++;
	}
}

void	handle_4_chunks_division(int n, int nbr)
{
	int	i;

	i = 1;
	while (i <= nbr)
	{
		while (pushSwap.sizeA > n - ((n / nbr) * i) + 5)
		{
			push_chunk(n, nbr, i);
			rotate_A();
		}
		i++;
	}
}

int get_k(int n, int i, int best_order_value)
{
	return (k_k(n, i, best_order_value));
}

int push_and_update_k(int n, int i, int *best_order, int index)
{
	push_A();
	int k_value = get_k(n, i, (best_order[index] + 1));
	return k_value;
}

void main_algorithm_1(int n, int i, int *best_order)
{
	int p = 1;
	int k;
	k = get_k(n, i, (best_order[0] + 1));

	while (p < 4)
	{
		if (pushSwap.stackB[0] == pushSwap.sorted_list[n - (best_order[0] + 1) - i])
		{
			k = push_and_update_k(n, i, best_order, 1);
			p++;
		}
		else if (pushSwap.stackB[0] == pushSwap.sorted_list[n - (best_order[1] + 1) - i])
		{
			k = push_and_update_k(n, i, best_order, 2);
			p++;
		}
		else if (pushSwap.stackB[0] == pushSwap.sorted_list[n - (best_order[2] + 1) - i])
		{
			push_A();
			p++;
		}

		else if (k == -1)
			rotate_B();
		else if (k == -2)
			reverse_rotate_B();
		else if (k == -3)
			rotate_B();
	}
}
void main_algorithm_2_1()
{
	swap_A();
	rotate_A();
	swap_A();
	reverse_rotate_A();
	swap_A();
}
void main_algorithm_2()
{
	// On trie dans stack A les 3 nombres push
	if (pushSwap.stackA[0] > pushSwap.stackA[1] && pushSwap.stackA[1] < pushSwap.stackA[2] && pushSwap.stackA[0] < pushSwap.stackA[2]) // case1 : [2,1,3]->sa->[1,2,3].
		swap_A();
	if (pushSwap.stackA[0] > pushSwap.stackA[1] && pushSwap.stackA[1] > pushSwap.stackA[2] && pushSwap.stackA[0] > pushSwap.stackA[2]) // case2 : [3,2,1]->sa->[2,3,1]->ra->[3,1,2]->sa->[1,3,2]->rra->[2,1,3]->sa->[1,2,3].
		main_algorithm_2_1();
	if (pushSwap.stackA[0] > pushSwap.stackA[1] && pushSwap.stackA[1] < pushSwap.stackA[2] && pushSwap.stackA[0] > pushSwap.stackA[2]) // case3: [3,1,2]->sa->[1,3,2]->ra->[3,2,1]->sa->[2,3,1]->rra->[1,2,3].
	{
		swap_A();
		rotate_A();
		swap_A();
		reverse_rotate_A();
	}
	if (pushSwap.stackA[0] < pushSwap.stackA[1] && pushSwap.stackA[1] > pushSwap.stackA[2] && pushSwap.stackA[0] < pushSwap.stackA[2]) // case4 : [1,3,2]->ra->[3,2,1]->sa->[2,3,1]->rra->[1,2,3].
	{
		rotate_A();
		swap_A();
		reverse_rotate_A();
	}
	if (pushSwap.stackA[0] < pushSwap.stackA[1] && pushSwap.stackA[1] > pushSwap.stackA[2] && pushSwap.stackA[0] > pushSwap.stackA[2]) // case5 : [2,3,1]->ra->[3,1,2]->sa->[1,3,2]->rra->[2,1,3]->sa->[1,2,3].
	{
		rotate_A();
		swap_A();
		reverse_rotate_A();
		swap_A();
	}
}
int len(const char *str) {
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}
void main_algorithm(int n)
{
	// On ramène sur A le plus grand nombre au plus petit nombre. On cherche par chunk avec RB,RRB et PA
	int i = 0;
	int k1;
	int k2;
	int k3;
	int *best_order = malloc(sizeof(int) * 3);
	static int default_order[] = {0, 1, 2};

	best_order = default_order;
	while (n - 1 - i >= 0)
	{
		//printf("number of instructions %f\n", strlen(pushSwap.result_to_display) / 3.1);

		k1 = pushSwap.sorted_list[n - 1 - i];
		k2 = pushSwap.sorted_list[n - 2 - i];
		k3 = pushSwap.sorted_list[n - 3 - i];
		best_order = best_combination(k1, k2, k3, n - i, pushSwap.sizeB);

		if (n - i >= 3) 
		{
			/*
			if (i == 0)
			{
				printf("k1 = %d, k2 = %d, k3 = %d\n", k1, k2, k3);
				// print the stackB list
				printf("stackB: ");
				for (int i = 0; i < pushSwap.sizeB; i++) {
					printf("%d ", pushSwap.stackB[i]);
				}
				printf("\n");
				printf("\n");
				printf("bestorder = %d, %d, %d\n", best_order[0], best_order[1], best_order[2]);
			}
			best_order = best_combination(k1, k2, k3, n - i, pushSwap.sizeB);*/

		}
		else 
		{
			best_order = default_order;
		}
		if (n - i == 2)
		{
			push_A();
			push_A();
			break;
		}
		else if (n - i == 1)
		{
			push_A();
			push_A();
			break;
		}
		main_algorithm_1(n, i, best_order);
		i += 3;
		main_algorithm_2();
	}
}
void push_swap_multi(int n, int nbr, int *stackA, int sizeA)
{
	int *test;
	test = (int *)malloc(sizeA * sizeof(int) * sizeA + 2);
	memcpy(pushSwap.stackA, stackA, sizeof(int) * sizeA + 2);
	memcpy(pushSwap.stackB, test, sizeof(int) * sizeA + 2);
	pushSwap.sizeA = sizeA;
	pushSwap.sizeB = 0;
	pushSwap.result_to_display = (char *)malloc(99999999);
	strcpy(pushSwap.result_to_display, "");

	handle_4_chunks_division(n, nbr);

	while (pushSwap.sizeA > 0)
	{
		push_B();
	}
	main_algorithm(n);	
	// check if the first element of stackA is smaller than the second, if not, swap
	if (pushSwap.stackA[0] > pushSwap.stackA[1])
	{
		swap_A();
	}
}
void push_swap_big(int n, int *stackA,  int sizeA)
{
	int i = 1;
	char *tmp;

	// Allocate memory for the strings
	tmp = (char *)malloc(99999999);
	while (i < 9)
	{
		if (strlen(pushSwap.result_to_display) == 0)
		{
			push_swap_multi(n, i, stackA, sizeA);
			strcpy(tmp, pushSwap.result_to_display);
		}
		else
		{
			push_swap_multi(n, i, stackA, sizeA);
			if (strlen(pushSwap.result_to_display) < strlen(tmp))
			{
				strcpy(tmp, pushSwap.result_to_display);
			}
		}
		i++;
	}
	strcpy(pushSwap.result_to_display, "");
	strcpy(pushSwap.result_to_display, tmp);



	// Free the memory
	free(tmp);
}
int push_swap(int *stackA, int sizeA)
{
	int i = 0;
	int e;
	int n = pushSwap.sizeA;
	// Check si trié dont Cas ou n=1
	if (check_sorted() == 0)
		return 0;
	if (n <= 10) // Cas ou n <= 10
	{
		
		if (n == 2) // Cas ou n=2; swap 1 time if needed
			swap_A();
		else if (n == 3) // Cas ou n=3; 5 combinaisons possibles
			handle_case_3();
		else // Autres cas; tri par selection, on ramène le plus petit nb par le haut ou le bas selon la distance
			push_swap_small(n);
	}
	else if (n > 10) // Cas ou n > 10
		push_swap_big(n, stackA, sizeA);
	return 0;
}
// write me an algorithm that is printing alphabet




# include "push_swap.h"

/////// CASES INFERIEUR A 10 ///////
int check_sorted()
{
	int i = 0;
	while (i <= pushSwap.sizeA)
	{
		if (pushSwap.sorted_list[i] != pushSwap.stackA[i])
		{
			break;
		}
		if (i == pushSwap.sizeA)
		{
			return 0;
		}
		i++;
	}
	return 1;
}

void handle_case_3()
{
	if (pushSwap.stackA[0] > pushSwap.stackA[1] && pushSwap.stackA[1] < pushSwap.stackA[2] && pushSwap.stackA[0] < pushSwap.stackA[2])
	{ // case1 : [2,1,3]->sa->[1,2,3].
		swap_A();
	}
	else if (pushSwap.stackA[0] > pushSwap.stackA[1] && pushSwap.stackA[1] > pushSwap.stackA[2] && pushSwap.stackA[0] > pushSwap.stackA[2])
	{ // case2 : [3,2,1]->sa->[2,3,1]->rra->[1,2,3].
		swap_A();
		reverse_rotate_A();
	}
	else if (pushSwap.stackA[0] > pushSwap.stackA[1] && pushSwap.stackA[1] < pushSwap.stackA[2] && pushSwap.stackA[0] > pushSwap.stackA[2])
	{ // case3: [3,1,2]->ra->[1,2,3].
		rotate_A();
	}
	else if (pushSwap.stackA[0] < pushSwap.stackA[1] && pushSwap.stackA[1] > pushSwap.stackA[2] && pushSwap.stackA[0] < pushSwap.stackA[2])
	{ // case4 : [1,3,2]->sa->[3,1,2]->ra->[1,2,3].
		swap_A();
		rotate_A();
	}
	else if (pushSwap.stackA[0] < pushSwap.stackA[1] && pushSwap.stackA[1] > pushSwap.stackA[2] && pushSwap.stackA[0] > pushSwap.stackA[2])
	{ // case5 : [2,3,1]->rra->[1,2,3].
		reverse_rotate_A();
	}
}
void push_swap_small(int n)
{
	int i = 0;
	int j = 0;
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
////////////////////////////////////////////////
/////// CASES SUPERIEUR A 10 ///////
void push_chunk(int n, int nbr, int i)
{
	int e, j;

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

void handle_4_chunks_division(int n, int nbr)
{
	int i = 1;

	while (i <= nbr) // On divise sorted_list par 4 chunks
	{
		// printf("\n%d \n", (n /nbr) * i );
		while (pushSwap.sizeA > n - ((n / nbr) * i) + 5) // On transfère chaque chunks du plus petit au plus grand, 1 par 1 en utilisant RRA et PB
		{
			push_chunk(n, nbr, i);
			rotate_A();
		}
		i++;
	}
}
int get_k(int n, int i, int best_order_value)
{
	return k_k(n, i, best_order_value);
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
	else if (pushSwap.stackA[0] > pushSwap.stackA[1] && pushSwap.stackA[1] > pushSwap.stackA[2] && pushSwap.stackA[0] > pushSwap.stackA[2]) // case2 : [3,2,1]->sa->[2,3,1]->ra->[3,1,2]->sa->[1,3,2]->rra->[2,1,3]->sa->[1,2,3].
		main_algorithm_2_1();
	else if (pushSwap.stackA[0] > pushSwap.stackA[1] && pushSwap.stackA[1] < pushSwap.stackA[2] && pushSwap.stackA[0] > pushSwap.stackA[2]) // case3: [3,1,2]->sa->[1,3,2]->ra->[3,2,1]->sa->[2,3,1]->rra->[1,2,3].
	{
		swap_A();
		rotate_A();
		swap_A();
		reverse_rotate_A();
	}
	else if (pushSwap.stackA[0] < pushSwap.stackA[1] && pushSwap.stackA[1] > pushSwap.stackA[2] && pushSwap.stackA[0] < pushSwap.stackA[2]) // case4 : [1,3,2]->ra->[3,2,1]->sa->[2,3,1]->rra->[1,2,3].
	{
		rotate_A();
		swap_A();
		reverse_rotate_A();
	}
	else if (pushSwap.stackA[0] < pushSwap.stackA[1] && pushSwap.stackA[1] > pushSwap.stackA[2] && pushSwap.stackA[0] > pushSwap.stackA[2]) // case5 : [2,3,1]->ra->[3,1,2]->sa->[1,3,2]->rra->[2,1,3]->sa->[1,2,3].
	{
		rotate_A();
		swap_A();
		reverse_rotate_A();
		swap_A();
	}
}
void main_algorithm(int n)
{
	// On ramène sur A le plus grand nombre au plus petit nombre. On cherche par chunk avec RB,RRB et PA
	int i = 0;
	int k1;
	int k2;
	int k3;

	while (n - 1 - i >= 0)
	{
		k1 = pushSwap.sorted_list[n - 1 - i];
		k2 = pushSwap.sorted_list[n - 2 - i];
		k3 = pushSwap.sorted_list[n - 3 - i];
		
		int *best_order = best_combination(k1, k2, k3, n - i, pushSwap.sizeB);
	
		if (n - i == 2)
		{
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
void push_swap_big(int n)
{
	int nbr;

	if (n <= 100) // && n <= 100
		nbr = 4;
	else
		nbr = 8;
	handle_4_chunks_division(n, nbr);
	while (pushSwap.sizeA > 0)
	{
		push_B();
	}
	main_algorithm(n);
}
int push_swap()
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
		push_swap_big(n);
	return 0;
}
// write me an algorithm that is printing alphabet


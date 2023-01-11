#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototypes
void merge_sort(int *list, int start, int end);
void merge(int *list, int start, int mid, int end);
int push_swap(int *stackA, int *stackB, int *sizeA, int *sizeB, char *result_to_display, int *sorted_list);
void swap_A(int *stackA, int *sizeA, char *result_to_display);
void swap_B(int *stackB, int *sizeB, char *result_to_display);
void swap_both(int *stackA, int *stackB, int *sizeA, int *sizeB, char *result_to_display);
void rotate_A(int *stackA, int *sizeA, char *result_to_display);
void rotate_B(int *stackB, int *sizeB, char *result_to_display);
void rotate_both(int *stackA, int *stackB, int *sizeA, int *sizeB, char *result_to_display);
void reverse_rotate_A(int *stackA, int *sizeA, char *result_to_display);
void reverse_rotate_B(int *stackB, int *sizeB, char *result_to_display);
void reverse_rotate_both(int *stackA, int *stackB, int *sizeA, int *sizeB, char *result_to_display);
void push_A(int *stackA, int *stackB, int *sizeA, int *sizeB, char *result_to_display);
void push_B(int *stackA, int *stackB, int *sizeA, int *sizeB, char *result_to_display);

int main(int argc, char *argv[]) {
	int *stackA, *stackB, sizeA[1], sizeB[1];
	char *result_to_display;
	
	//Check if arguments are valid
	if (argc < 2) {
		printf("Error\n");
		return 0;
	}
	
	//Check if all arguments are int
	for (int i = 1; i < argc; i++) {
		if (atoi(argv[i]) == 0 && argv[i][0] != '0') {
			printf("Error : not int %c\n", argv[i][0]);
			return 0;
		}
	}
	
	//Check if there are duplicates
	for (int i = 1; i < argc; i++) {
		for (int j = i + 1; j < argc; j++) {
			if (atoi(argv[i]) == atoi(argv[j])) {
				printf("Error\n");
				return 0;
			}
		}
	}
	
	//Initialize stackA and stackB
	*sizeA = argc - 1;
	*sizeB = 0;
	stackA = (int *)malloc(*sizeA * sizeof(int));
	stackB = (int *)malloc(*sizeA * sizeof(int));
	
	
	//Fill stackA
	for (int i = 0; i < *sizeA; i++) {
		stackA[i] = atoi(argv[i + 1]);
	}
	
	//Sort stackA
	int *sorted_list = (int *)malloc(*sizeA * sizeof(int));
	for (int i = 0; i < *sizeA; i++) {
		sorted_list[i] = stackA[i];
	}
	merge_sort(sorted_list, 0, *sizeA - 1);
	
	//Initialize result_to_display
	result_to_display = (char *)malloc(*sizeA * 10 * sizeof(char));
	strcpy(result_to_display, "");
	
	//Run push_swap
	push_swap(stackA, stackB, sizeA, sizeB, result_to_display, sorted_list);
	
	//Display result
	printf("%s", result_to_display);
	/*
	printf("Number of instructions : %d\n", (int)(strlen(result_to_display) / 3));
	printf("Stack A : ");
	for (int i = 0; i < *sizeA; i++) {
		printf("%d ", stackA[i]);
	}
	printf("\nStack B : ");
	for (int i = 0; i < *sizeB; i++) {
		printf("%d ", stackB[i]);
	}
	printf("\n");
	*/

	//Free memory
	free(stackA);
	free(stackB);
	free(sorted_list);
	free(result_to_display);
	
	return 0;
}

//Merge sort algorithm
void merge_sort(int *list, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(list, start, mid);
		merge_sort(list, mid + 1, end);
		merge(list, start, mid, end);
	}
}

//Merge two sorted lists
void merge(int *list, int start, int mid, int end) {
	int i, j, k;
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int *L = (int *)malloc(n1 * sizeof(int));
	int *R = (int *)malloc(n2 * sizeof(int));
	
	for (i = 0; i < n1; i++) {
		L[i] = list[start + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = list[mid + 1 + j];
	}
	
	i = 0;
	j = 0;
	k = start;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			list[k] = L[i];
			i++;
		}
		else {
			list[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1) {
		list[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		list[k] = R[j];
		j++;
		k++;
	}
	
	free(L);
	free(R);
}

//Push_swap algorithm
int push_swap(int *stackA, int *stackB, int *sizeA, int *sizeB, char *result_to_display, int *sorted_list) {
	int i = 0;
	int j = 0;
	int e;
	int n = *sizeA;
	//push_B(stackA, stackB, sizeA, sizeB, result_to_display);
	//push_A(stackA, stackB, sizeA, sizeB, result_to_display);

	// Check si trié dont Cas ou n=1
	for (int i = 0; i <= *sizeA;i++)
	{
		if (sorted_list[i] != stackA[i])
			break;
		if (i == *sizeA)
			return 0;
	}

	if (n <= 10) // Cas ou n <= 10
	{
		
		if (n == 2) // Cas ou n=2; swap 1 time if needed
			swap_A(stackA, sizeA, result_to_display);
		else if (n == 3) // Cas ou n=3; 5 combinaisons possibles
		{
			if (stackA[0] > stackA[1] && stackA[1] < stackA[2] && stackA[0] < stackA[2]) //case1 : [2,1,3]->sa->[1,2,3].
				swap_A(stackA, sizeA, result_to_display);
			else if ( stackA[0] > stackA[1] && stackA[1] > stackA[2] && stackA[0] > stackA[2]) //case2 : [3,2,1]->sa->[2,3,1]->rra->[1,2,3].
			{
				swap_A(stackA, sizeA, result_to_display);
				reverse_rotate_A(stackA, sizeA, result_to_display);
			}
			else if (stackA[0] > stackA[1] && stackA[1] < stackA[2] && stackA[0] > stackA[2]) //case3: [3,1,2]->ra->[1,2,3].
				rotate_A(stackA, sizeA, result_to_display);
			else if ( stackA[0] < stackA[1] && stackA[1] > stackA[2] && stackA[0] < stackA[2]) //case4 : [1,3,2]->sa->[3,1,2]->ra->[1,2,3].
			{
				swap_A(stackA, sizeA, result_to_display);
				rotate_A(stackA, sizeA, result_to_display);
			}
			else if (stackA[0] < stackA[1] && stackA[1] > stackA[2] && stackA[0] > stackA[2]) //case5 : [2,3,1]->rra->[1,2,3].
				reverse_rotate_A(stackA, sizeA, result_to_display);
		}
		else // Autres cas; tri par selection, on ramène le plus petit nb par le haut ou le bas selon la distance
		{
			while (sorted_list[j] != sorted_list[n])
			{
				if (sorted_list[j] == stackA[0])
				{
					push_B(stackA, stackB, sizeA, sizeB, result_to_display);
					j++;
				}
				else
				{
					rotate_A(stackA, sizeA, result_to_display);
				}
						//printf("1:%d ", sorted_list[*sizeA-1]);
						//printf("2:%d\n", sorted_list[j]);
			}
			for (int i = 0; i < n; i++)
				push_A(stackA, stackB, sizeA, sizeB, result_to_display);
		}

	}
	else if (n > 10 && n <= 100) // Cas ou n > 10 && A <= 100
	{
		
		for (int i = 1; i <= 4;i++) // On divise sorted_list par 4 chunks
		{
			for (int a = 0; a < n ; a++) // On transfère chaque chunks du plus petit au plus grand, 1 par 1 en utilisant RRA et PB
			{
				
				if(i==1)
					e = 0;
				else
					e = (n / 4) * (i - 1);

				for (; e <= (n / 4) * i - 1; e+=1)
				{
					if (stackA[0] == sorted_list[e])
					{	
						push_B(stackA, stackB, sizeA, sizeB, result_to_display);
						break;
					}
				}
				reverse_rotate_A(stackA, sizeA, result_to_display);
			}

		}
		
		// On ramène sur A le plus grand nombre au plus petit nombre. On cherche par chunk avec RB,RRB et PA
		int b = 0;
		for (int i = 0; n - 1 - i >= 0;i+=1)
		{
			while (b > 0)
			{
				reverse_rotate_B(stackB, sizeB, result_to_display);
				b--;
			}
			while (stackB[0] != sorted_list[n - 1 - i])
			{
				rotate_B(stackB, sizeB, result_to_display);
				b++;
			}
			push_A(stackA, stackB, sizeA, sizeB, result_to_display);
		}

	}

		
		
	return 0;
		


}

//Swap top two numbers in stack A
void swap_A(int *stackA, int *sizeA, char *result_to_display) {
	int temp = stackA[0];
	stackA[0] = stackA[1];
	stackA[1] = temp;
	strcat(result_to_display, "SA\n");
}

//Swap top two numbers in stack B
void swap_B(int *stackB, int *sizeB, char *result_to_display) {
	int temp = stackB[0];
	stackB[0] = stackB[1];
	stackB[1] = temp;
	strcat(result_to_display, "SB\n");
}

//Run SA and SB at the same time
void swap_both(int *stackA, int *stackB, int *sizeA, int *sizeB, char *result_to_display) {
	swap_A(stackA, sizeA, result_to_display);
	swap_B(stackB, sizeB, result_to_display);
	strcat(result_to_display, "SS\n");
}

//Top number goes to bottom of Stack A
void rotate_A(int *stackA, int *sizeA, char *result_to_display) {
	int temp = stackA[0];
	for (int i = 0; i < *sizeA - 1; i++) {
		stackA[i] = stackA[i + 1];
	}
	stackA[*sizeA - 1] = temp;
	strcat(result_to_display, "RA\n");
}

//Top number goes to bottom of Stack B
void rotate_B(int *stackB, int *sizeB, char *result_to_display) {
	int temp = stackB[0];
	for (int i = 0; i < *sizeB - 1; i++) {
		stackB[i] = stackB[i + 1];
	}
	stackB[*sizeB - 1] = temp;
	strcat(result_to_display, "RB\n");
}

//Run RA and RB at the same time
void rotate_both(int *stackA, int *stackB, int *sizeA, int *sizeB, char *result_to_display) {
	rotate_A(stackA, sizeA, result_to_display);
	rotate_B(stackB, sizeB, result_to_display);
	strcat(result_to_display, "RR\n");
}

//bottom number goes to top of Stack A
void reverse_rotate_A(int *stackA, int *sizeA, char *result_to_display) {
	int temp = stackA[*sizeA - 1];
	for (int i = *sizeA - 1; i > 0; i--) {
		stackA[i] = stackA[i - 1];
	}
	stackA[0] = temp;
	strcat(result_to_display, "RRA\n");
}

//bottom number goes to top of Stack B
void reverse_rotate_B(int *stackB, int *sizeB, char *result_to_display) {
	int temp = stackB[*sizeB - 1];
	for (int i = *sizeB - 1; i > 0; i--) {
		stackB[i] = stackB[i - 1];
	}
	stackB[0] = temp;
	strcat(result_to_display, "RRB\n");
}

//Run RRA and RRB at the same time
void reverse_rotate_both(int *stackA, int *stackB, int *sizeA, int *sizeB, char *result_to_display) {
	reverse_rotate_A(stackA, sizeA, result_to_display);
	reverse_rotate_B(stackB, sizeB, result_to_display);
	strcat(result_to_display, "RRR\n");
}

//Send top of B to top of A
void push_A(int *stackA, int *stackB, int *sizeA, int *sizeB, char *result_to_display) {
	if (*sizeB > 0)
	{
		for (int i = 0; i < *sizeA; i++) {
			stackA[*sizeA - i] = stackA[*sizeA - 1 - i];
		}	
		stackA[0] = stackB[0];
		*sizeB -= 1;
		*sizeA += 1;
		for (int i = 0; i < *sizeB; i++) {
			stackB[i] = stackB[i + 1];
		}
		strcat(result_to_display, "PA\n");		
	}

}

//Send top of A to top of B
void push_B(int *stackA, int *stackB, int *sizeA, int *sizeB, char *result_to_display) {
	if (*sizeA > 0)
	{
		for (int i = 0; i < *sizeB; i++) {
			stackB[*sizeB - i] = stackB[*sizeB - 1 - i];
		}	
		stackB[0] = stackA[0];
		*sizeA -= 1;
		*sizeB += 1;
		for (int i = 0; i < *sizeA; i++) {
			stackA[i] = stackA[i + 1];
		}
		strcat(result_to_display, "PB\n");
	}

}
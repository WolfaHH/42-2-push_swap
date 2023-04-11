# include "push_swap.h"

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
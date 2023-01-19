#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
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
int k_k(int *stackB, int *sorted_list, int n, int i, int e, int *sizeB);
int pepe(int *stackK, int k1, int k2, int k3, int *sizeK, int *sorted_list, int n, int e1, int e2, int e3);
void rotate_K(int *stackB, int *sizeB);
void reverse_rotate_K(int *stackB, int *sizeB);
int *best_combination(int k1, int k2, int k3, int* stackB, int size, int *sorted_list, int n);


#endif
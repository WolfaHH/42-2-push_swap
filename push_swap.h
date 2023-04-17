#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

// Structures
struct pushSwap {
    int *stackA;           // pointer to integer array
    int *stackB;           // pointer to integer array
    int sizeA;            // pointer to integer size variable for stackA
    int sizeB;            // pointer to integer size variable for stackB
    char *result_to_display; // pointer to character array
    int *sorted_list;      // pointer to integer array
};
struct pushSwap pushSwap;
//Prototypes
void merge_sort(int *list, int start, int end);
void merge(int *list, int start, int mid, int end);
int push_swap(int *stackA, int sizeA);
void swap_A();
void swap_B();
void swap_both();
void rotate_A();
void rotate_B();
void rotate_both();
void reverse_rotate_A();
void reverse_rotate_B();
void reverse_rotate_both();
void push_A();
void push_B();
int k_k(int n, int i, int e);
void rotate_K(int *stackB, int *sizeB);
void reverse_rotate_K(int *stackB, int *sizeB);
int *best_combination(int k1, int k2, int k3, int n, int size);
int k_k_k(int *stackB, int *sorted_list, int n, int i, int e, int *sizeB);
int pepe(int *stackK, int k1, int k2, int k3, int *sizeK, int n, int e1, int e2, int e3);
void push_swap_multi(int n, int nbr, int *stackA, int sizeA);
void sort_five_elements();

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:28:11 by ngodard           #+#    #+#             */
/*   Updated: 2023/05/24 21:07:14 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <stdbool.h>

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
void swap_a();
void swap_b();
void swap_both();
void rotate_a();
void rotate_b();
void rotate_both();
void reverse_rotate_a();
void reverse_rotate_b();
void reverse_rotate_both();
void push_a();
void push_b();
int k_k(int n, int i, int e);
void rotate_K(int *stackB, int *sizeB);
void reverse_rotate_K(int *stackB, int *sizeB);
int *best_combination(int k[3], int n, int size);
int k_k_k(int *stackB, int *sorted_list, int n, int i, int e, int *sizeB);
int pepe(int *stackK, int k1, int k2, int k3, int *sizeK, int n, int e1, int e2, int e3);
void push_swap_multi(int n, int nbr, int *stackA, int sizeA);
void sort_five_elements();
char **ft_split(const char *s, char c);
int	superchecker(char *argv[], int argc);
void	instantiation(int argc);
bool	is_integer(const char *str);
bool	has_duplicates(int argc, char *argv[]);
bool	is_valid_input(int argc, char *argv[]);
bool	is_second_format(int argc, char *argv[]);
int check_sorted(void);
void handle_case_3_2(void);
void handle_case_3(void);
void sort_five_elements(void);
void push_swap_small(int n);
void push_chunk(int n, int nbr, int i);
void handle_4_chunks_division(int n, int nbr);
int get_k(int n, int i, int best_order_value);
int push_and_update_k(int n, int i, int *best_order, int index);
void check_stack(int euh[2], int *best_order, int k, int *p);
void main_algorithm_1(int n, int i, int *best_order);
void main_algorithm_2_1(void);
void toubitouba(void);
void main_algorithm_2(void);
int len(const char *str);
int ttthh(int n, int i);
void main_algorithm(int n, int i);
void push_swap_multi(int n, int nbr, int *stackA, int sizeA);
void push_swap_big(int n, int *stackA, int sizeA);
void ft_strcat(char *dest, const char *src);

#endif
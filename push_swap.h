/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:28:11 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/13 08:45:02 by ngodard          ###   ########.fr       */
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
# include <errno.h>

// Structures
typedef struct s_g_push_swap {
	int		*stacka;
	int		*stackb;
	int		sizea;
	int		sizeb;
	char	*result_to_display;
	int		*sorted_list;
}	t_g_push_swap;

t_g_push_swap	g_push_swap;

static int		g_order[3];

//Prototypes
void		copy_stack(int *stackK, int *sizeK);
void		assign_order(int index, int permutations[6][3]);
void		useperm(int permutations[6][3]);
int			check_distance(int *stackK, int *k, int *sizeK, int *aarg);
void		calculate_order(int *stackK, int *k, int *sizeK, int n);
int			*best_combination(int k[3], int n, int size);
void		merge_sort(int *list, int start, int end);
int			push_swap(int *stackA, int sizeA);
void		swap_a(void);
void		swap_b(void);
void		swap_both(void);
void		rotate_a(void);
void		rotate_b(void);
void		rotate_both(void);
void		reverse_rotate_a(void);
void		reverse_rotate_b(void);
void		reverse_rotate_both(void);
void		push_a(void);
void		push_b(void);
int			k_k(int n, int i, int e);
void		rotate_k(int *stackB, int *sizeB);
void		reverse_rotate_k(int *stackB, int *sizeB);
int			*best_combination(int k[3], int n, int size);
int			k_k_k(int *stackB, int n, int e, int *sizeB);
int			pepe(int *stackK, int *sizeK, int *arg);
void		push_swap_multi(int n, int nbr, int *stackA, int sizeA);
void		sort_five_elements(void);
char		**ft_split(const char *s, char c);
int			superchecker(char *argv[], int argc);
void		instantiation(int argc);
bool		is_integer(const char *str);
bool		has_duplicates(int argc, char *argv[]);
bool		is_valid_input(int argc, char *argv[]);
bool		is_second_format(int argc, char *argv[]);
int			check_sorted(void);
void		handle_case_3_2(void);
void		handle_case_3(void);
void		sort_five_elements(void);
void		push_swap_small(int n);
void		push_chunk(int n, int nbr, int i);
void		handle_4_chunks_division(int n, int nbr);
int			get_k(int n, int i, int best_order_value);
int			push_and_update_k(int n, int i, int *best_order, int index);
void		main_algorithm_1(int n, int i, int *best_order);
void		main_algorithm_2_1(void);
void		toubitouba(void);
void		main_algorithm_2(void);
int			len(const char *str);
int			ttthh(int n, int i);
void		main_algorithm(int n, int i);
void		push_swap_multi(int n, int nbr, int *stackA, int sizeA);
void		push_swap_big(int n, int *stackA, int sizeA);
void		ft_strcat(char *dest, const char *src);
char		*ft_strcpy(char *destination, const char *source);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		norminettedecestmortsadaronnejenaimarredec(void);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
int			ft_atoi(const char *str);
int			ft_printf(const char*fmt, ...);
int			ft_isdigit(int c);
long long	ft_strtoll(const char *str, char **endptr);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:31:59 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/13 08:59:44 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	yoloz(int *stackcouille, char *argv[])
{
	int	i;

	i = 0;
	while (i < g_push_swap.sizea)
	{
		g_push_swap.stacka[i] = ft_atoi(argv[i + 1]);
		stackcouille[i] = ft_atoi(argv[i + 1]);
		i++;
	}	
}

void	free_memory(int *stackcouille)
{
	free(g_push_swap.stacka);
	free(g_push_swap.stackb);
	free(g_push_swap.sorted_list);
	free(g_push_swap.result_to_display);
	free(stackcouille);
}

int	main(int argc, char *argv[])
{
	int	*stackcouille;
	int	i;
	int	check;

	check = superchecker(argv, argc);
	if (!check)
		return (0);
	else if (check != -1)
		argc = check;
	instantiation(argc);
	stackcouille = (int *)malloc(g_push_swap.sizea * sizeof(int)
			* g_push_swap.sizea + 3);
	yoloz(stackcouille, argv);
	g_push_swap.sorted_list = (int *)malloc(g_push_swap.sizea * sizeof(int));
	i = -1;
	while (i++ < g_push_swap.sizea)
		g_push_swap.sorted_list[i] = g_push_swap.stacka[i];
	merge_sort(g_push_swap.sorted_list, 0, g_push_swap.sizea - 1);
	g_push_swap.result_to_display = (char *)malloc(999999);
	ft_strcpy(g_push_swap.result_to_display, "");
	push_swap(stackcouille, g_push_swap.sizea);
	ft_printf("%s", g_push_swap.result_to_display);
	free_memory(stackcouille);
	return (0);
}

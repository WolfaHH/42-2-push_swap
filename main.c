/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:31:59 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/12 15:19:41 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	yoloz(int *stackcouille, char *argv[])
{
	int	i;

	i = 0;
	while (i < pushSwap.sizeA)
	{
		pushSwap.stackA[i] = atoi(argv[i + 1]);
		stackcouille[i] = atoi(argv[i + 1]);
		i++;
	}	
}

void	free_memory(int *stackcouille)
{
	free(pushSwap.stackA);
	free(pushSwap.stackB);
	free(pushSwap.sorted_list);
	free(pushSwap.result_to_display);
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
	stackcouille = (int *)malloc(pushSwap.sizeA * sizeof(int)
			* pushSwap.sizeA + 2);
	yoloz(stackcouille, argv);
	pushSwap.sorted_list = (int *)malloc(pushSwap.sizeA * sizeof(int));
	i = -1;
	while (i++ < pushSwap.sizeA)
		pushSwap.sorted_list[i] = pushSwap.stackA[i];
	merge_sort(pushSwap.sorted_list, 0, pushSwap.sizeA - 1);
	pushSwap.result_to_display = (char *)malloc(999999);
	strcpy(pushSwap.result_to_display, "");
	push_swap(stackcouille, pushSwap.sizeA);
	printf("%s", pushSwap.result_to_display);
	free_memory(stackcouille);
	return (0);
}

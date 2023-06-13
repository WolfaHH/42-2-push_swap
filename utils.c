/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:08:29 by ngodard           #+#    #+#             */
/*   Updated: 2023/06/13 09:00:38 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static bool	ft_is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

static int	to_digit(char c)
{
	return (c - '0');
}

long long	ft_strtoll(const char *str, char **endptr)
{
	bool		negative;
	long long	result;

	while (ft_is_space(*str))
		str++;
	negative = false;
	if (*str == '-')
		negative = true;
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + to_digit(*str);
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	if (negative == true)
		result = -result;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:00:14 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/26 15:19:10 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespace(char c)
{
	if (c == ' ' || c == '\r' || c == '\t'
		|| c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

static int	overflow(long nb, int sign, char next_digit)
{
	if (sign == 1)
	{
		if (nb > LONG_MAX / 10
			|| (nb == LONG_MAX / 10 && next_digit - '0' >= LONG_MAX % 10))
			return (1);
	}
	if (sign == -1)
	{
		if (nb > LONG_MIN / -10
			|| (nb == LONG_MIN / -10 && next_digit - '0' >= LONG_MIN % 10 * -1))
			return (-1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (whitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -sign;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (overflow(result, sign, *str) == -1)
				return ((int)LONG_MIN);
			if (overflow(result, sign, *str) == 1)
				return ((int)LONG_MAX);
			result = result * 10 + *str - '0';
			str++;
		}
		else
			break ;
	}
	return ((int)(sign * result));
}

// #include <stdio.h>
// int main(void)
// {
// 	char *mixed = "-9223372036854775809";
// 	printf("%d\n", ft_atoi(mixed));
// 	return (0);
// }

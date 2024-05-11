/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:28:59 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/30 19:19:24 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(int nb)
{
	int	len;

	len = 0;
	if (nb < 1)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*malloc_str(size_t nb_length)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (nb_length + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	int				sign;
	int				nb_length;
	char			*str;

	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb_length = nb_len(n);
	if (n < 0)
	{
		n *= -1;
		sign = -1;
	}
	str = malloc_str(nb_length);
	if (!str)
		return (NULL);
	str[nb_length] = '\0';
	while (nb_length--)
	{
		str[nb_length] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

// #include <stdio.h>
// int  main (void)
// {
// 	char *str;

// 	str = ft_itoa(-7);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
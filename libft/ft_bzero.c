/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:06:59 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/17 17:10:32 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

// #include <stdio.h>
// int main()
// {
// 	char test[50] = "hey";
// 	printf("%s\n", test);
// 	ft_bzero(test, 1);
// 	printf("%s\n", test);
// 	return (0);
// }
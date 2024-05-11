/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:34:46 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/29 16:34:59 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

// #include <stdio.h>
// void	test_function(unsigned int i, char *s)
// {
//     while (*s)
//     {
//         if (*s >= 'a' && *s <= 'z')
//             *s -= 32;
//         s++;
//     }
// }

// int main (void)
// {
// 	char s[] = "Abc";

// 	ft_striteri(s, test_function);
// 	printf("%s\n", s);
// 	return (0);
// }
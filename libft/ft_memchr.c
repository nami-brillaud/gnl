/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:37:14 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/19 17:53:10 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*s_ptr;
	unsigned char			uc;
	size_t					i;

	s_ptr = (const unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*s_ptr == uc)
		{
			return ((void *)s_ptr);
		}
		else
		{
			s_ptr++;
			i++;
		}
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// 	// s = "libft-test-tokyo\0\0\0acdfg\0\0\0\0\0"
// 	char *s = calloc(30, sizeof(char));
// 	memcpy(s, "libft-test-tokyo", 17);
// 	memcpy(s + 20, "acdfg", 5);

// 	// char overflow
// 	printf("ft ver %s\n",ft_memchr(s, 'l' + 256, 30));
// 	printf("real ver %s\n",memchr(s, 'l' + 256, 30));
// 	return (0);
// }
// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	const char test[50] = "Hello Dude 123";
// 	char *ptr;
// 	printf("%s\n", test);
// 	ptr = ft_memchr(test, '5',  strlen(test));
// 	if (ptr != NULL)
// 	{
// 		printf("Found 1 at position %ld\n", ptr - test);
// 	}
// 	else
// 	{
// 		printf("Nothing found!\n");
// 	}
// 	return (0);
// }
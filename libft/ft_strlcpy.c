/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:37:16 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/30 19:56:06 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	if (!dstsize)
		return (srcsize);
	i = 0;
	while (i < (dstsize - 1) && *src)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (srcsize);
}
// #include <stdio.h>
// int main(void)
// {
// 	char src[] = "Hello";
// 	char dst[4];
// 	printf("Source is %s\n", src);
// 	size_t result = ft_strlcpy(dst, src, 4);
// 	printf("Dest is %s\n", dst);
// 	printf("Size of source is %zu\n", result);
// 	return (0);
// }

// Expected Result:
// Source is Hello
// Dest is Hel
// Size of source is 5
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:29:39 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/30 19:57:38 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dstlen;
	size_t		totallen;
	const char	*src_ptr;
	size_t		i;

	if (dst == NULL)
		return (ft_strlen(src));
	if ((!dst || !src) && !dstsize)
		return (0);
	src_ptr = src;
	dstlen = 0;
	while (dst[dstlen] && dstlen < dstsize)
		dstlen++;
	if (dstlen < dstsize)
		totallen = dstlen + ft_strlen(src_ptr);
	else
		return (dstsize + ft_strlen(src_ptr));
	i = dstlen;
	while (i < dstsize - 1 && *src_ptr)
	{
		dst[i] = *src_ptr++;
		i++;
	}
	dst[i] = '\0';
	return (totallen);
}

// #include <stdio.h>
// int main(void)
// {
// 	char src[2] = "";
// 	char dst[50] = "";
// 	printf("The source is %s, the dest is %s\n", src, dst);
// 	size_t result = ft_strlcat(dst, src, -1);
// 	printf("Now the source is %s, the dest is %s, the result is %zu\n", 
// 	src, dst, result);
// 	return (0);
// }
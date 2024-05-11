/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:09:04 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/26 15:13:15 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_ptr;
	char	*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	if (!dst && !src)
		return (dst);
	while (n--)
	{
		*dst_ptr++ = *src_ptr++;
	}
	return (dst);
}

// #include <stdio.h>
// int main ()
// {
// 	int source = 10;
// 	int dest = 5;
// 	int *sourceptr = &source;
// 	int *destptr = &dest;
// 	printf("%d %d\n", source, dest);
// 	ft_memcpy(destptr, sourceptr, 4);
// 	printf("Modified int %d %d\n", source, dest);
// 	return (0);
// }

// int main ()
// {
// 	char source[10] = "";
// 	char dest[50] = "";
// 	printf("%s %s\n", source, dest);
// 	ft_memcpy(dest, source, 0);
// 	printf("Modified char %s %s\n", source, dest);
// 	return (0);
// }

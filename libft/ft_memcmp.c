/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:02:24 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/19 17:53:10 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*s1_ptr;
	unsigned char		*s2_ptr;
	size_t				i;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*s1_ptr != *s2_ptr)
		{
			return ((int)(*s1_ptr) - (int)(*s2_ptr));
		}
		else
		{
			i++;
			s1_ptr++;
			s2_ptr++;
		}
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	// char str1[] = "Hey";
// 	// char str2[] = "Heo";
// 	// printf("%d\n", ft_memcmp(str1, str2, 3));
// // 10 (difference between y and o)

// 	// char str1[] = "Hey";
// 	// char str2[] = "Heyo";
// 	// printf("%d\n", ft_memcmp(str1, str2, 3)); // returns 0 

// 	// char str1[] = "Hey";
// 	// char str2[] = "Heyo";
// 	// printf("%d\n", ft_memcmp(str1, str2, 4)); 
// // returns -111 (difference between \0 (0) and o (111))

// 	// char str1[] = "Hey";
// 	// char str2[] = "Heyo";
// 	// printf("%d\n", ft_memcmp(str1, str2, 5)); 
// // with 1 byte over, still returns -111 
// (difference between \0 (0) and o (111))

// 	// char *str1 = NULL;
// 	// char *str2 = NULL;
// 	// printf("%d\n", ft_memcmp(str1, str2, 5)); //segfault
// 	// return (0);

// 	// char str1[] = "";
// 	// char str2[] = "";
// 	// printf("%d\n", ft_memcmp(str1, str2, 0));
//for byte 1 and 0, returns 0

// 	// char str1[] = "";
// 	// char str2[] = "";
// 	// printf("%d\n", ft_memcmp(str1, str2, 5)); 
// 	// returns 208 - undefined behavior

// 	// int arr1[] = {1, 2, 3, 4};
//     // int arr2[] = {1, 2, 3, 5};
//     // printf("%d\n", ft_memcmp(arr1, arr2, sizeof(arr1))); // returns -1

// 	//return(0);

// }
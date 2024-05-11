/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:09:53 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/19 17:53:10 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)ptr)[i] = x;
		i++;
	}
	return (ptr);
}

// #include <stdio.h>
// int main() 
// { 
//     char str[50] = "GeeksForGeeks is for programming geeks."; 
//     printf("\nBefore memset(): %s\n", str); 
//     ft_memset(str + 13, '.', 8*sizeof(char)); 
//     printf("After memset():  %s", str); 
//     return 0; 
// } 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:52:07 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/30 18:42:44 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && !needle)
		return (NULL);
	if (!*needle)
		return ((char *)(haystack));
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while ((i + j) < len && needle[j] && (haystack[i + j] == needle[j]))
		{
			j++;
		}
		if (needle[j] == '\0')
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	char needle[]="needle";
// 	// char empty[]="";
// 	char str[]="i hid a needle here";
// 	// char trap[]="needlineedlabutnotneedlf";
// 	// char nothing[]="nothinghere";
// 	// printf("empty/needle %s\n", ft_strnstr(empty, needle, 7));
// 	// printf("needle/empty %s\n", ft_strnstr(needle, empty, 7));
// 	printf("needle/str %s\n", ft_strnstr(str, needle, 20));
// 	// printf("needle/trap %s\n", ft_strnstr(needle, trap, 7));
// 	// printf("needle/nothing %s\n", ft_strnstr(needle, nothing, 7));
// 	return(0);
// }
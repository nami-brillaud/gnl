/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:22:39 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/19 17:53:10 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < (n - 1) && s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] != s2[i])
	{
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	// char empty[] = "";
// 	char abc[] = "abc";
// 	char abb[] = "abb";
// 	// char abc_same[] = "abc";
// 	printf("empty/abc 3 %d\n", ft_strncmp(abb, abc, 3));
// 	return(0);
// }

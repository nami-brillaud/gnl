/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:29:23 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/29 16:30:16 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	total_size;

	if (!s1 || !s2)
		return (NULL);
	if (!s1 & !s2)
		return ("");
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(sizeof(char) * total_size);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, sizeof(char) * total_size);
	ft_strlcat(ptr, s2, sizeof(char) * total_size);
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
// 	char test1[] = "";
// 	char test2[] = "";
// 	char *result = ft_strjoin(test1, test2);
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }
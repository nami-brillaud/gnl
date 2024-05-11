/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:30:47 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/29 20:44:44 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_find(char const *s1, char const c)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && char_find(set, s1[start]) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > start && char_find(set, s1[end - 1]) == 1)
		end--;
	ptr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1 + start, sizeof(char) * (end - start + 1));
	return (ptr);
}

// int main(void)
// {
// 	char string[] = "1234A223A";
// 	char set[] = "1234";
// 	char *result = ft_strtrim(string, set);
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:23:29 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/18 18:11:06 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_strjoin(char *stash, char *buffer) //should i add const here?
{
	char	*save;
	int		i;
	int		j;

	if (!stash && !buffer)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	save = ft_calloc(ft_strlen(stash) + ft_strlen(buffer) + 1, sizeof(char));
	if (!save)
		return (NULL);
	i = -1;
	while (stash[++i]) //you are using calloc so that if you dont have a stash first, it has stash = 0 so it skips this loop
		save[i] = stash[i];
	j = -1;
	while (buffer[++j])
		save[i++] = buffer[j];
	save[i] = '\0';
	printf("%s\n", "I'm here");
	return (free(stash), free(buffer), save);
}

char	*newline_check(char *stash)
{
	while (*stash)
	{
		if (*stash == '\n')
			return (stash);
		stash++; //doing this doesnt modify the original stash, as the pointer to stash is just a local copy
	}
	return (NULL);
}

// char	*ft_strjoin(char const *s1, char const *s2) //YOU HAVE TO ADJUST THIS TO STASH!!
// {
// 	char	*str;
// 	char	*initial_str;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!str)
// 		return (NULL);
// 	initial_str = str;
// 	while (*s1)
// 		*str++ = *s1++;
// 	while (*s2)
// 		*str++ = *s2++;
// 	*str = '\0';
// 	return (initial_str);
// }

// char	*ft_substr(char const *str, unsigned int start, size_t len) //you dont care about start > len because you will choose the value
// {
// 	char	*substr;
// 	char	*reference;
// 	size_t	i;

// 	substr = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!substr)
// 		return (NULL);
// 	reference = (char *)str + start;
// 	i = 0;
// 	while (*reference && i < len)
// 		substr[i++] = *reference++;
// 	substr[i] = '\0';
// 	return (substr);
// }

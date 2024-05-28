/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:23:29 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/28 16:01:13 by nfujisak         ###   ########.fr       */
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

char	*ft_strjoin(char *stash, char *buffer)
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
	while (stash[++i])
		save[i] = stash[i];
	j = -1;
	while (buffer[++j])
		save[i++] = buffer[j];
	save[i] = '\0';
	return (free(stash), free(buffer), save);
}

char	*newline_check(char *stash)
{
	if (!stash)
		return (NULL);
	while (*stash)
	{
		if (*stash == '\n')
			return (stash);
		stash++;
	}
	return (NULL);
}

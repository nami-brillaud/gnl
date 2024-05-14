/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:23:29 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/14 20:13:14 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

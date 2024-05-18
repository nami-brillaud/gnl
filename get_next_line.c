/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:21:37 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/18 19:12:32 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_remains(char *stash, char *line)
{
	char	*remains;
	int		i;
	int		j;

	i = 0;
	remains = NULL;
	if (!line)
		return (free(stash), NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	j = i + 1;
	if (stash[i] == '\n')
	{
		while (stash[j])
			j++;
		remains = ft_calloc(j - i + 1, sizeof(char));
		if (!remains)
			return (free(stash), NULL); //preserve or not preserve previous stash is alloc fails?
		j = i + 1;
		i = 0;
		while (stash[j])
			remains[i++] = stash[j++];
		remains[i] = '\0';
	}
	return (free(stash), remains);
}

char	*fetch_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL); //where does this GO?
	i = -1;
	while (stash[++i] && stash[i] != '\n')
		line[i] = stash[i];
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *stash)
{
	char	*buffer;
	int		chars_read;

	chars_read = 1;
	while (!newline_check(stash) && !chars_read)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		chars_read = (int)read(fd, buffer, BUFFER_SIZE);
		if ((!stash && chars_read == 0) || chars_read == -1)
			return (free(buffer), NULL);
		buffer[chars_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	save = read_file(fd, stash);
	if (!save)
	{
		if (stash)
			free(stash);
		stash = NULL; //why do we need this
		return (NULL);
	}
	stash = save;
	line = fetch_line(stash);//what happens when line is NULL?
	stash = handle_remains(stash, line);
	return (line); //gnl returns a string, doesnt print it
}

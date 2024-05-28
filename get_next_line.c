/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:21:37 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/28 17:26:58 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_remains(char *stash, char *line)
{
	char	*remains;
	int		i;
	int		j;

	if (!line)
		return (free(stash), NULL);
	i = ft_strlen(line);
	if (!stash[i])
		return (free(stash), NULL);
	j = 0;
	while (stash[i++])
		j++;
	remains = ft_calloc(j + 1, sizeof(char));
	if (!remains)
		return (free(stash), NULL);
	j = 0;
	i = ft_strlen(line);
	while (stash[i])
		remains[j++] = stash[i++];
	remains[j] = '\0';
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
		return (NULL);
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
	while (!newline_check(stash) && chars_read != 0)
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

	if (fd < 0 || BUFFER_SIZE < 0 || fd > OPEN_MAX)
		return (NULL);
	save = read_file(fd, stash);
	if (!save)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = save;
	line = fetch_line(stash);
	stash = handle_remains(stash, line);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>

// // __attribute__((destructor))
// // static void destructor() {
// //     system("leaks -q a.out");
// // }

// int main(void)
// {
// 	int     fd;
// 	char    *next_line;
// 	int     count;

// 	count = 0;
// 	fd = open("lines.txt", O_RDONLY);
// 	printf("fd equals %d\n", fd);
// 	if (fd == -1)
// 	{
// 		printf("%s", "Error opening file");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		next_line = get_next_line(fd);
// 		if (next_line == NULL)
// 		{
// 			break;
// 		}
// 		count++;
// 		printf("[%d]:%s\n", count, next_line);
// 		free(next_line);
// 		next_line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:21:37 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/18 18:02:51 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_remains(char *stash, char *line)
{
	char	*remains;
	int		i;

	i = 0;
	if (!line)
		return(free(line), free(stash), NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
	{
		while (stash[i])
			*remains++ = stash[i++]
	}
}

char	*fetch_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
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
	while (!check_newline(stash) && !chars_read) //if no new line or if not at EOF when reading
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); //allocating memory for buffer + the null to make it a string
		if (!buffer)
			return (NULL);
		chars_read = (int)read(fd, buffer, BUFFER_SIZE);
		if ((!stash && chars_read == 0) || chars_read == -1) //return null only if stash is null and reading 0 bytes or if there is an error
			return (free(buffer), NULL);
		buffer[chars_read] = '\0'; //if stash is not null but read finds an EOF, the buffer only contains a null char
		stash = ft_strjoin(stash, buffer);
	} 
	return (stash); //if there is a newline in stash or EOF at the beginning of read (ie just after)
}
	
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	save = read_file(fd, stash);
	if (!save) //we have to free the previously allocated stash in case of error, not just return null and leave stash to be
	{
		if (stash)
			free(stash);
		stash = NULL; //WHY DO WE NEED THIS
		return (NULL);
	}
	stash = save; //as strjoin has created a NEW stash!!
	line = fetch_line(stash); //to print the line. -> handle remains has to handle the NULL case.
	stash = handle_remains(stash, line); //stash takes the value of remains, as its what's left to print!
	return (line); //gnl returns a string, doesnt print it
}

//read in chunks of buffer, append them and then search for new lines
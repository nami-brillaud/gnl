/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:21:37 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/18 16:20:23 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fetch_line(char *stash)
{
	char	*line;
	int		len;

	while (*stash != '\n' || *stash != EOF) //include the n
}

char	*save_in_stash(int fd, char *stash)
{
	char	*buffer;
	int		chars_read;

	chars_read = 1;
	while (!check_newline(stash) && !chars_read) //its a while because buffer size might be small compared to input. we have to continue until a newline is in stash
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); //allocating memory for buffer + the null to make it a string
		if (!buffer)
			return (NULL);
		chars_read = (int)read(fd, buffer, BUFFER_SIZE);
		if (chars_read == 0 || chars_read == -1) //nothing to read i.e. EOF or error - CHECK BACK ON THIS (dont understand yet)
			return (free(buffer), NULL);
		buffer[chars_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	} 
	return (stash); //if there is a newline in stash, skip directly here
}
	
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	save = save_in_stash(fd, stash);
	if (!save) //we have to free the previously allocated stash in case of error, not just return null and leave stash to be
	{
		if (stash)
			free (stash);
		stash = NULL; //do we need this
		return (NULL);
	}
	stash = save; //as strjoin has created a NEW stash!!
	line = fetch_line(stash); //to print the line
	save = handle_remains(stash, line); //update save to the remains
	return (line); //gnl returns a string, doesnt print it
}

//read in chunks of buffer, append them and then search for new lines
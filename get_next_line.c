/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:21:37 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/18 15:29:37 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_in_stash(int fd, char *stash)
{
	char	*buffer;
	int		chars_read;

	chars_read = 1;
	while (!check_newline(stash) && !chars_read) //its a while because buffer size might be small compared to input. we have to continue until a newline is in stash
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char)); //allocating memory for buffer + the null to make it a string
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

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	save = save_in_stash(fd, stash);
	if (!save)
		return (NULL);
}

//read in chunks of buffer, append them and then search for new lines
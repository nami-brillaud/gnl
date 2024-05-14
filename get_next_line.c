/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:21:37 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/14 20:05:02 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_in_stash(int fd, char *stash)
{
	char	*buffer;
	int		chars_read;

	if (!check_newline(stash) && !chars_read)
	{
		buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char)); //allocating memory for buffer + the null to make it a string
		if (!buffer)
			return (NULL);
		chars_read = read(fd, buffer, BUFFER_SIZE);
	} 
	

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:36:58 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/19 17:53:10 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_ptr;
	char	c_char;

	s_ptr = (char *)s;
	c_char = (char)c;
	if (c_char == '\0')
	{
		while (*s_ptr)
		{
			s_ptr++;
		}
		return (s_ptr);
	}
	else
	{
		while (*s_ptr)
		{
			if (*s_ptr == c_char)
				return (s_ptr);
			else
				s_ptr++;
		}
		return (NULL);
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	char here[50] = "here there is a needle";
// 	char search = 'n';
// 	printf("%s\n", ft_strchr(here, search));
// 	return (0);
// }

// int main(void)
// {
// 	char *string = NULL;
// 	int c = 'a';
// 	ft_strchr(string, c);
// 	return (0);
// }
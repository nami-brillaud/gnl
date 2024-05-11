/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:49:01 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/19 17:53:10 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_character;
	char	*s_ptr;
	char	c_char;

	last_character = NULL;
	s_ptr = (char *)s;
	c_char = (char)c;
	while (*s_ptr)
	{
		if (*s_ptr == c_char)
			last_character = s_ptr;
		s_ptr++;
	}
	if (c_char == '\0')
		return ((char *)s_ptr);
	else
		return (last_character);
}

// #include <stdio.h>
// int main(void)
// {
// 	char here[50] = "here there is a needle";
// 	char search = 'e';
// 	printf("%s\n", ft_strrchr(here, search));
// 	return (0);
// }

// int main(void)
// {
// 	char *string = NULL;
// 	int c = 'a';
// 	ft_strchr(string, c);
// 	return (0);
// }
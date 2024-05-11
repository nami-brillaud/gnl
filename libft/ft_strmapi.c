/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:33:57 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/29 16:34:15 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*new_string;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	new_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_string[i] = (*f)(i, s[i]);
		i++;
	}
	new_string[len] = '\0';
	return (new_string);
}

// #include <stdio.h>
// char	test_function(unsigned int i, char c)
// {
// 	if (c >= 'A' && c <= 'Z')
// 		c += 32;
// 	return (c);
// }
// 
// int main (void)
// {
// 	char s[] = "ABC";
// 	char *result;

// 	result = ft_strmapi(s, test_function);
// 	printf("%s\n", result);
// 	free(result);
// }
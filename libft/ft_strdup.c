/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:47:35 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/30 20:06:08 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < ft_strlen(src))
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>
// int	main()
// {
// 	char src[10] = "youhou";
// 	char *copy = ft_strdup(src);

// 	if (copy == NULL)
// 		printf("Memory allocation issue");
// 		// you cant really test it??
// 	else
// 	{
// 		printf("the copy contains %s", ft_strdup(src));
// 		free(copy); //only free in case where not null
// 	}
// 	return(0);
// }
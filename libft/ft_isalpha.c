/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:58:57 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/17 19:16:48 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// 	int test;

// 	test = 'a' + 256; // 97 + 256 - should overflow i.e. return 0
// 	printf("mine %d\n", ft_isalpha(test));
// 	printf("real %d\n", isalpha(test));
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:52:08 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/29 19:25:47 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}

// void	del_function(void *content)
// {
// 	if (content)
// 		free(content);
// }

// #include <stdio.h>
// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }

// int main(void)
// {
// 	t_list	*test = ft_lstnew(ft_strdup("Hey")); 
// //double malloc here so that the content has a malloc 
// //and the node itself has a malloc
// 	printf("Before deletion:\n");
// 	print_list(test);
// 	ft_lstdelone(test, del_function);
// 	printf("\nAfter deletion:\n");
// 	return (0);
// }

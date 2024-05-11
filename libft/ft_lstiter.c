/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:27:55 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/29 20:38:50 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>
// void	print_content(void *content)
// {
// 	// function which conveniently prints content
// 	printf("%s\n", (char *)content);
// }

// void	del_function(void *content)
// {
// 	if (content)
// 		free(content);
// }

// int main(void)
// {
// 	t_list	*test = ft_lstnew(ft_strdup("Hey"));
// 	t_list	*new = ft_lstnew(ft_strdup("Yay"));
// 	ft_lstadd_front(&test, new);
// 	printf("Before iteration:\n");
// 	ft_lstiter(test, print_content);
// 	ft_lstclear(&test, del_function); //frees list
// 	return (0);
// }	
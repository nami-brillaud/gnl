/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:37:55 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/30 19:02:13 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !(*lst) || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		(*del)(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

// void	del_function(void *content)
// {
// 	if (content)
// 		free(content);
// }

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	t_list	*test = ft_lstnew(strdup("Hey"));
// 	t_list	*new = ft_lstnew(strdup("Yay"));
// 	ft_lstadd_front(&test, new);

// 	printf("Before clearing:\n");
//  for (t_list *tmp = test; tmp != NULL; tmp = tmp->next)
//   {
//         printf("%s\n", (char *)tmp->content);
//   }
//     // Clear the list
//     ft_lstclear(&test, del_function);
//     printf("\nAfter clearing:\n");
//     for (t_list *tmp = test; tmp != NULL; tmp = tmp->next)
//     {
//         printf("%s\n", (char *)tmp->content); 
// // This should not print anything
//     }
//     return (0);
// }
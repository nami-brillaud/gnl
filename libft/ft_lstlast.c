/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:49:48 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/30 19:47:34 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list	*test = ft_lstnew(ft_strdup("Hey"));
// 	t_list	*new = ft_lstnew(ft_strdup("Yay"));
// 	ft_lstadd_front(&test, new);
// 	t_list	*last = ft_lstlast(new);
// 	printf("The last node's content is %s\n", (char *)last->content);
// 	printf("The last node points to %s\n", (char *)last->next); 
// //printing as str so its readable
// 	printf("%s\n", "verification phase - printing out everything in the list");
// 	for (t_list *tmp = new; tmp != NULL;)
// 	{
// 		t_list *save_next = tmp->next; 
// 		printf("%s\n", (char *)tmp->content);
// 		free(tmp);
// 		tmp = save_next;
// 	}
// 	return (0);
// }
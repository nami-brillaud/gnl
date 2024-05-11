/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:41:40 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/30 19:45:27 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list	*test = ft_lstnew(ft_strdup("Hey"));
// 	t_list	*new = ft_lstnew(ft_strdup("Yay"));
// 	ft_lstadd_front(&test, new);
// 	for (t_list *tmp = new; tmp != NULL;)
// 	{
// 		t_list *save_next = tmp->next; 
// 		//save next pointer (first one is new.next i.e. the pointer to test)
// 		printf("%s\n", (char *)tmp->content); //prints new.content
// 		free(tmp); //frees new
// 		tmp = save_next; //goes to test
// 	}
// 	return (0);
// }
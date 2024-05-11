/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:23:26 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/30 19:44:29 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst ||!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list	*test = ft_lstnew(ft_strdup("Hey"));
// 	t_list	*back = ft_lstnew(ft_strdup("end_node"));
// 	ft_lstadd_back(&test, back);
// 	for (t_list *tmp = test; tmp != NULL;)
// 	{
// 		t_list *save_next = tmp->next; 
// 		printf("%s\n", (char *)tmp->content);
// 		free(tmp);
// 		tmp = save_next;
// 	}
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:34 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/30 19:48:38 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list	*test = ft_lstnew(ft_strdup("Hey"));
// 	t_list	*new = ft_lstnew(ft_strdup("Yay"));
// 	ft_lstadd_front(&test, new);
// 	printf("List count is %d\n", ft_lstsize(new));
// 	for (t_list *tmp = new; tmp != NULL;)
// 	{
// 		t_list *save_next = tmp->next; 
// 		printf("%s\n", (char *)tmp->content);
// 		free(tmp);
// 		tmp = save_next;
// 	}
// 	return (0);
// }
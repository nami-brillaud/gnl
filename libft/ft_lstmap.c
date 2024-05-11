/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:56:09 by nfujisak          #+#    #+#             */
/*   Updated: 2024/05/01 18:27:14 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del || !(*lst))
		return ;
	rec_lstclear(&(*lst)->next, del);
	(del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			(*del)(new_content);
			rec_lstclear(&new_list, (*del));
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void	del_function(void *content)
// {
// 	if (content)
// 		free(content);
// }
//
// #include "libft.h"
// #include <stdio.h>

// void	*to_uppercase(void *content)
// {
// 	char	*str;
// 	char	*upper_str;
// 	size_t	len;
// 	size_t	i;

// 	if (!content)
// 		return (NULL);
// 	str = (char *)content;
// 	len = ft_strlen(str);
// 	upper_str = (char *)malloc(len + 1);
// 	if (!upper_str)
// 		return (NULL);
// 	for (i = 0; i < len; i++)
// 		upper_str[i] = ft_toupper(str[i]);
// 	upper_str[len] = '\0';
// 	return (upper_str);
// }

// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }

// int	main(void)
// {
// 	t_list	*list = NULL;
// 	t_list	*node1 = ft_lstnew("hey");
// 	t_list	*node2 = ft_lstnew("there");
// 	ft_lstadd_back(&list, node1);
// 	ft_lstadd_back(&list, node2);

// 	t_list	*upper_list = ft_lstmap(list, &to_uppercase, &free);

// 	printf("Original list:\n");
// 	print_list(list);

// 	printf("\nUppercase list:\n");
// 	print_list(upper_list);

// 	return (0);
// }

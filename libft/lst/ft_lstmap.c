/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:12:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 20:36:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_lst.h"

static t_list	*node_map(\
					t_list *node, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_lst;
	t_list	*new_lst_end;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new = node_map(lst, f, del);
		if (new == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (new_lst == NULL)
			new_lst = new;
		else
			new_lst_end->next = new;
		new_lst_end = new;
		lst = lst->next;
	}
	return (new_lst);
}

static t_list	*node_map(t_list *node, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	void	*new_content;

	new_content = f(node->content);
	if (new_content == NULL && node->content != NULL)
		return (NULL);
	new = ft_lstnew(new_content);
	if (new == NULL)
	{
		if (new_content != node->content)
			del(new_content);
		return (NULL);
	}
	return (new);
}

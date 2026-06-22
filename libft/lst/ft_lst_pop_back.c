/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 01:04:46 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 20:38:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_lst.h"

void	*ft_lst_pop_back(t_list **lst)
{
	void	*content;
	t_list	*prev;
	t_list	*node;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	prev = NULL;
	node = *lst;
	while (node->next != NULL)
	{
		prev = node;
		node = node->next;
	}
	content = node->content;
	if (prev == NULL)
		*lst = NULL;
	else
		prev->next = NULL;
	free(node);
	return (content);
}

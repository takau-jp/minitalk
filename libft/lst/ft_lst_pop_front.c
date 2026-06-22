/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 01:11:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 20:38:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_lst.h"

void	*ft_lst_pop_front(t_list **lst)
{
	void	*content;
	t_list	*node;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	node = *lst;
	content = node->content;
	*lst = node->next;
	free(node);
	return (content);
}

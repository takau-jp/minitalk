/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 01:17:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 20:38:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_lst.h"

bool	ft_lst_push_front(t_list **lst, void *content)
{
	t_list	*new;

	if (lst == NULL)
		return (false);
	new = ft_lstnew(content);
	if (new == NULL)
		return (false);
	ft_lstadd_front(lst, new);
	return (true);
}

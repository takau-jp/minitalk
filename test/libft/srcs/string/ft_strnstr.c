/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:28:24 by stanaka2          #+#    #+#             */
/*   Updated: 2025/04/29 15:13:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	if (!len)
		return (NULL);
	i = 0;
	little_len = ft_strlen(little);
	while (big[i] && i + little_len <= len)
	{
		if (!ft_strncmp(big + i, little, little_len))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

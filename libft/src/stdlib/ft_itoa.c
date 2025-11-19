/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:41:20 by stanaka2          #+#    #+#             */
/*   Updated: 2025/06/29 08:52:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n);

char	*ft_itoa(int n)
{
	char			*num;
	unsigned int	un;
	int				digit;

	digit = count_digit(n);
	num = (char *)malloc(digit + 1);
	if (!num)
		return (NULL);
	num[digit] = '\0';
	un = n;
	if (n < 0)
		un = -n;
	while (digit--)
	{
		num[digit] = (un % 10) + '0';
		if (n < 0 && digit == 1)
		{
			num[0] = '-';
			break ;
		}
		un /= 10;
	}
	return (num);
}

static int	count_digit(int n)
{
	int	digit;

	if (!n)
		return (1);
	digit = 0;
	if (n < 0)
		digit = 1;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

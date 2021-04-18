/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 01:26:53 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/13 01:43:04 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memchr_pos(const void *str, int c, size_t n)
{
	int			pos;
	const char	*s;

	pos = 0;
	s = (const char *)str;
	while (n--)
	{
		if (s[pos] == (unsigned char)c)
			return (pos);
		pos++;
	}
	return (-1);
}

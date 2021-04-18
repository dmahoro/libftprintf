/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_firstwordlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:40:27 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/02 01:44:24 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_firstwordlen(char *str, size_t start, char *sep)
{
	char	sep_map[32];
	size_t	count;
	size_t	pos;

	count = 0;
	pos = start;
	ft_bit_map(sep_map, 32, sep);
	while (str[pos])
	{
		if (ft_bit_at(sep_map, str[pos]))
			return (count);
		count = count + 1;
		pos = pos + 1;
	}
	return (count);
}

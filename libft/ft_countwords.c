/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:34:22 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/02 04:06:33 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char *str, char *sep)
{
	size_t	word;
	size_t	count;
	size_t	pos;
	char	sep_map[32];

	pos = 0;
	count = 0;
	word = 0;
	ft_bit_map(sep_map, 32, sep);
	while (str[pos])
	{
		if (word == 0 && !ft_bit_at(sep_map, str[pos]))
		{
			word = 1;
			count = count + 1;
		}
		if (ft_bit_at(sep_map, str[pos]))
			word = 0;
		pos++;
	}
	return (count);
}

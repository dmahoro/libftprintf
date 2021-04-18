/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:11:39 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/03/26 23:49:35 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bit_map(void *arr, size_t size, const char *set)
{
	const unsigned char	*s;
	unsigned char		*map;

	s = (unsigned char *)set;
	map = arr;
	ft_bzero(map, size);
	while (*s)
	{
		map[*s / 8] |= 0x80 >> *s % 8;
		s++;
	}
}

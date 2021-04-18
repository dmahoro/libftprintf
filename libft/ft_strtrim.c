/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:28:21 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/01 00:23:29 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	map[32];
	size_t	n;
	size_t	pos;

	ft_bit_map(map, 32, set);
	pos = 0;
	while (ft_bit_at(map, s1[pos]))
		pos++;
	if (!s1[pos])
		return (ft_strnew(0));
	n = ft_strlen((s1 + pos));
	while (ft_bit_at(map, s1[pos + (n - 1)]))
		n--;
	return (ft_substr(s1, pos, n));
}

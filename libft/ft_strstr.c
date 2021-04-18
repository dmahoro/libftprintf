/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 22:25:05 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/02 22:25:10 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;

	s2_len = ft_strlen(s2);
	if (!s2_len)
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	while (s1_len >= s2_len)
	{
		s1_len--;
		if (!ft_memcmp(s1, s2, s2_len))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:38:56 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/03/25 13:39:01 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	size_t		n;

	n = ft_strlen(s);
	p = s + n;
	n++;
	while (n-- && *p != (char)c)
		if (p-- == s)
			return (NULL);
	return ((char *)p);
}

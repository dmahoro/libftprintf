/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:57:26 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/02 16:56:28 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
		((unsigned char *)src)[pos++] = (unsigned char)c;
	return (src);
}

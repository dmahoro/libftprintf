/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 04:17:06 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/02 13:57:59 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fillstr(unsigned int numb, size_t i, size_t neg, int base)
{
	char	*b;
	char	*s;

	b = "0123456789ABCDEF";
	s = (char *)malloc(i + neg + 1);
	if (s)
	{
		s[0] = '-';
		s[i + neg] = '\0';
		while (i--)
		{
			s[i + neg] = b[numb % base];
			numb /= base;
		}
	}
	return (s);
}

char	*ft_itoa_base(int n, int base)
{
	char			*b;
	unsigned int	numb;
	unsigned int	buff;
	size_t			i;

	if (base < 2 || base > 16)
		return (NULL);
	b = "0123456789ABCDEF";
	if (n < 0)
		numb = -n;
	else
		numb = n;
	buff = numb;
	i = 1;
	numb /= base;
	while (numb)
	{
		numb /= base;
		i++;
	}
	numb = buff;
	n = n < 0 && base == 10;
	return (ft_fillstr(numb, i, n, base));
}

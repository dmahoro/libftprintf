/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:56:28 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/05/03 22:59:38 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_wcrtomb(char *b, wchar_t c)
{
	int	i;

	i = 1;
	if (c < 0x80)
		b[0] = c;
	else if (++i && c < 0x800)
	{
		b[0] = 0xc0 | c >> 6;
		b[1] = 0x80 | (c >> 0 & 0x3f);
	}
	else if (++i && c < 0x10000)
	{
		b[0] = 0xe0 | c >> 12;
		b[1] = 0x80 | (c >> 6 & 0x3f);
		b[2] = 0x80 | (c >> 0 & 0x3f);
	}
	else if (++i)
	{
		b[0] = 0xf0 | c >> 18;
		b[1] = 0x80 | (c >> 12 & 0x3f);
		b[2] = 0x80 | (c >> 6 & 0x3f);
		b[3] = 0x80 | (c >> 0 & 0x3f);
	}
	return (i);
}

int	pf_wclen(const wchar_t c)
{
	if (c < 0x80)
		return (1);
	else if (c < 0x800)
		return (2);
	return (4 - (c < 0x10000));
}
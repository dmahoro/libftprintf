/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:43:04 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/05/03 22:49:50 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_case(int i)
{
	if (i < 10)
		return (i + '0');
	else
		return (i + (lower + 'A' - 10));
}

char	*pf_convert(t_pf_format *f, uint64_t n, int base, int lower)
{
	char	*d;
	int		i;
	int		c;

	if (lower)
		lower = 32;
	d = f->conv + PF_CONVERT_BUFF_SIZE;
	c = 0;
	if (!n && f->precision)
		*--d = '0';
	while (n)
	{
		if ((f->flags & PF_FL_APOSTROPHE) && ++c == 4)
		{
			*--d = ',';
			c = 1;
		}
		i = n % base;
		*--d = handle_case(i);
		n /= base;
	}
	f->dsize = f->conv + PF_CONVERT_BUFF_SIZE - d;
	return (d);
}

int64_t	pf_va_arg(t_flag flags, va_list valst)
{
	int64_t	n;

	if ((flags & PF_FL_LL) || (flags & PF_FL_L))
		n = va_arg(l, int64_t);
	else
		n = va_arg(l, int32_t);
	return (n);
}

uint64_t	pf_va_arg_unsigned(t_flag flags, va_list valst)
{
	uint64_t	n;

	if ((flags & PF_FL_LL) || (flags & PF_FL_L))
		n = va_arg(l, uint64_t);
	else
		n = va_arg(l, uint32_t);
	return (n);
}

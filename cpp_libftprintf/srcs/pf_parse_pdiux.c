/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_pdiux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:13:11 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/05/06 17:42:45 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_set_fields(t_pf_format *f, int hlen)
{
	if (f->precision >= 0 || (f->flags & PF_MINUS))
		f->flags &= ~PF_ZERO;
	f->precision -= f->dsize;
	if (f->precision < 0)
		f->precision = 0;
	if (f->flags & PF_HASH)
		hlen += f->dsize + f->precision;
	else
		hlen = f->dsize + f->precision;
	f->width -= hlen;
	if (f->width < 0)
		f->width = 0;
	if (f->flags & PF_ZERO)
	{
		f->precision = f->width;
		f->width = 0;
	}
}

void	pf_parse_p(t_pf_format *f, uint64_t n)
{
	const char	*s;

	f->flags |= PF_LL;
	s = pf_convert(f, n, 16, 1);
	f->flags |= PF_HASH;
	pf_set_fields(f, 2);
	pf_print(f, s, "0x");
}

void	pf_parse_di(t_pf_format *f, int64_t n)
{
	const char	*h;
	const char	*s;

	if (n < 0)
	{
		s = pf_convert(f, -n, 10, 1);
		h = "-";
	}
	else
	{
		s = pf_convert(f, n, 10, 1);
		if (f->flags & PF_PLUS)
			h = "+";
		else if (f->flags & PF_SPACE)
			h = " ";
		else
			h = 0;
	}
	if (h)
		f->flags |= PF_HASH;
	else
		f->flags &= ~PF_HASH;
	pf_set_fields(f, 1);
	pf_print(f, s, h);
}

void	pf_parse_u(t_pf_format *f, uint64_t n)
{
	const char	*s;

	s = pf_convert(f, n, 10, 1);
	pf_set_fields(f, 0);
	pf_print(f, s, 0);
}

void	pf_parse_x(t_pf_format *f, uint64_t n)
{
	const char	*s;

	s = pf_convert(f, n, 16, *f->s == 'x');
	if (!n && (f->flags & PF_HASH))
		f->flags &= ~PF_HASH;
	pf_set_fields(f, 2);
	if (*f->s == 'x')
		pf_print(f, s, "0x");
	else
		pf_print(f, s, "0X");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:11:41 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/05/06 17:34:04 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	pf_parse_ls(t_pf_format *f, wchar_t *s)
{
	int	i;

	if (!s)
		s = L"(null)";
	i = 0;
	while (s[i++] != L'\0' && (f->precision < 0
			|| (f->precision >= 0 && f->dsize
				+ pf_wclen(s[i]) <= f->precision)))
		f->dsize += pf_wclen(s[i]);
	if (f->precision >= 0 || (f->flags & PF_MINUS))
		f->flags = ~PF_ZERO;
	if ((f->precision >= 0) && (f->precision < f->dsize))
		f->dsize = f->precision;
	f->width -= f->dsize;
	if (f->width < 0)
		f->width = 0;
	if (!(f->flags & PF_MINUS))
		pf_putpadding(f);
	f->dsize -= pf_wclen(*s);
	while (f->dsize >= 0)
		pf_putwchar(f, *s++);
}

void	pf_parse_c(t_pf_format *f)
{
	wchar_t	c;

	if (*f->s == '%')
		c = '%';
	else if (f->flags & PF_L)
		c = va_arg(f->valst, wchar_t);
	else
		c = (char)va_arg(f->valst, int);
	f->s++;
	if ((c < 0 && (f->flags & PF_L)) || c > 0x10ffff)
	{
		f->pf_flags |= PF_ERROR;
		return ;
	}
	f->width -= pf_wclen(c);
	if (f->width < 0)
		f->width = 0;
	if (!(f->flags & PF_MINUS))
		pf_putpadding(f);
	pf_putwchar(f, c);
	if (f->flags & PF_MINUS)
		pf_putpadding(f);
}

void	pf_parse_s(t_pf_format *f, char *s)
{
	f->dsize = 0;
	if (f->flags & PF_L)
		pf_parse_ls(f, (wchar_t *)s);
	else
	{
		if (!s)
			s = "(null)";
		f->dsize = ft_strlen(s);
		if (f->precision >= 0 || (f->flags & PF_MINUS))
			f->flags &= ~PF_ZERO;
		if (f->precision >= 0)
			if (f->precision < f->dsize)
				f->dsize = f->precision;
		f->width -= f->dsize;
		if (f->width < 0)
			f->width = 0;
		if (!(f->flags & PF_MINUS))
			pf_putpadding(f);
		while (f->dsize--)
			pf_putchar(f, *s++);
	}
	if (f->flags & PF_MINUS)
		pf_putpadding(f);
	f->s++;
}

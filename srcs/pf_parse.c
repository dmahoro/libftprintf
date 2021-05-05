/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:10:58 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/05/06 01:46:21 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	pf_parse_field(t_pf_format *f)
{
	int		precision;
	long	n;

	n = 0;
	precision = *f->s == '.';
	if (precision)
		++f->s;
	if (*f->s == '*' && *f->s++)
		n = va_arg(f->valst, int);
	else
		while (ft_isdigit(*f->s))
			n = n * 10 + (*f->s++ - '0');
	if (n >= 0)
		return (n);
	if (precision)
		n = -1;
	else
	{
		n = -n;
		f->flags |= PF_MINUS;
	}
	return (n);
}

static t_flag	handle_L_LL(const t_flag flags)
{
	if (flags & PF_L)
		return (PF_LL);
	else
		return (PF_L);
}

static int	pf_parse_subflags(t_pf_format *f)
{
	if (*f->s == '-')
		f->flags |= PF_MINUS;
	else if (*f->s == '0')
		f->flags |= PF_ZERO;
	else if (*f->s == '#')
		f->flags |= PF_HASH;
	else if (*f->s == '\'')
		f->flags |= PF_APOSTROPHE;
	else if (*f->s == ' ')
		f->flags |= PF_SPACE;
	else if (*f->s == '+')
		f->flags |= PF_PLUS;
	else if (*f->s == 'l')
		f->flags |= handle_L_LL(f->flags);
	else if (*f->s == 'h')
	{
		if (f->flags & PF_H)
			f->flags |= PF_HH;
		else
			f->flags |= PF_H;
	}
	else
		return (0);
	++f->s;
	return (1);
}

static int	pf_parse_flags(t_pf_format *f)
{
	++f->s;
	f->flags = 0;
	f->precision = -1;
	f->width = 0;
	while (*f->s)
	{
		if (*f->s == '*' || (*f->s >= '1' && *f->s <= 9))
			f->width = pf_parse_field(f);
		else if (*f->s == '.')
			f->precision = pf_parse_field(f);
		else if (!pf_parse_subflags(f))
			break ;
	}
	return (1);
}

void	pf_parse(t_pf_format *f)
{
	while (*f->s && !(f->pf_flags & PF_ERROR))
	{
		if (*f->s != '%')
			pf_putchar(f, *f->s++);
		else if ((pf_parse_flags(f) && *f->s == '%') || *f->s == 'c')
			pf_parse_c(f);
		else if (*f->s == 's')
			pf_parse_s(f, va_arg(f->valst, char *));
		else if (*f->s == 'p')
			pf_parse_p(f, (uint64_t)va_arg(f->valst, void *));
		else if (*f->s == 'd' || *f->s == 'i')
			pf_parse_di(f, pf_va_arg(f->flags, f->valst));
		else if (*f->s == 'u')
			pf_parse_u(f, pf_va_arg_unsigned(f->flags, f->valst));
		else if (*f->s == 'x' || *f->s == 'X')
			pf_parse_x(f, pf_va_arg_unsigned(f->flags, f->valst));
	}
}

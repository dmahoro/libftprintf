/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:03:24 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/05/03 20:18:11 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	t_pf_format	f;

	pf_init(&f, format, args);
	f.fd = fd;
	pf_parse(&f);
	if (f.i)
		pf_flush_buffer(&f);
	if (f->pf_flags & PF_ERROR)
		return (-1);
	else
		return (f->size);
}

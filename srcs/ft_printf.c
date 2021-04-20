/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:08:50 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/19 23:28:53 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list	args;
	int		n;

	va_start(args, format);
	n = ft_vdprintf(STDOUT_FILENO);
	va_endl(l);
	return (n);
}

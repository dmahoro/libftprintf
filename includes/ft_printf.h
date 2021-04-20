/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:01:42 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/19 23:28:59 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

typedef enum e_pf_flags
{
	PF_FL_INIT = 0,
	PF_FL_HASH = 1,
	PF_FL_ZERO = 2,
	PF_FL_MINUS = 4,
	PF_FL_PLUS = 8,
	PF_FL_SPACE = 16,
	PF_FL_BIN = 32,
} t_pf_flags;

typedef enum e_pf_mod_len
{
	PF_ML_INIT 
} t_pf_mod_len;

typedef struct s_pf_format
{
	va_list		argsptrs;
	size_t		buff_len;
	size_t		i;
	size_t		malloc_len;
	t_pf_flags	flags;
} t_pf_format;


int		ft_printf(char const *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list ap);

#endif

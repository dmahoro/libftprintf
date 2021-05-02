/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:01:42 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/30 09:52:02 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

# define PF_BUFF_SIZE 128
# define PF_CONVERT_BUFF_SIZE 80

typedef enum e_flag
{
	PF_MINUS = 0x1,
	PF_ZERO = 0x2,
	PF_APOSTROPHE = 0x4,
	PF_HASH = 0x8,
	PF_SPACE = 0x10,
	PF_PLUS = 0x20,
	PF_L = 0x40,
	PF_LL = 0x80,
	PF_H = 0x100,
	PF_HH = 0x200,
	PF_E_FLAG_MAX = 10
}	t_flag;

typedef enum e_pf_flag
{
	PF_ERROR = 0x1,
	PF_USE_STR = 0x2,
	PF_USE_LEFT = 0x4,
	PF_E_PF_FLAG_MAX = 3
}	t_pf_flag;

typedef struct s_pf_format
{
	char		buff[PF_BUFF_SIZE];
	char		conv[PF_CONVERT_BUFF_SIZE + 1];
	int			i;
	size_t		left;
	const char	*s;
	va_list		valst;
	t_pf_flag 	pf_flags : PF_E_PF_FLAG_MAX;
	int			size;
	int			fd;
	char		*str;
	t_flag		flags: PF_E_FLAG_MAX;
	size_t		dsize;
	int			precision;
	size_t		width;
}	t_pf_format;

int		ft_printf(char const *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list ap);

void		pf_init(t_pf_format *f, const char *format, va_list ap);
char		*pf_convert(t_pf_format *f, uint64_t n, int base, int lower);

void		pf_parse(t_pf_format *f);
void		pf_parse_c(t_pf_format *f);
void		pf_parse_s(t_pf_format *f, char *s);
void		pf_parse_p(t_pf_format *f, uint64_t n);
void		pf_parse_di(t_pf_format *f, int64_t n);
//void		pf_parse_o(t_pf_format *f, uint64_t n);
void		pf_parse_u(t_pf_format *f, uint64_t n);
void		pf_parse_x(t_pf_format *f, uint64_t n);
void		pf_parse_n(t_pf_format *f, int64_t *size);
//void		pf_parse_X(t_pf_format *f);

void		pf_print(t_pf_format *f, const char *s, const char *hash);
void		pf_putchar(t_pf_format *f, const char c);
void		pf_putpadding(t_pf_format *f);
void		pf_putstr(t_pf_format *f, const char *s);
void		pf_putwchar(t_pf_format *f, const wchar_t c);
int64_t		pf_va_arg(t_flag f, va_list argsptrs);
uint64_t	pf_va_arg_unsigned(t_flag, va_list argsptrs);
int		pf_wclen(const wchar_t c);
int		pf_wcrtomb(char *b, wchar_t c);

void		pf_flush_buffer(t_pf_format *f);

#endif

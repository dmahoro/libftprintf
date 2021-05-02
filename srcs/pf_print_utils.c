
#include "ft_printf.h"

void	pf_print(t_pf_format *f, const char *s, const char *hash)
{
	if (!(f->flags & PF_MINUS))
		pf_putpadding(f);
	if (f->flags & PF_HASH)
		pf_putstr(f, hash);
	while (f->precision--)
		pf_putchar(f, '0');
	if (f->dsize)
		pf_putstr(f, s);
	if (f->flags & PF_MINUS)
		pf_putpadding(f);
	++f->s;
}

void	pf_putchar(t_pf_format *f, char const c)
{
	++f->size;
	f->buff[f->i++] = c;
	if (f->i == PF_BUFF_SIZE)
		pf_flush_buffer(f);
}

void	pf_putpadding(t_pf_format *f)
{
	char c;

	c = (f->flags & PF_FL_ZERO) ? '0' : ' ';
	while (f->width--)
		pf_putchar(f, c);
}

void	pf_putwchar(t_pf_format *f, const wchar_t c)
{
	char	b[4];
	int	i;
	int	n;

	n = pf_wcrtomb(b, c);
	i = 0;
	while (i < n)
		pf_putchar(f, b[i++]);	
}

void	pf_putstr(t_pf_format *f, const char *s)
{
	while (*s)
		pf_putchar(f, *s++);
}

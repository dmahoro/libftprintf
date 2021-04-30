
#include "ft_printf.h"

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

int	pf_wclen(const wchar_t c)
{
	if (c < 0x80)
		return (1);
	else if (c < 0x800)
		return (2);
	return (4 - (c < 0x10000));
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

static int	pf_wcrtomb(char *b, wchar_t c)
{
	int i;

	i = 1;
	// 0x3f   :	      111111
	// 0x80   :         10000000
	// 0xc0	  :         11000000
	// 0xe0   :         11100000
	// 0xf0   :         11110000
	// 0x800  :     100000000000
	// 0x1000 :10000000000000000
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


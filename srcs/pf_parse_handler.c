
#include "ft_printf.h"

void	pf_init(t_pf_format *f, const char *format, va_list argsptrs)
{
	f->conv[PF_CONVERT_BUFF_SIZE] = '\0';
	f->i = 0;
	f->s = format;
	va_copy(f->argsptrs, argsptrs);
	f->pf_flags = 0;
	f->size = 0;
}

char	*pf_convert(t_pf_format *f, uint64_t n, int base, int lower)
{
	char	*d;
	int	i;
	int	c;

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
	}
	f->dsize = f->conv + PF_CONVERT_BUFF_SIZE - d;
	return (d);
}

void	pf_parse(t_pf_format *f)
{
	while (*f->s && !(f->pf_flags & PF_ERROR))
		if (*f->s != '%')
			pf_putchar(f, );
}

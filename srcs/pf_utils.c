
#include "ft_printf.h"

void	pf_putchar(t_pf_format *f, char const c)
{
	++f->size;
	f->buff[f->i++] = c;
	if (f->i == PF_BUFF_SIZE)
		pf_flush_buffer(f);
}


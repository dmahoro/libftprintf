
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

void	pf_flush_buffer(t_pf_format *f)
{
	if (f->pf_flags & PF_ERROR)
		return ;
	if (f->pf_flags & PF_USE_STR)
	{
		if (f->pflags & PF_USE_LEFT)
		{
			if (!f->left || f->left - 1 < (size_t)f->i)
			{
				f->i = f->left - (f-left > 0);
				f->left = (f->left > 0);
			}
			else
				f->left -= f->i;
		}
		f->str = (char *)ft_memcpy(f->str, f->buff, f->i) + f->i;
	}
	else if (write(f->fd, f->buff, f->i) < 0)
		f->pf_flags |= PF_ERROR;
	f->i = 0;
}



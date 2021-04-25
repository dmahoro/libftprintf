
#include "ft_printf.h"

int64_t	pf_va_arg(t_flag flags, va_list valst)
{
	int64_t	n;

	if ((flags & PF_FL_LL) || (flags & PF_FL_L))
		n = va_arg(l, int64_t);
	else
		n = va_arg(l, int32_t);
	return (n);
}

uint64_t	pf_va_arg_unsigned(t_flag flags, va_list valst)
{
	uint64_t	n;

	if ((flags & PF_FL_LL) || (flags & PF_FL_L))
		n = va_arg(l, uint64_t);
	else
		n = va_arg(l, uint32_t);
	return (n);
}

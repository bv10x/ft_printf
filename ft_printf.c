#include "ft_printf.h"


int	ft_type(char c, va_list valist)
{
	int	rtn;

	rtn = 0;
	if (!c)
		return (-1);
	if(c == 'd' || c == 'i')
		rtn = ft_putnbr(va_arg(valist, int));
	else if(c == 'c')
		rtn = ft_putchar(va_arg(valist, int));
	else if(c == 's')
		rtn = ft_putstr(va_arg(valist, char *));
	else if(c == 'p')
		rtn = ft_cnvrt(va_arg(valist, unsigned long));
	else if(c == 'u')
		rtn = ft_unbr(va_arg(valist, unsigned int));
	else if(c == 'x')
		rtn = ft_hex(va_arg(valist, unsigned int));
	else if(c == 'X')
		rtn = ft_heX(va_arg(valist, unsigned int));
	else if(c == '%')
		rtn = ft_putchar('%');
	else
			return (-1);
	return (rtn);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	total;
	va_list valist;

	i = 0;
	total = 0;
	if (!s)
		return (-1);
	va_start(valist, s);
	while(s[i])
	{
		if (s[i] == '%')
		{
			total += ft_type(s[i + 1], valist);
		}
		else
		{
			ft_putchar(s[i]);
			total++;
		}
		i++;
	}
	va_end(valist);
	return (total);
}

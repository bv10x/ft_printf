#include "ft_putchar.c"
#include <stdarg.h>
#include "ft_putnbr.c"
#include "ft_deneme.c"

int	ft_type(char c, va_list valist)
{
	int	rtn;

	rtn = 0;
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
}

int	ft_printf(const char *abc, ...)
{
	int	i;
	int	total;
	va_list valist;

	i = 0;
	total = 0;
	va_start(valist, abc);
	while(abc[i])
	{
		if (abc[i] == '%')
		{
			i++;
			total += ft_type(abc[i], valist);
		}
		else
		{
			ft_putchar(abc[i]);
			total++;
		}
		i++;
	}
	return (total);
}

int	main()
{
	char x = 'b';
	int	a = printf("baris");
	printf("\n%c\t%c\n", 'a', x);
	ft_printf("%c\t%c", 'a', x);
}
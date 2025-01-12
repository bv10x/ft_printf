#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include "ft_putchar.c"
#include <stdarg.h>

int	ft_deneme(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		i += ft_deneme(nbr / 16);
	else
		i = write (1, "0x", 2);
	write (1, &"0123456789abcdef"[nbr % 16], 1);
	return (i + 1);
}

int	abc(char *a, ...)
{
	va_list valist;

	va_start(valist, a);
	ft_deneme(va_arg(valist, unsigned long));
}

int	main()
{
	char *a = "adres:";
	char **b;
	b = &a;
	abc(a, &b);
	printf("\n%p\t%p\t%p\t%p\t%p\n",&b ,b , &a, *b, a);
	printf("%d", printf("%w"));
}
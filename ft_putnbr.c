#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	rtn;

	rtn = 0;
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		rtn += ft_putnbr(147483648);
		rtn += 2;
	}
	else if(n < 0)
	{
		ft_putchar('-');
		n *= -1;
		rtn += ft_putnbr(n);
		rtn++;
	}
	else if (n > 9)
	{
		rtn += ft_putnbr(n / 10);
		rtn += ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + 48);
		rtn++;
	}
	return(rtn);
}

int	ft_cnvrt(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		i += ft_cnvrt(nbr / 16);
	else
		i = write (1, "0x", 2);
	write (1, &"0123456789abcdef"[nbr % 16], 1);
	return (i + 1);
}

int	ft_hex(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_hex(nbr / 16);
		i += ft_hex(nbr % 16);
	}
	else
		i += write(1, &"0123456789abcdef"[nbr], 1);
	return(i);
}

int	ft_heX(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_heX(nbr / 16);
		i += ft_heX(nbr % 16);
	}
	else
		i += write(1, &"0123456789ABCDEF"[nbr], 1);
	return(i);
}

int	ft_unbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 9)
	{
		i += ft_unbr(nbr / 10);
		i += ft_unbr(nbr % 10);
	}
	else
		i += write(1, &"0123456789"[nbr], 1);
	return (i);
}

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h> 
# include <stdbool.h>
# include <stdio.h>

int		ft_putstr(char *str);
int	    ft_cnvrt(unsigned long nbr);
int	    ft_unbr(unsigned int nbr);
int	    ft_heX(unsigned int nbr);
int	    ft_hex(unsigned int nbr);
int		ft_putnbr(int nbr);
int		ft_putchar(char c);
int		ft_printf(const char *s, ...);

#endif
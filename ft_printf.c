/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acengiz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:10:10 by acengiz           #+#    #+#             */
/*   Updated: 2022/03/07 12:20:52 by acengiz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char str, va_list variable)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(variable, int));
	else if (str == 's')
		count += ft_str(va_arg(variable, char *));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(variable, int), 10, 0);
	else if (str == 'x')
		count += ft_putnbr(va_arg(variable, unsigned int), 16, 0);
	else if (str == 'X')
		count += ft_putnbr(va_arg(variable, unsigned int), 16, 1);
	else if (str == 'u')
		count += ft_putnbr(va_arg(variable, unsigned int), 10, 0);
	else if (str == 'p')
		count += ft_pointer(va_arg(variable, unsigned long), 16, 0);
	else if (str == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		variable;
	int			count;

	count = 0;
	va_start(variable, str);
	while (*str)
	{
		if (*str == '%')
		{
			count += ft_control(*(str + 1), variable);
			str++;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(variable);
	return (count);   
}
/*
int	main(void)
{
	int	orj;
	int	my;

    my = ft_printf("%%%s\n");
	orj = printf("%%%s\n");
	printf("sayi: %d ---- sayi: %d", orj, my);
}*/

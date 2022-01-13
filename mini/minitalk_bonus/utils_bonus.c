/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:28:27 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/01/13 15:20:57 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk_bonus.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		len += ft_putchar(*s++);
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long	n1;
	int		len;

	len = 0;
	n1 = n;
	if (n1 < 0)
	{
		len += ft_putchar('-');
		n1 *= -1;
	}
	if (n1 >= 0 && n1 <= 9)
	{
		len += ft_putchar(n1 + 48);
	}
	if (n1 >= 10)
	{
		len += ft_putnbr(n1 / 10);
		len += ft_putchar(n1 % 10 + 48);
	}
	return (len);
}

void	affi(char fmt, int *len, va_list ap)
{
	if (fmt == 'c')
		*len -= ft_putchar(va_arg(ap, int));
	else if (fmt == 's')
		*len += ft_putstr(va_arg(ap, char *)) - 2;
	else if (fmt == 'd' || fmt == 'i')
		*len += ft_putnbr(va_arg(ap, int)) - 2;
	else if (fmt == '%')
		*len -= ft_putchar('%');
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = 0;
	while (fmt[len])
		len++;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			affi(*fmt, &len, ap);
			fmt++;
		}
		if (*fmt != '\0' && *fmt != '%')
			ft_putchar(*fmt++);
	}
	va_end(ap);
	return (len);
}

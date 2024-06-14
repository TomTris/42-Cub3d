/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:44:42 by qdo               #+#    #+#             */
/*   Updated: 2024/05/08 00:59:10 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(char *str, va_list args)
{
	if (*str == '%')
		return (ft_putc('%'));
	else if (*str == 'c')
		return (ft_putc(va_arg(args, int)));
	else if (*str == 'p')
		return (ft_putp(va_arg(args, unsigned long)));
	else if (*str == 's')
		return (ft_puts(va_arg(args, char *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_putdi(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_putu(va_arg(args, unsigned int)));
	else if (*str == 'x')
		return (ft_putx(va_arg(args, unsigned int)));
	else if (*str == 'X')
		return (ft_putxx(va_arg(args, unsigned int)));
	else
		return (-1);
}

static int	ft_printf2(char *str, int cnt, va_list args, int cnt_check)
{
	while (*str)
	{
		while (*str && (*str) != '%')
		{
			if (ft_putc(*(str++)) < 0)
				return (-1);
			cnt++;
		}
		if (*str == '%')
		{
			cnt_check = ft_cmp((++str), args);
			if (cnt_check < 0)
				return (-1);
			cnt += cnt_check;
			str++;
		}
	}
	return (cnt);
}

int	ft_printf(const char *str_o, ...)
{
	va_list	args;
	char	*str;
	int		cnt;

	cnt = 0;
	str = (char *)str_o;
	va_start(args, str_o);
	cnt = ft_printf2(str, cnt, args, 0);
	va_end(args);
	return (cnt);
}

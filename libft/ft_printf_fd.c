/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:44:42 by qdo               #+#    #+#             */
/*   Updated: 2024/05/12 00:43:12 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include "libft.h"

static int	ft_cmp(char *str, va_list args, int fd)
{
	if (*str == '%')
		return (ft_putc_fd('%', fd));
	else if (*str == 'c')
		return (ft_putc_fd(va_arg(args, int), fd));
	else if (*str == 'p')
		return (ft_putp_fd(va_arg(args, unsigned long), fd));
	else if (*str == 's')
		return (ft_puts_fd(va_arg(args, char *), fd));
	else if (*str == 'd' || *str == 'i')
		return (ft_putdi_fd(va_arg(args, int), fd));
	else if (*str == 'u')
		return (ft_putu_fd(va_arg(args, unsigned int), fd));
	else if (*str == 'x')
		return (ft_putx_fd(va_arg(args, unsigned int), fd));
	else if (*str == 'X')
		return (ft_putxx_fd(va_arg(args, unsigned int), fd));
	else
		return (-1);
}

static int	ft_printf2(char *str, va_list args, int fd)
{
	int	cnt_check;
	int	cnt;

	cnt = 0;
	cnt_check = 0;
	while (*str)
	{
		while (*str && (*str) != '%')
		{
			if (ft_putc_fd(*(str++), fd) < 0)
				return (-1);
			cnt++;
		}
		if (*str == '%')
		{
			cnt_check = ft_cmp((++str), args, fd);
			if (cnt_check < 0)
				return (-1);
			cnt += cnt_check;
			str++;
		}
	}
	return (cnt);
}

int	print_fd(int fd, const char *str_o, ...)
{
	va_list	args;
	char	*str;
	int		cnt;

	str = (char *)str_o;
	va_start(args, str_o);
	cnt = ft_printf2(str, args, fd);
	va_end(args);
	return (cnt);
}

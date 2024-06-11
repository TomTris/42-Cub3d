/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:34:47 by qdo               #+#    #+#             */
/*   Updated: 2024/05/08 01:01:54 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_write(int n, int cnt, int fd)
{
	char	a;

	if (cnt == -1)
		return (-1);
	if (n >= 10)
		cnt = ft_write(n / 10, cnt + 1, fd);
	if (cnt < 0)
		return (-1);
	n = n % 10;
	a = n + '0';
	if (write(fd, &a, 1) < 0)
		return (-1);
	return (cnt);
}

int	ft_putdi_fd(int n, int fd)
{
	int	cnt;

	cnt = 0;
	if (n == -2147483648)
	{
		if (write(fd, "-2147483648", 11) < 0)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		if (write(fd, "-", 1) < 0)
			return (-1);
		cnt++;
		n *= -1;
	}
	return (ft_write(n, cnt + 1, fd));
}

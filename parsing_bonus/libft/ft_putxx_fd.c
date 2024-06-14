/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxx_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:03:37 by qdo               #+#    #+#             */
/*   Updated: 2024/05/08 01:02:26 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n - 10 + 'A');
}

static int	ft_writexx(unsigned int n, int cnt, int fd)
{
	char	a;

	if (cnt == -1)
		return (-1);
	if (n >= 16)
		cnt = ft_writexx(n / 16, cnt + 1, fd);
	if (cnt < 0)
		return (-1);
	n = n % 16;
	a = ft_n(n);
	if (write(fd, &a, 1) < 0)
		return (-1);
	return (cnt);
}

int	ft_putxx_fd(unsigned int n, int fd)
{
	int	cnt;

	cnt = 0;
	return (ft_writexx(n, cnt + 1, fd));
}

// int	main(void)
// {
// 	printf("\n%x\n", 245645656);
// }
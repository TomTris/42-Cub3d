/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:17 by qdo               #+#    #+#             */
/*   Updated: 2024/05/08 01:02:23 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n - 10 + 'a');
}

static int	ft_writex(unsigned int n, int cnt, int fd)
{
	char	a;

	if (cnt == -1)
		return (-1);
	if (n >= 16)
		cnt = ft_writex(n / 16, cnt + 1, fd);
	if (cnt < 0)
		return (-1);
	n = n % 16;
	a = ft_n(n);
	if (write(fd, &a, 1) < 0)
		return (-1);
	return (cnt);
}

int	ft_putx_fd(unsigned int n, int fd)
{
	int	cnt;

	cnt = 0;
	return (ft_writex(n, cnt + 1, fd));
}
// int	main(void)
// {
// 	printf("original %x\n", 2147483647);
// 	printf("\nlocal\n", ft_putnbrx(2147483648));
// }

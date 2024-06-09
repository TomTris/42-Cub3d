/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:26 by qdo               #+#    #+#             */
/*   Updated: 2024/05/08 01:30:18 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_write(unsigned int n, int cnt, int fd)
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

int	ft_putu_fd(unsigned int n, int fd)
{
	int	cnt;

	cnt = 0;
	return (ft_write(n, cnt + 1, fd));
}

// int	main(void)
// {
// 	printf("\n%d", ft_putunsignbr1(023456789));
// }

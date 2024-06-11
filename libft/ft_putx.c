/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:56:17 by qdo               #+#    #+#             */
/*   Updated: 2024/05/08 01:00:08 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n - 10 + 'a');
}

static int	ft_writex(unsigned int n, int cnt)
{
	char	a;

	if (cnt == -1)
		return (-1);
	if (n >= 16)
		cnt = ft_writex(n / 16, cnt + 1);
	if (cnt < 0)
		return (-1);
	n = n % 16;
	a = ft_n(n);
	if (write(1, &a, 1) < 0)
		return (-1);
	return (cnt);
}

int	ft_putx(unsigned int n)
{
	int	cnt;

	cnt = 0;
	return (ft_writex(n, cnt + 1));
}
// int	main(void)
// {
// 	printf("original %x\n", 2147483647);
// 	printf("\nlocal\n", ft_putnbrx(2147483648));
// }

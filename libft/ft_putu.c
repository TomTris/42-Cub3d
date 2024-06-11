/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:26 by qdo               #+#    #+#             */
/*   Updated: 2024/05/08 01:00:09 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_write(unsigned int n, int cnt)
{
	char	a;

	if (cnt == -1)
		return (-1);
	if (n >= 10)
		cnt = ft_write(n / 10, cnt + 1);
	if (cnt < 0)
		return (-1);
	n = n % 10;
	a = n + '0';
	if (write(1, &a, 1) < 0)
		return (-1);
	return (cnt);
}

int	ft_putu(unsigned int n)
{
	int	cnt;

	cnt = 0;
	return (ft_write(n, cnt + 1));
}

// int	main(void)
// {
// 	printf("\n%d", ft_putunsignbr1(023456789));
// }

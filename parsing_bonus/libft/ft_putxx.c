/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:03:37 by qdo               #+#    #+#             */
/*   Updated: 2024/05/08 01:00:08 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n - 10 + 'A');
}

static int	ft_writexx(unsigned int n, int cnt)
{
	char	a;

	if (cnt == -1)
		return (-1);
	if (n >= 16)
		cnt = ft_writexx(n / 16, cnt + 1);
	if (cnt < 0)
		return (-1);
	n = n % 16;
	a = ft_n(n);
	if (write(1, &a, 1) < 0)
		return (-1);
	return (cnt);
}

int	ft_putxx(unsigned int n)
{
	int	cnt;

	cnt = 0;
	return (ft_writexx(n, cnt + 1));
}

// int	main(void)
// {
// 	printf("\n%x\n", 245645656);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:52:09 by qdo               #+#    #+#             */
/*   Updated: 2024/05/15 20:22:57 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_2147483648(void)
{
	char	*ret;

	ret = (char *)malloc(12 * sizeof(char));
	{
		if (ret == 0)
			return (0);
	}
	ft_strcpy(ret, "-2147483648");
	ret[11] = 0;
	return (ret);
}

static size_t	ft_cnt(int n)
{
	size_t	cnt;

	if (n == 0)
		return (1);
	if (n > 0)
		cnt = 0;
	else
	{
		cnt = 1;
		n *= -1;
	}
	while (n > 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

static void	ft_fill(char *ret, int n, int cnt)
{
	if (n < 0)
		n *= -1;
	ret[cnt--] = 0;
	while (cnt >= 0)
	{
		ret[cnt--] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	cnt;

	if (n == -2147483648)
		return (ft_2147483648());
	cnt = ft_cnt(n);
	ret = (char *)malloc((cnt +1) * sizeof(char));
	if (ret == 0)
		return (NULL);
	if (n < 0)
	{
		ft_strcpy((ret), "-");
		ft_fill(ret + 1, n, cnt - 1);
	}
	else
		ft_fill(ret, n, cnt);
	return (ret);
}

// int	main (void)
// {
// 	printf("%s\n", ft_itoa(2 1 4 7 483647));
// }

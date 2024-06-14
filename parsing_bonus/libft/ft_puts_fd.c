/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:51:38 by qdo               #+#    #+#             */
/*   Updated: 2024/05/15 20:23:51 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putstr1_null(int fd)
{
	if (write(fd, "(null)", 6) < 0)
		return (-1);
	else
		return (6);
}

int	ft_puts_fd(char *s, int fd)
{
	int		len;
	int		len2;
	int		i;

	if (s == NULL)
	{
		return (ft_putstr1_null(fd));
	}
	i = 0;
	len = (int) ft_strlen(s);
	len2 = len;
	while (len > 0)
	{
		if (write(fd, s + i, 1) < 0)
			return (-1);
		else
		{
			len--;
			i++;
		}
	}
	return (len2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:31:45 by qdo               #+#    #+#             */
/*   Updated: 2024/05/21 23:10:17 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 1 && *a != 0 && *b != 0)
	{
		n--;
		if (*a == *b)
		{
			a++;
			b++;
		}
		else
			return (*a - *b);
	}
	return (*a - *b);
}

int	sncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0)
		return (1);
	while (n > 1 && *a != 0 && *b != 0)
	{
		n--;
		if (*a == *b)
		{
			a++;
			b++;
		}
		else if (*a - *b == 0)
			return (1);
		else
			return (0);
	}
	if (*a - *b != 0)
		return (0);
	return (1);
}

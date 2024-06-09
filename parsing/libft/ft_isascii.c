/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:57:34 by qdo               #+#    #+#             */
/*   Updated: 2024/03/06 14:52:38 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a)
{
	if ((a >= 0) && (a < 128))
		return (1);
	else
		return (0);
}
/*int	main(void)
{
	int	a;

	a = -5;
	while (a < 1500)
	{
		if (isascii(a) != ft_isascii(a))
		{
			printf("%d",a);
			break ;
		}
		a++;
	}
	if (a == 1500)
		printf("good");
	return (0);
}*/
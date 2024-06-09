/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:29:54 by qdo               #+#    #+#             */
/*   Updated: 2024/03/06 14:52:43 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int a)
{
	if ((a > 31) && (a < 127))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int	a;

	a = -5;
	while (a < 1770)
	{
		if( isprint(a) != ft_isprint(a))
		{
			printf("%d",a);
			break;
		}
		a++;
	}
	if (a == 1770)
		printf("good");
	return (0);
}*/
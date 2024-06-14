/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 03:44:31 by qdo               #+#    #+#             */
/*   Updated: 2024/03/11 16:37:28 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*a;

	a = s;
	while (n > 0)
	{
		*a = '\0';
		a++;
		n--;
	}
}

// int	main(void)
// {
// 	char	*a;

// 	a = malloc(sizeof("ea4n3f489n2fj23"));

// 	strcpy(a, "ea4n3f489n2fj23");
// 	ft_bzero(a, 5*sizeof(char));
// 	printf("%s",(a+5));
// 	return (0);
// }
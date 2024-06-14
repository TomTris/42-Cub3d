/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 02:52:16 by qdo               #+#    #+#             */
/*   Updated: 2024/03/06 14:52:58 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*a;

	a = b;
	while (len > 0)
	{
		*a = c;
		a++;
		len--;
	}
	return (b);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	char	*a;	

// 	a = malloc(strlen("firstmotivateddayin42"));
// 	strcpy(a, "firstmotivateddayin42");
// 	printf("%d\n", 'p');
// 	printf("%s",ft_memset(a, 'p', 5*sizeof(int)));
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:46:01 by qdo               #+#    #+#             */
/*   Updated: 2024/03/08 17:40:25 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*a;

	a = (char *)s;
	while (n > 0)
	{
		n--;
		if (*a == (char)c)
			return (a);
		a++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*a;
// 	char	*b;
// 	int		n;

// 	a = malloc(30);
// 	b = malloc(30);
// 	strcpy(a, "0120210299904");
// 	strcpy(b, "012000");
// 	*(a+3) = '\0';
// 	*(a+6) = '\0';
// 	*(a+11) = '\0';

// 	n = 8;
// 	while(n > 0)
// 	{
// 		printf("%s\n", memchr(a,'2',1));
// 		printf("%s\n", ft_memchr(a,'2',1));
// 		printf("%s", "----"); printf("%d",n); printf("%s\n", "----");
// 		n--;
// 		a++;
// 	}
// 	return (0);
// }

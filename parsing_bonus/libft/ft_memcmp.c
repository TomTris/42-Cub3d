/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:15:24 by qdo               #+#    #+#             */
/*   Updated: 2024/03/08 15:02:14 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (n >= 1)
	{
		if (*a != *b)
			return (*a - *b);
		n--;
		a++;
		b++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*a;
// 	char	*b;
// 	int		n;

// 	a = malloc(30);
// 	b = malloc(30);
// 	strcpy(a, "0120210295904");
// 	strcpy(b, "0120210290904");

// 	// *(a+3) = '\0';
// 	// *(a+6) = '\0';
// 	// *(a+11) = '\0';
// 	// *(b+3) = '\0';
// 	// *(b+6) = '\0';
// 	// *(b+11) = '\0';

// 	n = 12;
// 	while(n > 0)
// 	{
// 		printf("%d\n", memcmp(a,b,n));
// 		printf("%d\n", ft_memcmp(a,b,n));
// 		printf("%s", "----"); printf("%d",n); printf("%s\n", "----");
// 		n--;
// 	}
// 	return (0);
// }

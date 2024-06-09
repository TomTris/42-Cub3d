/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:02:42 by qdo               #+#    #+#             */
/*   Updated: 2024/03/07 15:57:15 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;

	if (n == 0 || (dst == NULL && src == NULL))
		return (dst);
	a = (char *)dst;
	b = (char *)src;
	while (n > 0)
	{
		n--;
		*a = *b;
		a++;
		b++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	*a;
// 	char	*b;

// 	a = (char *)malloc(30 * sizeof(char));
// 	b = a + 3;
// 	strcpy(a, "1234567890abcdef");
// 	ft_memcpy(b,a,6);
// 	printf("%s\n",a);

// 	a = (char *)malloc(30 * sizeof(char));
// 	b = a + 3;
// 	strcpy(a, "1234567890abcdef");
// 	memcpy(b,a,6);
// 	printf("%s\n",a);

// }

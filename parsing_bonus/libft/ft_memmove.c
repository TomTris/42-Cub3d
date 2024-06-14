/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 05:09:24 by qdo               #+#    #+#             */
/*   Updated: 2024/03/10 16:30:39 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;

	if (len == 0 || (dst == NULL && src == NULL))
		return (dst);
	a = (char *)dst;
	b = (char *)src;
	if (dst < src)
	{
		while (len > 0)
		{
			len--;
			*a = *b;
			a++;
			b++;
		}
		return (dst);
	}
	while (len > 0)
	{
		len--;
		*(a + len) = *(b + len);
	}
	return (dst);
}

// int	main(void)
// {
// 	char	*a;
// 	char	*b;

// 	a = malloc(30);

// 	strcpy(a, "123456789abcd");
// 	b = a + 3;
// 	*(a+7)=0;
// 	*(a+3)=0;
// 	*(a+10)=0;
// 	printf("%s\n", memcpy(a,b,7));
// 	printf("%s\n", a);

// 	strcpy(a, "123456789abcd");
// 	b = a + 3;
// 	*(a+7)=0;
// 	*(a+3)=0;
// 	*(a+10)=0;
// 	printf("%s\n", ft_memmove(a,b,7));
// 	printf("%s\n", a);	

// 	return (0);
// }
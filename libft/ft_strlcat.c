/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:43:37 by qdo               #+#    #+#             */
/*   Updated: 2024/03/10 15:10:32 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen((char *)src);
	dst_len = ft_strlen((char *)dst);
	dst = dst + dst_len;
	if (dstsize <= dst_len + 1)
	{
		if (dstsize == dst_len + 1)
			*dst = '\0';
		if ((src_len + dstsize) <= (src_len + dst_len))
			return (src_len + dstsize);
		return (src_len + dst_len);
	}
	while (dstsize > 1 + dst_len && src_len > 0)
	{
		*dst = *src;
		dst++;
		src++;
		dst_len++;
		src_len--;
	}
	*dst = '\0';
	return (src_len + dst_len);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*b;
// 	int		n;

// 	str = (char *)malloc(40 * sizeof(char));
// 	b = (char *)malloc(40 * sizeof(char));
// 	while (n < 15)
// {	printf("%s","-----");
// 	printf("%d",n);
// 	printf("%s\n","-----");
// 	strcpy(str, "");
// 	strcpy(b,"1111");

// 	printf("%lu\n", strlcat(str,b,n));
// 	printf("%s\n", str);

// 	strcpy(str, "");
// 	strcpy(b,"1111");

// 	printf("%lu\n", ft_strlcat(str,b,n));
// 	printf("%s\n", str);
// 	n++;
// }
// 	return (0);
// }

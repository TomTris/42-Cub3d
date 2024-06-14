/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 05:22:55 by qdo               #+#    #+#             */
/*   Updated: 2024/03/07 15:58:16 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst,
		const char *src, size_t dstsize)
{
	char	*a;
	char	*b;
	int		cnt_src;

	b = (char *) src;
	cnt_src = 0;
	while (*b != '\0')
	{
		cnt_src++;
		b++;
	}
	a = dst;
	while (dstsize > 1 && *src != '\0')
	{
		*a = *src;
		src++;
		a++;
		dstsize--;
	}
	if (dstsize >= 1)
		*a = '\0';
	return (cnt_src);
}
// int	main(void)
// {
// 	char *a;
// 	char *b;

// 	a = (char *)malloc(30 * sizeof(char));
// 	b = (char *)malloc(30 * sizeof(char));
// 	strcpy(a,"");
// 	strcpy(b,"");

// 	printf("%zu\n",strlcpy(a,b,3));

// 	strcpy(a,"");
// 	strcpy(b,"");

// 	printf("%zu\n",ft_strlcpy(a,b,3));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:51:35 by qdo               #+#    #+#             */
/*   Updated: 2024/03/12 15:54:47 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strncmp1(char *a, char *b, size_t len)
{
	while (*a != 0 && *b != 0 && len > 0)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
		len--;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*a;
	char	*b;
	size_t	needle_len;

	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	if (ft_strlen((char *)haystack) == 0)
		return (NULL);
	needle_len = ft_strlen((char *)needle);
	a = (char *) haystack;
	b = (char *) needle;
	while (len > needle_len)
	{
		if (ft_strncmp1(a, b, needle_len) == 0)
			return (a);
		a++;
		len--;
	}
	if (len == needle_len && ft_strncmp1(a, b, needle_len) == 0)
		return (a);
	return (NULL);
}

// int	main(void)
// {
// 	char	*a = "123456";
// 	char	*b = "3456";
// 	int		n;

// 	n = 7;
// 	printf("%s\n",strnstr("3","",n));
// 	printf("%s\n",ft_strnstr("3","",n));
// }

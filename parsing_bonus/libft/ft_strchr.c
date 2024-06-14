/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:37:56 by qdo               #+#    #+#             */
/*   Updated: 2024/05/14 16:13:57 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == '\0')
	{
		while (*s != 0)
			s++;
		return ((char *)s);
	}
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char    *a;

// 	a = malloc(30);
// 	strcpy(a, "1234567890");
// 	printf("%s\n", a);
// 	printf("%s\n", strchr(a, 25));
// 	return (0);
// }
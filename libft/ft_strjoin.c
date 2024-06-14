/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:34:00 by qdo               #+#    #+#             */
/*   Updated: 2024/05/11 20:39:14 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *dest, char const *src)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*a;

	s1_len = ft_strlen((char *)dest);
	s2_len = ft_strlen((char *)src);
	a = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (a == 0)
		return (NULL);
	ft_strcpy(a, (char *)dest);
	ft_strcpy((a + s1_len), (char *)src);
	*(a + s1_len + s2_len) = 0;
	return (a);
}

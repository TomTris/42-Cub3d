/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:04:53 by qdo               #+#    #+#             */
/*   Updated: 2024/05/19 19:39:58 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		(dest[i]) = src[i];
	dest[i] = 0;
	return (dest);
}

void	ft_strncpy(char *dest, char *src, int i)
{
	dest[i] = 0;
	while (--i >= 0)
		dest[i] = src[i];
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 05:10:28 by qdo               #+#    #+#             */
/*   Updated: 2024/05/14 15:42:12 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *dest, char *src, int n)
{
	int		i;
	int		j;
	char	*ret;

	ret = (char *)malloc
		((ft_strlen(dest) + n + 1) * sizeof(char));
	if (ret == 0)
		return (NULL);
	i = -1;
	while (dest[++i])
		ret[i] = dest[i];
	j = 0;
	while (n >= 1)
	{
		ret[i++] = src[j++];
		n--;
	}
	ret[i] = 0;
	return (ret);
}

char	*snjoin(char *dest, char *src, int n)
{
	int		i;
	int		j;
	char	*ret;

	ret = (char *)malloc
		((ft_strlen(dest) + n + 1) * sizeof(char));
	if (ret == 0)
		return (NULL);
	i = -1;
	while (dest[++i])
		ret[i] = dest[i];
	j = 0;
	while (n >= 1)
	{
		ret[i++] = src[j++];
		n--;
	}
	ret[i] = 0;
	return (ret);
}

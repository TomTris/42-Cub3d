/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:39:11 by qdo               #+#    #+#             */
/*   Updated: 2024/03/11 15:22:17 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		len;

	ret = ft_strdup(s);
	if ((ret) == 0)
		return (0);
	len = (int)ft_strlen(s);
	while (len > 0)
	{
		ret[len - 1] = (*f)(len - 1, ret[len - 1]);
		len--;
	}
	return (ret);
}

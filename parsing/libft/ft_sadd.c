/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:42:35 by qdo               #+#    #+#             */
/*   Updated: 2024/05/13 20:44:44 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sadd(char *str, char c)
{
	int		i;
	int		len;
	char	*ret;

	len = ft_strlen(str);
	ret = (char *)malloc(len + 2);
	if (str == 0)
		return (0);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = c;
	ret[i + 1] = 0;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:25:36 by qdo               #+#    #+#             */
/*   Updated: 2024/05/10 23:25:58 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//return value = :
//-1 -> it's empty till the end
//>= 0 -> str + i != empty, could be 0.
int	ft_empty_cnt(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isempty(str[i]) != 1)
			return (i);
	}
	return (i);
}

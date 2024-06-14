/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_valid_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:42:25 by qdo               #+#    #+#             */
/*   Updated: 2024/05/11 00:16:48 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//character is alpha / num or undercore.
//str[0] = digit still fine.
int	ft_cnt_valid_word(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum_(str[i]) == 1)
			i++;
		else
			return (i);
	}
	return (i);
}

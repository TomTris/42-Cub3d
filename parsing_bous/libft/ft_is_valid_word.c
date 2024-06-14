/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:07:25 by qdo               #+#    #+#             */
/*   Updated: 2024/05/11 00:07:40 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// i == -1 => check til the end.
int	ft_is_valid_word(char *str, int i)
{
	if (i <= 0)
		return (0);
	i--;
	if (ft_isdigit(str[0]) == 1)
		return (0);
	while (--i >= 0)
	{
		if (ft_isalnum_(str[i]) != 1)
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_white_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:03:10 by qdo               #+#    #+#             */
/*   Updated: 2024/05/12 04:11:02 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//this will trim whitespace before and after
//if no space at the beginning and the end -> = ft_strdup.
char	*ft_trim_whitespace(char *str)
{
	int		i;
	int		j;

	i = -1;
	while (str[++i])
		if (ft_isempty(str[i]) != 1)
			break ;
	if (str[i] == 0)
		return (ft_strdup(""));
	j = ft_strlen(str);
	while (str[--j])
		if (ft_isempty(str[j]) != 1)
			break ;
	return (sndup(str + i, j - i + 1));
}

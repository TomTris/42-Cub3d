/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_middle_del.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:53:36 by qdo               #+#    #+#             */
/*   Updated: 2024/05/12 00:37:38 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// a str: 0123456789
// delet 345 -> start_delete = 3, end_delete = 5
char	*ft_strdup_middle_del(char *str, int start_del, int end_del)
{
	int		i;
	int		j;
	char	*ret;

	ret = (char *)malloc((ft_strlen(str) + start_del - end_del - 1));
	if (ret == 0)
		return (0);
	i = -1;
	while (++i < start_del)
		ret[i] = str[i];
	j = end_del + 1;
	while (str[j])
		ret[i++] = str[j++];
	ret[i] = 0;
	return (ret);
}

char	*sdup_md_del(char *str, int start_del, int end_del)
{
	int		i;
	int		j;
	char	*ret;

	ret = (char *)malloc((ft_strlen(str) + start_del - end_del - 1));
	if (ret == 0)
		return (0);
	i = -1;
	while (++i < start_del)
		ret[i] = str[i];
	j = end_del + 1;
	while (str[j])
		ret[i++] = str[j++];
	ret[i] = 0;
	return (ret);
}

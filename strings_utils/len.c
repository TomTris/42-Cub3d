/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:55:08 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 20:23:13 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	len_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}

char	*to_string(int c)
{
	int		i;
	char	*s;
	int		cur;

	if (c > 9)
		i = 2;
	else
		i = 1;
	cur = 0;
	s = malloc(i * sizeof(char) + sizeof(char));
	if (!s)
		return (NULL);
	if (c > 9)
		s[cur++] = c / 10 + '0';
	s[cur] = c % 10 + '0';
	s[i] = 0;
	return (s);
}

char	*str_join(char *str1, char *str2)
{
	int		ptr1;
	int		ptr2;
	char	*out;

	out = malloc((ft_str_len(str1) + ft_str_len(str2) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ptr1 = 0;
	ptr2 = 0;
	while (str1[ptr1])
		out[ptr2++] = str1[ptr1++];
	ptr1 = 0;
	while (str2[ptr1])
		out[ptr2++] = str2[ptr1++];
	out[ptr2] = 0;
	return (out);
}

int	is_not_walkable(char c)
{
	if (c == '1' || c == 'd')
		return (1);
	return (0);
}

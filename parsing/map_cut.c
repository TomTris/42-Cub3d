/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:56:10 by qdo               #+#    #+#             */
/*   Updated: 2024/06/12 18:57:58 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_only_1(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == '1')
		i++;
	if (i != ft_strlen(str))
		return (0);
	return (1);
}

void	ft_map_cut_height(char **map, int height, int i, int check)
{
	while (map[height])
		height++;
	while (++i < height - 1)
	{
		if (ft_only_1(map[i]) && ft_only_1(map[i + 1]))
		{
			free(map[i]);
			map[i] = 0;
		}
	}
	while (check != 0)
	{
		check = 0;
		i = -1;
		while (++i < height - 1)
		{
			if (map[i] == 0 && map[i + 1] != 0)
			{
				check = 1;
				map[i] = map[i + 1];
				map[i + 1] = 0;
			}
		}
	}
}

int	ft_map_cut_width2(char **map, int height, int len, int i)
{
	char	*temp;

	len = ft_strlen(map[0]);
	height = -1;
	while (map[++height])
	{
		i = 0;
		while (map[height][i] == '1')
			i++;
		if (len > i)
			len = i;
	}
	len -= 1;
	while (len != 0 && --height >= 0)
	{
		temp = ft_strdup(map[height] + len);
		if (temp == 0)
			return (0);
		free(map[height]);
		map[height] = temp;
	}
	return (1);
}

void	ft_map_cut_width1(char **map)
{
	int	i;
	int	j;
	int	cut;
	int	tem;

	cut = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
	{
		j = 0;
		tem = 0;
		while (map[i][j])
			j++;
		while (map[i][--j] == '1')
			tem++;
		if (cut > tem)
			cut = tem;
	}
	cut -= 1;
	map[0][ft_strlen(map[0]) - cut] = 0;
	i = 0;
	while (map[++i])
		map[i][ft_strlen(map[0])] = 0;
}

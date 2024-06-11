/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:41:58 by qdo               #+#    #+#             */
/*   Updated: 2024/06/11 19:42:33 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

typedef struct s_po
{
	int	x;
	int	y;
}	t_po;

int	player_find(t_po *po, char **map)
{
	int		x;
	int		y;
	char	a;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			a = map[x][y];
			if (a != '1' && a != '2' && a != '0')
			{
				po->x = x;
				po->y = y;
				return (1);
			}
			y++;
		}
		x++;
	}
	print_fd(2, "Error\nCan't find player\n");
	return (0);
}

//1 -> 1
//0 or ' ' -> 0
// nichts -> 2.
// 2 - should not touched.
//P can go over -> change to 3 or maintance NSEW

int	check_n_change(char **map, int i, int j)
{
	char	a;
	char	b;
	char	c;
	char	d;
	int		ret;

	a = map[i][j + 1];
	b = map[i][j - 1];
	c = map[i + 1][j];
	d = map[i - 1][j];
	if (a == '2' || b == '2' || c == '2' || d == '2')
		return (print_fd(2, "Error\nInvalid map\n"), -1);
	if (a == '0' || b == '0' || c == '0' || d == '0')
		ret = 1;
	else
		ret = 0;
	if (map[i][j + 1] == '0')
		map[i][j + 1] = '3';
	if (map[i][j - 1] == '0')
		map[i][j - 1] = '3';
	if (map[i + 1][j] == '0')
		map[i + 1][j] = '3';
	if (map[i - 1][j] == '0')
		map[i - 1][j] = '3';
	return (ret);
}

int	loop(char **map, int i, int j)
{
	int	changed;
	int	changed2;

	changed = 0;
	changed2 = 0;
	while (i >= 0 && map[i + 1] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '3')
			{
				changed = check_n_change(map, i, j);
				if (changed == -1)
					return (-1);
				if (changed2 == 0 && changed == 1)
					changed2 = 1;
			}
			j++;
		}
		i++;
	}
	return (changed2);
}

int	is_surrounded(char **map, t_map *ret)
{
	t_po	po;
	int		check;

	if (player_find(&po, map) == 0)
		return (0);
	ret->x = ((double) po.x) + 0.5;
	ret->y = ((double) po.y) + 0.5;
	ret->dire = 3;
	if (map[po.x][po.y] == 'E')
		ret->dire = 0;
	if (map[po.x][po.y] == 'N')
		ret->dire = 1;
	if (map[po.x][po.y] == 'W')
		ret->dire = 2;
	map[po.x][po.y] = '3';
	while (1)
	{
		check = loop(map, 0, 0);
		if (check == -1)
			return (0);
		if (check == 0)
			return (1);
	}
}

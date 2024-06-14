/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:03:47 by qdo               #+#    #+#             */
/*   Updated: 2024/06/14 17:09:44 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_t_map_0_map(t_map *a)
{
	if (a)
	{
		free(a->no);
		free(a->so);
		free(a->ea);
		free(a->we);
	}
	free(a);
}

void	recover_d(t_po **d, char **map)
{
	t_po	*temp;

	if (d != 0)
	{
		while (d[0] != 0)
		{
			printf("recoverd: x = %d, y= %d\n", d[0]->x, d[0]->y);
			if (map[d[0]->x][d[0]->y + 1] != '1'
				|| map[d[0]->x][d[0]->y -1] != '1'
				|| map[d[0]->x + 1][d[0]->y] != '1'
				|| map[d[0]->x - 1][d[0]->y] != '1')
			{
				map[d[0]->x][d[0]->y] = 'd';
				printf("recover d\n");
			}
			temp = d[0];
			d[0] = d[0]->next;
			free(temp);
		}
	}
}

void	ft_1_0_map(t_po *d, char **map, t_map *ret)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == '0' || map[i][j] == '2')
				map[i][j] = '1';
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == '3')
				map[i][j] = '0';
	}
	recover_d(&d, map);
	ret->map[(int)ret->x][(int)ret->y] = 'N';
}

void	ft_n(char **map, t_map *ret)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'N')
			{
				ret->x = ((double) x) + 0.5;
				ret->y = ((double) y) + 0.5;
				map[x][y] = '0';
				return ;
			}
		}
	}
	print_fd(2, "Error\nSth wrong\n");
}

//non_map contains 8 meaningfull lines with meaning full value, check only
//before line ft_is_part_of_map
//un_non_map - else
t_map	*ft_map(int ac, char **av)
{
	char		**file_content;
	t_map		*ret;
	int			i;
	t_po		*d;
	int			check;

	file_content = ft_file_create(ac, av);
	if (file_content == 0)
		return (NULL);
	i = 0;
	ret = break_non_map(file_content, &i);
	if (ret == 0)
		return (NULL);
	d = map_gen(file_content, i, ret, &check);
	free_split(file_content);
	if (check == 0)
		return (recover_d(&d, ret->map), free_t_map(ret), NULL);
	ft_1_0_map(d, ret->map, ret);
	ft_map_cut_height(ret->map, 0, -1, 1);
	ft_map_cut_width1(ret->map);
	if (ft_map_cut_width2(ret->map, 0, 0, 0) == 0)
		return (free_t_map(ret), NULL);
	ft_n(ret->map, ret);
	return (ret);
}

// int	main2(int ac, char **av)
// {
// 	t_map	*map;

// 	map = ft_map(ac, av);
// 	if (map == 0)
// 		return (printf("somewher wrong\n"), 1);
// 	printf("%d\n", map->dire);
// 	printf("%f\n", map->x);
// 	printf("%f\n", map->y);
// 	printf("%s\n", map->no);
// 	printf("%s\n", map->so);
// 	printf("%s\n", map->we);
// 	printf("%s\n", map->ea);
// 	printf("%u\n", map->floor);
// 	printf("%u\n", map->ceiling);

// 	int	i =0;
// 	while (map->map[i])
// 	{
// 		printf("%s\n", map->map[i++]);
// 	}
// 		free_t_map(map);
// 	return (0);
// }

// int	main(int ac, char **av)
// {
// 	main2(ac, av);
// 	// system("leaks parsing.a");
// }

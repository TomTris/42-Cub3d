/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:03:47 by qdo               #+#    #+#             */
/*   Updated: 2024/06/12 18:58:57 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_1_0_map(char **map)
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
}

//non_map contains 8 meaningfull lines with meaning full value, check only
//before line ft_is_part_of_map
//un_non_map - else
t_map	*ft_map(int ac, char **av)
{
	char		**file_content;
	t_map		*ret;
	int			i;

	file_content = ft_file_create(ac, av);
	if (file_content == 0)
		return (NULL);
	i = 0;
	ret = break_non_map(file_content, &i);
	if (ret == 0)
		return (NULL);
	ret->map = map_gen(file_content, i, ret);
	free_split(file_content);
	if (ret->map == 0)
		return (free_t_map(ret), NULL);
	ft_1_0_map(ret->map);
	ft_map_cut_height(ret->map, 0, -1, 1);
	ft_map_cut_width1(ret->map);
	if (ft_map_cut_width2(ret->map, 0, 0, 0) == 0)
		return (free_t_map(ret), NULL);
	return (ret);
}

// int	main(int ac, char **av)
// {
// 	t_map	*map;

// 	map = ft_map(ac, av);
// 	if (map == 0)
// 		return (1);
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
// 	return (0);
// }

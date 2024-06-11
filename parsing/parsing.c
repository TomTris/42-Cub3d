/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:03:47 by qdo               #+#    #+#             */
/*   Updated: 2024/06/11 18:22:03 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_1_0_map(char **map)
{
	int		i;
	int		j;
	char	a;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			a = map[i][j];
			if (a != '1')
				map[i][j] = '0';
		}
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
	return (ret);
}

// int	main(int ac, char **av)
// {
// 	t_map	*map;

// 	map = ft_map(ac, av);
// 	if (map == 0)
// 		return (1);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:03:47 by qdo               #+#    #+#             */
/*   Updated: 2024/06/11 13:31:09 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	return (ret);
}

int	main2(int ac, char **av)
{
	t_map	*map;

	map = ft_map(ac, av);
	if (map == 0)
		print_fd(1, "Somewhere wrong\n");
	else
		print_fd(2, "Code for this case good!\n");
	free_t_map(map);
	return (0);
}

int	main(int ac, char **av)
{
	main2(ac, av);
	// system("leaks parsing");
}
// printf("%s\n", (map->no));
			// printf("%s\n", (map->so));
			// printf("%s\n", (map->ea));
			// printf("%s\n", (map->we));
			// printf("%u\n", map->floor);
			// printf("%u\n", map->ceiling);
			// printf("-------------------------\n");
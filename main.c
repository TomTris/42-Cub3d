/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:58:53 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/11 20:05:12 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_cpy_map_to_data(t_data *data, t_player *player, t_map *parsing)
{
	data->map = parsing->map;
	data->player = player;
	player->x = parsing->y;
	player->y = parsing->x;
	data->so = parsing->so;
	data->no = parsing->no;
	data->we = parsing->we;
	data->ea = parsing->ea;
	data->floor = parsing->floor;
	data->map_height = ft_str_len(data->map[0]);
	data->map_width = len_2d_array(data->map);
	// change_one_to_zero(data, data->map);
	for	(int i = 0; data->map[i]; i++)
	{
		printf("%s\n", data->map[i]);
	}
	printf("%d\n", parsing->dire);
	printf("%f\n", parsing->x);
	printf("%f\n", parsing->y);
	printf("%s\n", parsing->no);
	printf("%s\n", parsing->so);
	printf("%s\n", parsing->we);
	printf("%s\n", parsing->ea);
	printf("%u\n", parsing->floor);
	printf("%u\n", parsing->ceiling);
	data->player->angle_turn_horizontal = 3 * M_PI / 2;
	if (parsing->dire == 0)
		data->player->angle_turn_horizontal = 0.0;
	else if (parsing->dire == 1)
		data->player->angle_turn_horizontal = M_PI / 2;
	else if (parsing->dire == 2)
		data->player->angle_turn_horizontal = M_PI;
	data->ceiling = parsing->ceiling;
	free(parsing);
}


int	main(int ac, char **av)
{
	t_data		data;
	t_map		*parsing;
	t_player	player;

	parsing = ft_map(ac, av);
	if (parsing == 0)
		return (1);
	ft_cpy_map_to_data(&data, &player, parsing);
	display(&data);
	return (EXIT_SUCCESS);
}

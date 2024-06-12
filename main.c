/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:58:53 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/12 14:29:11 by obrittne         ###   ########.fr       */
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
	data->player->angle_turn_horizontal = 3.0 * M_PI / 2.0;
	if (parsing->dire == 0)
		data->player->angle_turn_horizontal = 0.0;
	else if (parsing->dire == 1)
		data->player->angle_turn_horizontal = M_PI / 2.0;
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

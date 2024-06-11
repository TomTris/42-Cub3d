/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:58:53 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/11 18:34:17 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_cpy_map_to_data(t_data *data, t_player *player,  t_map *parsing)
{
	data->map = parsing->map;
	data->player = player;
	player->x = parsing->x;
	player->y = parsing->y;
	data->so = parsing->so;
	data->no = parsing->no;
	data->we = parsing->we;
	data->ea = parsing->ea;
	data->floor = parsing->floor;
	player->angle_turn_horizontal = (double)parsing->dire * M_PI / 2;
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

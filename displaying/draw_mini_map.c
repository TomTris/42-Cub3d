/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:28:20 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/11 14:17:07 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	draw_space(t_data *data, int x, int y, int color)
{
	int	i;
	int	e;

	i = 0;
	while (i < 32)
	{
		e = 0;
		while (e < 32)
		{
			mlx_put_pixel(data->minimap, 32 * x + e, 32 * y + i, color);
			e++;
		}
		i++;
	}
}

void	get_players_x_y(t_data *data, int *x, int *y)
{
	*x = (int)data->player->x;
	*y = (int)data->player->y;
}

void	draw_stuff(t_data *data, t_mini	*minimap)
{
	if (minimap->y_player < 0 || minimap->x_player < 0 || !minimap->can_access)
		draw_space(data, minimap->x, minimap->y, 255);
	else
	{
		if (!minimap->end)
		{
			if (!(data->map[minimap->y_player]))
				minimap->end = 1;
		}
		if (minimap->can_access && !minimap->end)
		{
			if (data->map[minimap->y_player][minimap->x_player] == 0)
			{
				minimap->can_access = 0;
				return ;
			}
		}
		if (minimap->end || data->map[minimap->y_player][minimap->x_player] == '1')
			draw_space(data, minimap->x, minimap->y, 255);
		else
			draw_space(data, minimap->x, minimap->y, 255 << 24 | 255);
	}
}

void	draw_mini_map(t_data *data)
{
	t_mini	minimap;

	get_players_x_y(data, &minimap.x_player, &minimap.y_player);
	minimap.x_player -= 4;
	minimap.y_player -= 4;
	minimap.y = 0;
	minimap.end = 0;
	while (minimap.y < 9)
	{
		minimap.can_access = 1;
		minimap.x = 0;
		while (minimap.x < 9)
		{
			draw_stuff(data, &minimap);
			minimap.x++;
			minimap.x_player++;
		}
		minimap.y++;
		minimap.y_player++;
		minimap.x_player -= 9;
	}
	draw_player(data);
	draw_rays(data);
}

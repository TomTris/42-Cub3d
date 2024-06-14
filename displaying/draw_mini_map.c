/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:28:20 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 19:02:04 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	draw_space(t_data *data, int x, int y, int color)
{
	int	i;
	int	e;

	i = 0;
	while (i < MINIMAP_SQUARE)
	{
		e = 0;
		while (e < MINIMAP_SQUARE)
		{
			mlx_put_pixel(data->minimap, MINIMAP_SQUARE * x + e, \
			MINIMAP_SQUARE * y + i, color);
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
		draw_space(data, minimap->x, minimap->y, MAP_WALL << 8 | 255);
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
		if (minimap->end || \
		data->map[minimap->y_player][minimap->x_player] == '1')
			draw_space(data, minimap->x, minimap->y, MAP_WALL << 8 | 255);
		else if (data->map[minimap->y_player][minimap->x_player] == '0')
			draw_space(data, minimap->x, minimap->y, MAP_EMPTY << 8 | 255);
		else
			draw_space(data, minimap->x, minimap->y, MAP_DOOR << 8 | 255);
	}
}

void	fill_first_time(t_data *data)
{
	static int	first = 1;
	int			y;
	int			x;

	if (first)
	{
		y = 0;
		while (y < (int)data->minimap->height)
		{
			x = 0;
			while (x < (int)data->minimap->width)
			{
				mlx_put_pixel(data->minimap, x, y, MAP_WALL << 8 | 255);
				x++;
			}
			y++;
		}
		first = 0;
	}
}

void	draw_mini_map(t_data *data, t_ray *ray)
{
	t_mini	minimap;

	fill_first_time(data);
	get_players_x_y(data, &minimap.x_player, &minimap.y_player);
	minimap.x_player -= (int)(AMOUNT_SQUARES / 2);
	minimap.y_player -= (int)(AMOUNT_SQUARES / 2);
	minimap.y = 0;
	minimap.end = 0;
	while (minimap.y < AMOUNT_SQUARES)
	{
		minimap.can_access = 1;
		minimap.x = 0;
		while (minimap.x < AMOUNT_SQUARES)
		{
			draw_stuff(data, &minimap);
			minimap.x++;
			minimap.x_player++;
		}
		minimap.y++;
		minimap.y_player++;
		minimap.x_player -= AMOUNT_SQUARES;
	}
	draw_player(data);
	draw_rays(data, ray);
	display_wapon(data);
}

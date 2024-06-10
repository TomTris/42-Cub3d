/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actual_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:49:55 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/10 21:19:09 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	draw_player(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int	addy;
	int	addx;


	x = 32 * 4 + (int)(32.0 * (data->player->x - \
	(double)((int)data->player->x)));
	y = 32 * 4 + (int)(32.0 * (data->player->y - \
	(double)((int)data->player->y)));
	color = 255 << 16 | 255;
	addy = -2;
	while (addy < 2)
	{
		addx = -2;
		while (addx < 2)
		{
			mlx_put_pixel(data->minimap, x + addx, y + addy, color);
			addx++;
		}
		addy++;
	}
}

void	move_right(t_data *data)
{
	int		t;
	double	min_move;
	double	min_distance;

	min_move = MINMOVE;
	min_distance = MINDISTANCE;
	dprintf(1, "%f\n", data->player->x);
	data->player->x += min_move + min_distance;
	t = (int)data->player->x;
	if (data->map[(int)data->player->y][t] == '1' || \
	data->map[(int)data->player->y][t] == 0)
	{
		data->player->x -= min_move;
	}
	data->player->x -= min_distance;
}

void	move_down(t_data *data)
{
	int		t;
	double	min_move;
	double	min_distance;

	min_move = MINMOVE;
	min_distance = MINDISTANCE;
	dprintf(1, "%f\n", data->player->y);
	data->player->y += min_move + min_distance;
	t = (int)data->player->y;
	if (!data->map[t] || data->map[t][(int)data->player->x] == '1')
	{
		data->player->y -= min_move;
	}
	data->player->y -= min_distance;
}

void	move_up(t_data *data)
{
	int		t;
	double	min_move;
	double	min_distance;

	min_move = MINMOVE;
	min_distance = MINDISTANCE;
	dprintf(1, "%f\n", data->player->y);
	data->player->y -= min_move + min_distance;
	t = (int)data->player->y;
	if (data->map[t][(int)data->player->x] == '1')
	{
		data->player->y += min_move;
	}
	data->player->y += min_distance;
}

void	move_left(t_data *data)
{
	int		t;
	double	min_move;
	double	min_distance;

	dprintf(1, "%f\n", data->player->x);
	min_move = MINMOVE;
	min_distance = MINDISTANCE;
	data->player->x -= (min_move + min_distance);
	if (data->player->x < 0.0)
	{
		data->player->x += min_move + min_distance;
		return ;
	}
	t = (int)data->player->x;
	if (data->map[(int)data->player->y][t] == '1')
	{
		data->player->x += min_move;
	}
	data->player->x += min_distance;
}

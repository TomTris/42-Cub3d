/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actual_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:49:55 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 18:55:04 by obrittne         ###   ########.fr       */
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

	x = MINIMAP_SQUARE * ((int)AMOUNT_SQUARES / 2) + \
	(int)((double)MINIMAP_SQUARE * (data->player->x - \
	(double)((int)data->player->x)));
	y = MINIMAP_SQUARE * ((int)AMOUNT_SQUARES / 2) + \
	(int)((double)MINIMAP_SQUARE * (data->player->y - \
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

double	get_factor(double angle)
{
	if (angle > 0.0)
		return (1.0);
	else if (angle < 0.0)
		return (-1.0);
	else
		return (0.0);
}

double	get_distance(int boost)
{
	if (boost == 1)
		return (MINMOVE * 2.0);
	return (MINMOVE);
}

void	move_in_line(t_data *data, double angle, int boost)
{
	double	new_x;
	double	new_y;
	double	sinus;
	double	cosinus;

	sinus = -sin(angle) * get_distance(boost);
	cosinus = cos(angle) * get_distance(boost);
	new_x = data->player->x + cosinus;
	new_y = data->player->y + sinus;
	if (!is_not_walkable(data->map[(int)data->player->y] \
	[(int)(new_x + MINDISTANCE * get_factor(cosinus))]) && \
	!is_not_walkable(data->map[(int)(data->player->y + MINDISTANCE)] \
	[(int)(new_x + MINDISTANCE * get_factor(cosinus))]) && \
	!is_not_walkable(data->map[(int)(data->player->y - MINDISTANCE)] \
	[(int)(new_x + MINDISTANCE * get_factor(cosinus))]))
		data->player->x = new_x;
	if (!is_not_walkable(data->map[(int)(new_y + MINDISTANCE * \
	get_factor(sinus))][(int)data->player->x]) &&
	!is_not_walkable(data->map[(int)(new_y + MINDISTANCE * \
	get_factor(sinus))][(int)(data->player->x + MINDISTANCE)]) && \
	!is_not_walkable(data->map[(int)(new_y + MINDISTANCE * \
	get_factor(sinus))][(int)(data->player->x - MINDISTANCE)]))
		data->player->y = new_y;
}

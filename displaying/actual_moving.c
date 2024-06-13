/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actual_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:49:55 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/13 18:40:44 by obrittne         ###   ########.fr       */
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

double	get_factor(double angle)
{
	if (angle > 0.0)
		return (1.0);
	else if (angle < 0.0)
		return (-1.0);
	else
		return (0.0);
}

void	move_in_line(t_data *data, double angle)
{
	double	new_x;
	double	new_y;
	double	sinus;
	double	cosinus;

	sinus = -sin(angle) * MINMOVE;
	cosinus = cos(angle) * MINMOVE;
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

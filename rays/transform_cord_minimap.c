/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_cord_minimap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:02:33 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 20:23:13 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_start_pos(t_data *data, t_ray *ray)
{
	int		player_x;
	int		player_y;

	player_x = MINIMAP_SQUARE * ((int)AMOUNT_SQUARES / 2) + \
	(int)((double)MINIMAP_SQUARE * (data->player->x - \
	(double)((int)data->player->x)));
	player_y = MINIMAP_SQUARE * ((int)AMOUNT_SQUARES / 2) + \
	(int)((double)MINIMAP_SQUARE * (data->player->y - \
	(double)((int)data->player->y)));
	ray->start_pos_x = player_x;
	ray->start_pos_y = player_y;
	ray->map_cord_x = MINIMAP_SQUARE * ((int)AMOUNT_SQUARES / 2) + \
	lround((ray->x - (double)((int)data->player->x)) * (double)MINIMAP_SQUARE);
	ray->map_cord_y = MINIMAP_SQUARE * ((int)AMOUNT_SQUARES / 2) + \
	lround((ray->y - (double)((int)data->player->y)) * (double)MINIMAP_SQUARE);
}

void	get_inter_1(t_ray *ray, int dx2, int dy2, double *t)
{
	double	s;

	s = -(double)ray->start_pos_x / (double)dx2;
	if (s < *t && s >= 0)
	{
		*t = s;
		ray->pos_x = lround((double)ray->start_pos_x + s * (double)dx2);
		ray->pos_y = lround((double)ray->start_pos_y + s * (double)dy2);
	}
	s = -(double)ray->start_pos_y / (double)dy2;
	if (s < *t && s >= 0)
	{
		*t = s;
		ray->pos_x = lround((double)ray->start_pos_x + s * (double)dx2);
		ray->pos_y = lround((double)ray->start_pos_y + s * (double)dy2);
	}
}

void	move_to_box(t_data *data, t_ray *ray, int dx, int dy)
{
	double	t;
	double	s;
	double	maxi;

	t = 1e9;
	get_inter_1(ray, dx, dy, &t);
	maxi = (double)data->minimap->width;
	s = (maxi - (double)ray->start_pos_x) / dx;
	if (s < t && s >= 0)
	{
		t = s;
		ray->pos_x = lround((double)ray->start_pos_x + s * (double)dx);
		ray->pos_y = lround((double)ray->start_pos_y + s * (double)dy);
	}
	s = (maxi - (double)ray->start_pos_y) / dy;
	if (s < t && s >= 0)
	{
		t = s;
		ray->pos_x = lround((double)ray->start_pos_x + s * (double)dx);
		ray->pos_y = lround((double)ray->start_pos_y + s * (double)dy);
	}
	ray->map_cord_x = ray->pos_x;
	ray->map_cord_y = ray->pos_y;
}

void	move_inside(t_data *data, t_ray *ray)
{
	int		dx;
	int		dy;

	if (ray->map_cord_x >= 0 && ray->map_cord_x < (int)data->minimap->width \
	&& ray->map_cord_y >= 0 && ray->map_cord_y < (int)data->minimap->height)
		return ;
	dx = (ray->map_cord_x - ray->start_pos_x);
	dy = (ray->map_cord_y - ray->start_pos_y);
	if (dx == 0 && ray->map_cord_y >= (int)data->minimap->width)
		ray->map_cord_y = (int)data->minimap->width - 1;
	else if (dx == 0 && ray->map_cord_y < 0)
		ray->map_cord_y = 0;
	else if (dy == 0 && ray->map_cord_x >= (int)data->minimap->width)
		ray->map_cord_x = (int)data->minimap->width - 1;
	else if (dy == 0 && ray->map_cord_x < 0)
		ray->map_cord_x = 0;
	else
		move_to_box(data, ray, dx, dy);
}

void	transform_cordinates(t_data *data, t_ray *ray)
{
	get_start_pos(data, ray);
	move_inside(data, ray);
}

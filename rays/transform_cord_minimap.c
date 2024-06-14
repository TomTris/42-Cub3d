/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_cord_minimap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:02:33 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 12:25:44 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	get_start_pos(t_data *data, t_ray *ray)
{
	int		player_x;
	int		player_y;

	player_x = 32 * 4 + (int)(32.0 * (data->player->x - \
	(double)((int)data->player->x)));
	player_y = 32 * 4 + (int)(32.0 * (data->player->y - \
	(double)((int)data->player->y)));
	ray->start_pos_x = player_x;
	ray->start_pos_y = player_y;
	ray->map_cord_x = 128 + \
	lround((ray->x - (double)((int)data->player->x)) * 32.0);
	ray->map_cord_y = 128 + \
	lround((ray->y - (double)((int)data->player->y)) * 32.0);
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

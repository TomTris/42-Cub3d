/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:36:45 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/13 15:56:25 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	get_angle_0_180(t_data *data, t_ray *ray, int i)
{
	int	addition;
	int	player_x;

	player_x = (int)data->player->x;
	if (i == 0)
		addition = 1;
	else
		addition = -1;
	while (!is_not_walkable(data->map[(int)data->player->y][player_x]))
		player_x = player_x + addition;
	if (addition == -1)
		player_x += 1;
	ray->x = (double)player_x;
	ray->y = data->player->y;
}

void	get_angle_90_270(t_data *data, t_ray *ray, int i)
{
	int	addition;
	int	player_y;

	player_y = (int)data->player->y;
	if (i == 0)
		addition = -1;
	else
		addition = 1;
	while (!is_not_walkable(data->map[player_y][(int)data->player->x]))
		player_y = player_y + addition;
	if (addition == -1)
		player_y += 1;
	ray->x = data->player->x;
	ray->y = (double)player_y;
}

void	get_horizontal(t_data *data, double angle, t_ray *ray)
{
	double	ta;
	double	x_factor;
	double	y_factor;

	ta = fabs(tan(angle)); 
	ta = 1.0 / ta;
	x_factor = 1.0;
	y_factor = 1.0;
	if (angle > M_PI / 2.0 && angle < 3.0 * M_PI / 2.0)
		x_factor = -1.0;
	if (angle > M_PI)
	{
		y_factor = 1.0;
		ray->t_y = (double)((int)data->player->y + 1);
		ray->t_x = data->player->x + fabs(((double)(ray->t_y - data->player->y))) * ta * x_factor;
	}
	else
	{
		y_factor = -1.0;
		ray->t_y = (double)((int)data->player->y) - 0.000001;
		ray->t_x = data->player->x + fabs(((double)(ray->t_y - data->player->y))) * ta * x_factor;
	}
	if ((int)ray->t_x < 0 || (int)ray->t_x >= data->map_width || data->map[(int)ray->t_y][(int)ray->t_x] == '1')
	{
		return ;
	}
	while (data->map[(int)ray->t_y][(int)ray->t_x] != '1')
	{
		ray->t_y = ray->t_y + y_factor;
		ray->t_x += ta * x_factor ;
		if ((int)ray->t_x < 0 || (int)ray->t_x >= data->map_width)
		{
			return ;
		}
	}
	if (y_factor == -1.0)
	{
		ray->should = 1;
		ray->update_y = 1.0;
		ray->update_x = -ta * x_factor;
	}
}

void	get_vertical(t_data *data, double angle, t_ray *ray)
{
	double	ta;
	double	x_factor;
	double	y_factor;

	ta = fabs(tan(angle)); 
	x_factor = 1.0;
	y_factor = 1.0;
	if (angle < M_PI)
		y_factor = -1.0;
	if (angle > M_PI / 2.0 && angle < 3.0 * M_PI / 2.0)
	{
		x_factor = -1.0;
		ray->t_xv = (double)((int)data->player->x) - 0.0000001;
		ray->t_yv = data->player->y + fabs(((double)(ray->t_xv - data->player->x))) * ta * y_factor;
	}
	else
	{
		x_factor = 1.0;
		ray->t_xv = (double)((int)data->player->x + 1);
		ray->t_yv = data->player->y + fabs(((double)(ray->t_xv - data->player->x))) * ta * y_factor;
	}
	if ((int)ray->t_yv < 0 || (int)ray->t_yv >= data->map_height || (int)ray->t_xv < 0 || (int)ray->t_xv >= data->map_width || data->map[(int)ray->t_yv][(int)ray->t_xv] == '1')
	{
		return ;
	}
	while (data->map[(int)ray->t_yv][(int)ray->t_xv] != '1')
	{
		ray->t_yv += ta * y_factor;
		ray->t_xv = ray->t_xv + x_factor;
		if ((int)ray->t_yv < 0 || (int)ray->t_yv >= data->map_height || (int)ray->t_xv < 0 || (int)ray->t_xv >= data->map_width)
		{
			return ;
		}
	}
	if (y_factor == -1.0)
	{
		ray->shouldv = 1;
		ray->update_xv = 1.0;
		ray->update_yv = -ta * y_factor;
	}
	ray->x = ray->t_xv;
	ray->y = ray->t_yv;
}

void	get_best(t_data *data, t_ray *ray)
{
	if (pow(ray->t_xv - data->player->x, 2.0) + pow(ray->t_yv - data->player->y, 2.0) > \
	pow(ray->t_x - data->player->x, 2.0) + pow(ray->t_y - data->player->y, 2.0))
	{
		ray->x = ray->t_x;
		ray->y = ray->t_y;
	}
	else
	{
		ray->x = ray->t_xv;
		ray->y = ray->t_yv;
	}
}

void	get_normal(t_data *data, double angle, t_ray *ray)
{
	get_horizontal(data, angle, ray);
	get_vertical(data, angle, ray);
	get_best(data, ray);
}

void	get_cords(t_data *data, double angle, t_ray *ray)
{

	if (angle == 0.0)
		get_angle_0_180(data, ray, 0);
	else if (angle == M_PI)
		get_angle_0_180(data, ray, 1);
	else if (angle == M_PI / 2.0)
		get_angle_90_270(data, ray, 0);
	else if (angle == 3.0 * M_PI / 2.0)
		get_angle_90_270(data, ray, 1);
	else
		get_normal(data, angle, ray);
}

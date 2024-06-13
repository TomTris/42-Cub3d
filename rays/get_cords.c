/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:36:45 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/13 19:54:57 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	get_angle_0_180(t_data *data, t_ray *ray, int i)
{
	int	addition;

	if (i == 0)
	{
		ray->x = (double)((int)data->player->x);
		ray->texture = 0;
		addition = 1;
	}
	else
	{
		ray->x = (double)((int)data->player->x) - 0.000001;
		ray->texture = 2;
		addition = -1;
	}
	while (!is_not_walkable(data->map[(int)data->player->y][(int)ray->x]))
		ray->x = ray->x + addition;
	ray->y = data->player->y;
	ray->distance = fabs(ray->x - data->player->x);
}

void	get_angle_90_270(t_data *data, t_ray *ray, int i)
{
	int	addition;

	if (i == 0)
	{
		ray->y = (double)((int)data->player->y) - 0.000001;
		ray->texture = 1;
		addition = -1;
	}
	else
	{
		ray->y = (double)((int)data->player->y);
		ray->texture = 3;
		addition = 1;
	}
	while (!is_not_walkable(data->map[(int)ray->y][(int)data->player->x]))
		ray->y = ray->y + addition;
	ray->x = data->player->x;
	ray->distance = fabs(ray->y - data->player->y);
}

void	get_best(t_data *data, t_ray *ray)
{
	double	distance1;
	double	distance2;

	calculate_distance(data, ray, &distance1, &distance2);
	if (distance1 > distance2)
	{
		ray->x = ray->t_x;
		ray->y = ray->t_y;
		if (ray->y_factor_f == 1.0)
			ray->texture = 3;
		else
			ray->texture = 1;
		ray->distance = distance2;
	}
	else
	{
		ray->x = ray->t_xv;
		ray->y = ray->t_yv;
		if (ray->x_factor_f == 1.0)
			ray->texture = 0;
		else
			ray->texture = 2;
		ray->distance = distance1;
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

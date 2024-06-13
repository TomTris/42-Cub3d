/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:36:45 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/13 19:24:48 by obrittne         ###   ########.fr       */
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

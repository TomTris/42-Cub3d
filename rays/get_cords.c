/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:36:45 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/12 17:05:02 by obrittne         ###   ########.fr       */
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
	while (data->map[(int)data->player->y][player_x] != '1')
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
	while (data->map[player_y][(int)data->player->x] != '1')
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
	double	t_x;
	double	t_y;

	ta = fabs(tan(data->player->angle_turn_horizontal)); 
	ta = 1.0 / ta;
	x_factor = 1.0;
	y_factor = 1.0;
	if (angle > M_PI / 2.0 && angle < 3.0 * M_PI / 2.0)
		x_factor = -1.0;
	if (angle > M_PI)
	{
		y_factor = 1.0;
		t_y = (double)((int)data->player->y + 1);
		t_x = data->player->x + fabs(((double)(t_y - data->player->y))) * ta * x_factor;
	}
	else
	{
		y_factor = -1.0;
		t_y = (double)((int)data->player->y);
		t_x = data->player->x + fabs(((double)(t_y - data->player->y))) * ta * x_factor;
	}
	dprintf(1, "angle {%f}  stept_Y {%f}  step_x{%f} \n\n\n", angle * 180.0 / M_PI, y_factor, ta * x_factor);
	if ((int)t_x < 0 || (int)t_x >= data->map_width || data->map[(int)t_y][(int)t_x] == '1')
	{
		ray->x = t_x;
		ray->y = t_y;
		return ;
	}
	while (data->map[(int)t_y][(int)t_x] != '1')
	{
		t_y = t_y + y_factor;
		t_x += ta * x_factor ;
		if ((int)t_x < 0 || (int)t_x >= data->map_width)
		{
			ray->x = t_x;
			ray->y = t_y;
			return ;
		}
	}
	if (y_factor == -1.0)
	{
		t_y += 1.0;
		t_x -= ta * x_factor;
	}
	ray->y = t_y;
	ray->x = t_x;
}

// void	get_vertical(t_data *data, double angle, double *x, double *y)
// {
// }

void	get_normal(t_data *data, double angle, t_ray *ray)
{
	get_horizontal(data, angle, ray);
	// get_vertical(data, angle, x, y);

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

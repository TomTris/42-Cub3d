/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:17:27 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/13 19:29:47 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	get_factor(t_data *data, t_ray *ray, double angle)
{
	ray->ta = fabs(tan(angle));
	ray->x_factor = 1.0;
	ray->y_factor = 1.0;
	if (angle < M_PI)
		ray->y_factor = -1.0;
	if (angle > M_PI / 2.0 && angle < 3.0 * M_PI / 2.0)
	{
		ray->x_factor = -1.0;
		ray->t_xv = (double)((int)data->player->x) - 0.0000001;
		ray->t_yv = data->player->y + fabs(((double)(ray->t_xv - \
		data->player->x))) * ray->ta * ray->y_factor;
	}
	else
	{
		ray->x_factor = 1.0;
		ray->t_xv = (double)((int)data->player->x + 1);
		ray->t_yv = data->player->y + fabs(((double)(ray->t_xv - \
		data->player->x))) * ray->ta * ray->y_factor;
	}
	ray->x_factor_f = ray->x_factor;
}

void	get_vertical(t_data *data, double angle, t_ray *ray)
{
	get_factor(data, ray, angle);
	if ((int)ray->t_yv < 0 || (int)ray->t_yv >= data->map_height || \
	(int)ray->t_xv < 0 || (int)ray->t_xv >= data->map_width || \
	is_not_walkable(data->map[(int)ray->t_yv][(int)ray->t_xv]))
		return ;
	while (!is_not_walkable(data->map[(int)ray->t_yv][(int)ray->t_xv]))
	{
		ray->t_yv += ray->ta * ray->y_factor;
		ray->t_xv = ray->t_xv + ray->x_factor;
		if ((int)ray->t_yv < 0 || (int)ray->t_yv >= data->map_height \
		|| (int)ray->t_xv < 0 || (int)ray->t_xv >= data->map_width)
			return ;
	}
	ray->x = ray->t_xv;
	ray->y = ray->t_yv;
}

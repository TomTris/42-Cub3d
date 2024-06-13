/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizonatal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:25:07 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/13 19:56:04 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	get_factor(t_data *data, t_ray *ray, double angle)
{
	ray->ta = 1.0 / fabs(tan(angle));
	ray->x_factor = 1.0;
	ray->y_factor = 1.0;
	if (angle > M_PI / 2.0 && angle < 3.0 * M_PI / 2.0)
		ray->x_factor = -1.0;
	if (angle > M_PI)
	{
		ray->y_factor = 1.0;
		ray->t_y = (double)((int)data->player->y + 1);
		ray->t_x = data->player->x + fabs(((double)(ray->t_y - \
		data->player->y))) * ray->ta * ray->x_factor;
	}
	else
	{
		ray->y_factor = -1.0;
		ray->t_y = (double)((int)data->player->y) - 0.000001;
		ray->t_x = data->player->x + fabs(((double)(ray->t_y - \
		data->player->y))) * ray->ta * ray->x_factor;
	}
	ray->y_factor_f = ray->y_factor;
}

void	get_horizontal(t_data *data, double angle, t_ray *ray)
{
	get_factor(data, ray, angle);
	if ((int)ray->t_x < 0 || (int)ray->t_x >= data->map_width \
	|| is_not_walkable(data->map[(int)ray->t_y][(int)ray->t_x]))
	{
		return ;
	}
	while (!is_not_walkable(data->map[(int)ray->t_y][(int)ray->t_x]))
	{
		ray->t_y = ray->t_y + ray->y_factor;
		ray->t_x += ray->ta * ray->x_factor ;
		if ((int)ray->t_x < 0 || (int)ray->t_x >= data->map_width)
			return ;
	}
}

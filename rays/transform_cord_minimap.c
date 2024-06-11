/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_cord_minimap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:02:33 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/11 13:44:31 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	get_start_pos(t_data *data, t_ray *ray)
{
	int		player_x;
	int		player_y;
	double	temp_x;
	double	temp_y;

	player_x = 32 * 4 + (int)(32.0 * (data->player->x - \
	(double)((int)data->player->x)));
	player_y = 32 * 4 + (int)(32.0 * (data->player->y - \
	(double)((int)data->player->y)));
	ray->start_pos_x = player_x;
	ray->start_pos_y = player_y;
	ray->map_cord_x = player_x - roundl((ray->x - data->player->x) * 32.0);
	ray->map_cord_y = player_y - roundl((ray->y - data->player->y) * 32.0);
}

void	move_inside(t_data *data, t_ray *ray)
{
	int	dx;
	int	dy;

	dx = (ray->map_cord_x - ray->start_pos_x);
	dy = (ray->map_cord_y - ray->start_pos_y);
	
}

void	transform_cordinates(t_data *data, t_ray *ray)
{
	get_start_pos(data, ray);
}

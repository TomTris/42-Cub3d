/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:17:44 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/13 19:44:29 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	calculate_distance(t_data *data, t_ray *ray, \
double *distance1, double *distance2)
{
	*distance1 = sqrt(pow(ray->t_xv - data->player->x, 2.0) + \
	pow(ray->t_yv - data->player->y, 2.0));
	*distance2 = sqrt(pow(ray->t_x - data->player->x, 2.0) + \
	pow(ray->t_y - data->player->y, 2.0));
}

void	draw_rays(t_data *data, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < AMOUNT_OF_RAYS)
	{
		get_cords(data, add_angles(data->player->angle_turn_horizontal, \
		M_PI / 3.0 / AMOUNT_OF_RAYS * ((double) i) - (M_PI / 6.0)), &ray[i]);
		transform_cordinates(data, &ray[i]);
		DDA(data, &ray[i]);
		i++;
	}
}

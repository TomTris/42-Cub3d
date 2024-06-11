/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:17:44 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/11 16:27:03 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	draw_rays(t_data *data)
{
	double	x;
	double	y;
	t_ray	ray;
	
	get_cords(data, data->player->angle_turn_horizontal, &x, &y);
	ray.x = x;
	ray.y = y;
	transform_cordinates(data, &ray);
	DDA(data, &ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:17:44 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/12 18:09:22 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	draw_rays(t_data *data)
{
	t_ray	ray;
	
	ray.should = 0;
	ray.shouldv = 0;
	get_cords(data, data->player->angle_turn_horizontal, &ray);
	transform_cordinates(data, &ray);
	write(1, "ad", 2);
	DDA(data, &ray);
}

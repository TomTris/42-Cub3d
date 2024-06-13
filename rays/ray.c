/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:17:44 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/13 15:12:14 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	draw_rays(t_data *data)
{
	t_ray	ray[2000];
	
	for (int i = 0; i < 2000; i++)
	{
	get_cords(data, add_angles(data->player->angle_turn_horizontal, M_PI / 6000.0 * ((double) i) - (M_PI / 6.0) ), &ray[i]);
	transform_cordinates(data, &ray[i]);
	DDA(data, &ray[i]);
	}
}

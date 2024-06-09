/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:18:53 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/09 12:19:36 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	move(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		data->player->angle_turn_vertical += 1.0;
		if (data->player->angle_turn_vertical > 60.0)
			data->player->angle_turn_vertical = 60.0;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		data->player->angle_turn_vertical -= 1.0;
		if (data->player->angle_turn_vertical < -60.0)
			data->player->angle_turn_vertical = -60.0;
	}
}

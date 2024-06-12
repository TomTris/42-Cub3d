/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:18:53 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/12 17:24:24 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	rotate_view(t_data *data)
{
	double	t;

	t = data->player->angle_turn_horizontal;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		t = add_angles(t, 0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		t = add_angles(t, -0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_up(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
	data->player->angle_turn_horizontal = t;
}

void	exiting(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data += 0;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}

void	move(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	rotate_view(data);
}

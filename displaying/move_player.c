/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:18:53 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 14:27:07 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	rotate_view(t_data *data)
{
	double	t;
	int		boost;

	t = data->player->angle_turn_horizontal;
	boost = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		boost = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		t = add_angles(t, -0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		t = add_angles(t, 0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_in_line(data, data->player->angle_turn_horizontal, boost);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_in_line(data, \
		add_angles(data->player->angle_turn_horizontal, M_PI), boost);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_in_line(data, \
		add_angles(data->player->angle_turn_horizontal, M_PI / 2.0), boost);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_in_line(data, \
		add_angles(data->player->angle_turn_horizontal, M_PI / -2.0), boost);
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
	t_data		*data;
	static int	can_do = 0;

	data = (t_data *)param;
	if (!can_do && mlx_is_key_down(data->mlx, MLX_KEY_F))
	{
		can_do += 1;
		open_close_nearst_door(data);
	}
	else
	{
		if (can_do != 0)
		{
			can_do += 1;
			can_do %= 100;
		}
		rotate_view(data);
	}
}

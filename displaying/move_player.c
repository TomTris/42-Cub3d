/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:18:53 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/15 15:23:52 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

	data = (t_data *)param;
	rotate_view(data);
}

void	mouse(void	*param)
{
	static int	first = 1;
	t_data		*data;
	int32_t		x;
	int32_t		y;

	data = (t_data *)param;
	if (first < 20)
	{
		mlx_set_mouse_pos(data->mlx, WIDTH / 2, HEIGHT / 2);
		first++;
	}
	else
	{
		mlx_get_mouse_pos(data->mlx, &x, &y);
		data->player->angle_turn_horizontal = add_angles \
		(data->player->angle_turn_horizontal, (double)(WIDTH / 2 - x) / 1000.0);
		mlx_set_mouse_pos(data->mlx, WIDTH / 2, HEIGHT / 2);
	}
}

void	draw_floor_ceiling(t_data *data)
{
	int	swapper;
	int	i;
	int	e;

	i = 0;
	swapper = data->image->height / 2;
	while (i < (int)data->image->height)
	{
		e = 0;
		while (e < (int)data->image->width)
		{
			if (i < swapper)
				mlx_put_pixel(data->image, e, i, data->ceiling);
			else
				mlx_put_pixel(data->image, e, i, data->floor);
			e++;
		}
		i++;
	}
}

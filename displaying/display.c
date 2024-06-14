/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:33:19 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 19:09:11 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	test(void *param)
{
	static int	can_do = 0;
	t_data		*data;
	t_ray		ray[(int)AMOUNT_OF_RAYS];

	data = (t_data *)param;
	draw_floor_ceiling(data);
	draw_mini_map(data, ray);
	if (!can_do && mlx_is_key_down(data->mlx, MLX_KEY_F))
	{
		can_do += 1;
		handle_door(data, &ray[(int)AMOUNT_OF_RAYS / 2]);
	}
	else
	{
		if (can_do != 0)
		{
			can_do += 1;
			can_do %= 10;
		}
	}
}

void	ft_cpy_map_to_data(t_data *data, t_map *parsing)
{
	data->so = mlx_load_png(parsing->so);
	data->we = mlx_load_png(parsing->we);
	data->ea = mlx_load_png(parsing->ea);
	data->no = mlx_load_png(parsing->no);
	data->cursor = mlx_load_png("textures/empty.png");
	data->door = mlx_load_png("textures/door.png");
	if (!data->so || !data->we || !data->no || !data->ea || !data->cursor \
	|| !data->door)
		return (freeing_textures(data), free_t_map(parsing), exit(1));
	data->map = parsing->map;
	data->player->x = parsing->y;
	data->player->y = parsing->x;
	data->floor = parsing->floor;
	data->map_height = len_2d_array(data->map);
	data->map_width = ft_str_len(data->map[0]);
	data->player->angle_turn_horizontal = 3.0 * M_PI / 2.0;
	if (parsing->dire == 0)
		data->player->angle_turn_horizontal = 0.0;
	else if (parsing->dire == 1)
		data->player->angle_turn_horizontal = M_PI / 2.0;
	else if (parsing->dire == 2)
		data->player->angle_turn_horizontal = M_PI;
	data->ceiling = parsing->ceiling;
	free_t_map_0_map(parsing);
}

void	init_data2(t_data *data)
{
	data->weapon = mlx_texture_to_image(data->mlx, data->weapon_textures[0]);
	if (!data->weapon)
		return (mlx_delete_image(data->mlx, data->image), \
		mlx_delete_image(data->mlx, data->minimap), \
		mlx_close_window(data->mlx), free_data_pre_init(data), \
		exit(EXIT_FAILURE));
	if (mlx_image_to_window(data->mlx, data->weapon, data->mlx->width - \
	data->weapon->width - 1, data->mlx->height - data->weapon->height))
		return (mlx_delete_image(data->mlx, data->image), \
		mlx_delete_image(data->mlx, data->minimap), \
		mlx_delete_image(data->mlx, data->weapon), \
		mlx_close_window(data->mlx), free_data_pre_init(data), \
		exit(EXIT_FAILURE));
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Best Game", false);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
		return (mlx_close_window(data->mlx), free_data_pre_init(data), \
		exit(EXIT_FAILURE));
	data->minimap = mlx_new_image(data->mlx, AMOUNT_SQUARES * MINIMAP_SQUARE, \
	AMOUNT_SQUARES * MINIMAP_SQUARE);
	if (!data->minimap)
		return (mlx_delete_image(data->mlx, data->image), \
		mlx_close_window(data->mlx), free_data_pre_init(data), \
		exit(EXIT_FAILURE));
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1 || \
	mlx_image_to_window(data->mlx, data->minimap, 0, \
	data->image->height - data->minimap->height) == -1)
		return (mlx_delete_image(data->mlx, data->image), \
		mlx_delete_image(data->mlx, data->minimap), \
		mlx_close_window(data->mlx), free_data_pre_init(data), \
		exit(EXIT_FAILURE));
	init_data2(data);
}

int	display(t_data *data, t_map *parsing)
{
	ft_cpy_map_to_data(data, parsing);
	init_weapon(data);
	init_data(data);
	data->mlx_cur = mlx_create_cursor(data->cursor);
	mlx_set_cursor(data->mlx, data->mlx_cur);
	mlx_set_mouse_pos(data->mlx, 400, 300);
	mlx_loop_hook(data->mlx, test, data);
	mlx_loop_hook(data->mlx, move, data);
	mlx_loop_hook(data->mlx, mouse, data);
	mlx_key_hook(data->mlx, exiting, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free_data_pre_init(data);
	return (1);
}

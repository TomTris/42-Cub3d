/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:33:19 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/11 20:17:38 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	draw_floor_ceiling(t_data *data)
{
	int	swapper;
	int	i;
	int	e;

	i = 0;
	swapper = data->image->height / 2 + data->player->angle_turn_vertical / \
	data->player->angle_view * data->image->height / 2;
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

void	test(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	// draw_floor_ceiling(data);
	draw_mini_map(data);
	// mlx_close_window(data->mlx);
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Best Game", true);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
		return (mlx_close_window(data->mlx), exit(EXIT_FAILURE));
	data->minimap = mlx_new_image(data->mlx, 288, 288);
	if (!data->minimap)
		return (mlx_delete_image(data->mlx, data->image), \
		mlx_close_window(data->mlx), exit(EXIT_FAILURE));
	if (mlx_image_to_window(data->mlx, data->minimap, 0, \
	data->image->height - data->minimap->height))
		return (mlx_delete_image(data->mlx, data->image), \
		mlx_delete_image(data->mlx, data->minimap), \
		mlx_close_window(data->mlx), exit(EXIT_FAILURE));
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		return (mlx_delete_image(data->mlx, data->image), \
		mlx_delete_image(data->mlx, data->minimap), \
		mlx_close_window(data->mlx), exit(EXIT_FAILURE));
}

int	display(t_data *data)
{

	init_data(data);
	printf("%f\n", data->player->angle_turn_horizontal);
	mlx_loop_hook(data->mlx, test, data);
	mlx_loop_hook(data->mlx, move, data);
	mlx_key_hook(data->mlx, exiting, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (1);
}

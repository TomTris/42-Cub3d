

#include "../cube3d.h"

void	draw_helper(t_data *data)
{
	int	swapper;
	int	i;
	int	e;

	i = 0;
	swapper = data->image->height / 2 + data->player->angle_turn_vertical / \
	data->player->angle_view * data->image->height / 2;
	dprintf(1, "%i %f\n", swapper, data->player->angle_turn_vertical);
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

void	draw_floor_ceiling(t_data *data)
{
	t_player	*player;

	player = data->player;

		draw_helper(data);
}

void	test(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	draw_floor_ceiling(data);

	// mlx_close_window(data->mlx);
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Best Game", true);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		mlx_close_window(data->mlx);
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		exit(EXIT_FAILURE);
	}
}

void	init_player(t_data *data, t_player *player)
{
	player->x = 0.0;
	player->y = 0.0;
	player->z = 0.0;
	player->angle_view = 30.0;
	player->angle_turn_horizontal = 0.0;
	player->angle_turn_vertical = 0.0;
	data->floor = 225 << 24 | 30 << 16 | 0 << 8 | 255;
	// data->floor = 255 << 8 | 255;
	data->ceiling = 255 << 16 | 255;
	data->player = player;
}

int	display(t_data *data)
{
	t_player	player;

	init_data(data);
	init_player(data, &player);
	mlx_loop_hook(data->mlx, test, data);
	mlx_loop_hook(data->mlx, move, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (1);
}

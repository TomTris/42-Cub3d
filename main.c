#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "cube3d.h"
#include <math.h>
#include <unistd.h>

#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;

void static	solve(long long n, int fd)
{
	char	t;

	if (n)
	{
		solve(n / 10, fd);
		t = (n % 10) + '0';
		write(fd, &t, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	t;

	t = n;
	if (t < 0)
	{
		t = -t;
		write(fd, "-", 1);
	}
	if (t == 0)
		write(fd, "0", 1);
	else
		solve(t, fd);
}

// -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

	// if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	// 	mlx_close_window(mlx);
	// if (mlx_is_key_down(mlx, MLX_KEY_UP))
	// 	image->instances[0].y -= 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	// 	image->instances[0].y += 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	// 	image->instances[0].x -= 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	// 	image->instances[0].x += 5;
// }

// -----------------------------------------------------------------------------

static t_cube	cube;

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

void	draw_square(t_data *data, int x, int y, int color)
{
	for (int i = -1; i < 2; i++)
	{
		for (int e = -1; e < 2; e++)
		{
			mlx_put_pixel(data->image, x + i, y + e, color);
		}
	}
}

void	draw_full(t_data *data, u_int32_t color)
{
	for (int i = 0; i < data->image->width; i++)
	{
		for (int e = 0; e < data->image->height; e++)
		{
			mlx_put_pixel(data->image, i, e, color);
		}
	}
}

void	draw_helper(t_data *data)
{
		
	int	swapper = data->image->height / 2 + data->player->angle_turn_vertical / data->player->angle_view * data->image->height / 2;
	dprintf(1, "%i %f\n", swapper, data->player->angle_turn_vertical);
	for (int i = 0; i < data->image->height; i++)
	{
		for (int e = 0; e < data->image->width; e++)
		{
			if (i < swapper)
			{
				mlx_put_pixel(data->image, e, i, data->ceiling);
			}
			else
			{
				mlx_put_pixel(data->image, e, i, data->floor);
			}
		}
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

int	main(void)
{
	t_data		data;
	t_player	player;

	data.mlx = mlx_init(WIDTH, HEIGHT, "Best Game", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.image = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.image)
	{
		mlx_close_window(data.mlx);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(data.mlx, data.image, 0, 0) == -1)
	{
		mlx_close_window(data.mlx);
		return (EXIT_FAILURE);
	}
	player.x = 0.0;
	player.y = 0.0;
	player.z = 0.0;
	player.angle_view = 30.0;
	player.angle_turn_horizontal = 0.0;
	player.angle_turn_vertical = 0.0;
	data.floor = 255 << 8 | 255;
	data.ceiling = 255 << 16 | 255;
	data.player = &player;
	mlx_loop_hook(data.mlx, test, &data);
	mlx_loop_hook(data.mlx, move, &data);

	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
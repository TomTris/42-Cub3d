/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:35:48 by qdo               #+#    #+#             */
/*   Updated: 2024/06/13 20:53:13 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

#define WINDOW_HEIGHT 1024
#define WINDOW_WIDTH 1024

unsigned int	get_pixel(mlx_texture_t *texture, int wid, int hei)
{
	int		ret;
	uint8_t	*temp;
	int		i;

	temp = &texture->pixels[(wid * texture->width + hei) * sizeof(u_int32_t)];
	ret = 0;
	i = -1;
	while (++i < 4)
	{
		ret = ret << 8;
		ret = ret | *temp;
		temp += 1;
	}
	return (ret);
}

// void	render_height_more_than_1(mlx_image_t *image, int texture_hei, double rate, int wid_on_texture)
// {

// }

// void	render_height_less_than_1(mlx_image_t *image, int texture_hei, double rate, int wid_on_texture)
// {
// 	int	

// 	mlx_put_pixel(image, wid_on_texture, , 255 << 16 | 10);	
// }

void	render_height(mlx_image_t *image, mlx_texture_t *texture, int texture_hei, double rate, int wid_on_texture, int wid_on_screen)
{
	int	hei_highest = WINDOW_HEIGHT / 2 + WINDOW_HEIGHT * rate;
	int	height_cnt = WINDOW_HEIGHT;
	int height_on_texture;
	int	a = 0;

	while (height_cnt > hei_highest)
	{
		mlx_put_pixel(image, wid_on_screen, height_cnt--, 100<<16 | 255);
		// printf("a\n");
	}
	hei_highest = WINDOW_HEIGHT / 2 - rate * WINDOW_HEIGHT;
	while (height_cnt > hei_highest)
	{
		height_on_texture = (height_cnt - hei_highest) / (WINDOW_HEIGHT - 2 * hei_highest) * texture_hei;
		mlx_put_pixel(image, wid_on_screen, height_cnt, get_pixel(texture, wid_on_texture, height_on_texture));
		height_cnt--;
	}
	while (height_cnt > 0)
	{
		mlx_put_pixel(image, wid_on_screen, height_cnt--, 255 << 8 | 10);
		// printf("a =\n");
	}
}

// mlx_put_pixel(data.image, i, j, 255 << 16 | 10);
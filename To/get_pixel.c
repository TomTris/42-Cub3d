/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:35:48 by qdo               #+#    #+#             */
/*   Updated: 2024/06/14 10:45:06 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

#define WINDOW_HEIGHT 1023
#define WINDOW_WIDTH 1023
#define RATE_SCREEN 1/2

int	raya(int a1, int b)
{
	static int a = 0;

	if (b == 1)
		return (a);
	a = a1;
	return (0);
}

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
		if (temp == 0)
			ret = ret | 0;
		else
		{
			// write(1, "a\n", 2);
			ret = ret | temp[i];
			// write(1, "b\n", 2);
		}
	}
	return (ret);
}


void	render_height(mlx_image_t *image, mlx_texture_t *texture, int texture_hei, double rate, int wid_on_texture, int wid_on_screen)
{
	double	height_on_texture;
	double	height_cnt ;
	double	hei_highest ;
	int		a;
	int		b;
	if (rate >= 1)
	{
		height_cnt = WINDOW_HEIGHT;
		hei_highest = 0;
	}
	else
	{
		height_cnt = (WINDOW_HEIGHT  + WINDOW_HEIGHT * rate) / 2;
		hei_highest = (WINDOW_HEIGHT  - WINDOW_HEIGHT * rate) / 2;
	}
	while (height_cnt >= hei_highest)
	{
		height_on_texture =  (height_cnt - hei_highest) /  (WINDOW_HEIGHT - 2 * hei_highest) *  texture_hei;
		if ((int) lround(height_on_texture) == texture_hei)
			a = (int) lround(height_on_texture) - 1;
		else
			a = (int) lround(height_on_texture);
		if (wid_on_texture > 0)
			b = wid_on_texture - 1;
		else
			b = wid_on_texture;
		mlx_put_pixel(image, wid_on_screen,(int) height_cnt, get_pixel(texture, b, a));
		height_cnt -= 1;
	}
}

// mlx_put_pixel(data.image, i, j, 255 << 16 | 10);
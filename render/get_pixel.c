/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:35:48 by qdo               #+#    #+#             */
/*   Updated: 2024/06/14 20:23:13 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#define WINDOW_HEIGHT 1023
#define WINDOW_WIDTH 1023

unsigned int	get_pixel(mlx_texture_t *texture, int wid, int hei)
{
	int		ret;
	uint8_t	*temp;
	int		i;

	temp = &texture->pixels[(hei * texture->width + wid) * sizeof(u_int32_t)];
	ret = 0;
	i = -1;
	while (++i < 4)
	{
		ret = ret << 8;
		if (temp == 0)
			ret = ret | 0;
		else
			ret = ret | temp[i];
	}
	return (ret);
}

void	render_height_less_than_1(t_render *r)
{
	double	height_on_texture;
	double	height_cnt ;
	double	hei_highest ;
	int		a;
	int		b;

	height_cnt = (WINDOW_HEIGHT + WINDOW_HEIGHT * r->rate) / 2;
	hei_highest = (WINDOW_HEIGHT - WINDOW_HEIGHT * r->rate) / 2;
	while (height_cnt >= hei_highest)
	{
		height_on_texture = (height_cnt - hei_highest) \
		/ (WINDOW_HEIGHT - 2 * hei_highest) * r->texture_hei;
		a = (int) lround(height_on_texture);
		if ((int) lround(height_on_texture) == r->texture_hei)
			a = (int) lround(height_on_texture) - 1;
		b = r->wid_on_texture;
		if (r->wid_on_texture > 0)
			b = r->wid_on_texture - 1;
		mlx_put_pixel(r->image, r->wid_on_screen, (int) height_cnt,
			get_pixel(r->texture, b, a));
		height_cnt -= 1;
	}
}

void	render_height_more_than_1(t_render *r)
{
	double	height_on_texture;
	double	height_cnt;
	int		a;
	int		b;
	double	down_part;

	down_part = ((r->rate - 1) / 2) / r->rate * r->texture_hei;
	height_cnt = WINDOW_HEIGHT;
	while (height_cnt >= 0)
	{
		height_on_texture = (height_cnt / WINDOW_HEIGHT) \
		* r->texture_hei / r->rate + down_part;
		a = (int) lround(height_on_texture);
		if ((int) lround(height_on_texture) == r->texture_hei)
			a = (int) lround(height_on_texture) - 1;
		b = r->wid_on_texture;
		if (r->wid_on_texture > 0)
			b = r->wid_on_texture - 1;
		mlx_put_pixel(r->image, r->wid_on_screen, (int) height_cnt,
			get_pixel(r->texture, b, a));
		height_cnt -= 1;
	}
}

void	render_height(t_render *r)
{
	if (r->rate > 1)
		render_height_more_than_1(r);
	else
		render_height_less_than_1(r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:00:29 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 19:34:39 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

typedef struct s_norm_facing
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		steps;
	double	xinc;
	double	yinc;
	double	x;
	double	y;
}	t_norm_facing;

uint32_t	limits(u_int32_t	t)
{
	if (t > AMOUNT_SQUARES * AMOUNT_SQUARES - 1)
		return (AMOUNT_SQUARES * AMOUNT_SQUARES - 1);
	return (t);
	
}

void	dda(t_data *data, t_ray *ray)
{
	int				i;
	t_norm_facing	var;

	var.x0 = ray->start_pos_x;
	var.x1 = ray->map_cord_x;
	var.y0 = ray->start_pos_y;
	var.y1 = ray->map_cord_y;
	var.dx = var.x1 - var.x0;
	var.dy = var.y1 - var.y0;
	if (abs(var.dx) > abs(var.dy))
		var.steps = abs(var.dx);
	else
		var.steps = abs(var.dy);
	var.xinc = var.dx / (double)var.steps;
	var.yinc = var.dy / (double)var.steps;
	var.x = var.x0;
	var.y = var.y0;
	i = -1;
	while (++i <= var.steps)
	{
		mlx_put_pixel(data->minimap, limits((uint32_t)lround(var.x)),
			limits((uint32_t)lround(var.y)), 255 << 16 | 255);
		var.x += var.xinc;
		var.y += var.yinc;
	}
}

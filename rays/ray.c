/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:17:44 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 19:30:28 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	calculate_distance(t_data *data, t_ray *ray, \
double *distance1, double *distance2)
{
	*distance1 = sqrt(pow(ray->t_xv - data->player->x, 2.0) + \
	pow(ray->t_yv - data->player->y, 2.0));
	*distance2 = sqrt(pow(ray->t_x - data->player->x, 2.0) + \
	pow(ray->t_y - data->player->y, 2.0));
}

double	get_distance_to_point(t_player *player, double x, double y)
{
	return (sqrt(pow(x - player->x, 2.0) + pow(player->y - y, 2.0)));
}

mlx_texture_t	*get_texture(t_data *data, t_ray *ray, int texture)
{
	if (data->map[(int)ray->y][(int)ray->x] == 'd')
		return (data->door);
	if (texture == 0)
		return (data->ea);
	else if (texture == 1)
		return (data->no);
	else if (texture == 2)
		return (data->we);
	else
		return (data->so);
}

int	get_wid_on_texture(t_data *data, t_ray *ray)
{
	mlx_texture_t	*temp;
	double			t;

	temp = get_texture(data, ray, ray->texture);
	if (ray->texture == 0)
	{
		t = fabs(ray->y - (double)((int)ray->y));
	}
	else if (ray->texture == 1)
	{
		t = fabs(ray->x - (double)((int)ray->x));
	}
	else if (ray->texture == 2)
	{
		t = fabs(ray->y - (double)((int)ray->y));
	}
	else
	{
		t = fabs(ray->x - (double)((int)ray->x));
	}
	return ((int)lround(t * temp->width));
}

void	draw_rays(t_data *data, t_ray *ray)
{
	int				i;
	t_render		render;

	i = 0;
	while (i < AMOUNT_OF_RAYS)
	{
		ray[i].closest_door_x = 1000000000.0;
		ray[i].closest_door_y = 1000000000.0;
		get_cords(data, add_angles(data->player->angle_turn_horizontal, \
		M_PI / 3.0 / AMOUNT_OF_RAYS * ((double) i) - (M_PI / 6.0)), &ray[i]);
		transform_cordinates(data, &ray[i]);
		render.image = data->image;
		render.texture = get_texture(data, &ray[i], ray[i].texture);
		render.texture_hei = render.texture->height;
		render.rate = 1.0 / ray[i].distance;
		render.wid_on_texture = get_wid_on_texture(data, &ray[i]);
		render.wid_on_screen = AMOUNT_OF_RAYS - 1 - i;
		render_height(&render);
		i++;
	}
	dda(data, &ray[AMOUNT_OF_RAYS / 2]);
}

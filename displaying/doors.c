/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:39:01 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 19:09:24 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	swap(char *c)
{
	if (*c == 'd')
		*c = 'D';
	else
		*c = 'd';
}

void	push_back(t_data *data, t_player *player, int i)
{
	if (i == 2)
	{
		if (player->y - (double)((int)player->y) < MINDISTANCE)
			player->y = (double)((int)player->y) + MINDISTANCE;
		swap(&(data->map[(int)player->y - 1][(int)player->x]));
	}
	if (i == 1)
	{
		if ((double)((int)player->y + 1) - player->y > 1.0 - MINDISTANCE)
			player->y = (double)((int)player->y + 1) - MINDISTANCE;
		swap(&(data->map[(int)player->y + 1][(int)player->x]));
	}
	if (i == 3)
	{
		if ((double)((int)player->x + 1) - player->x > 1.0 - MINDISTANCE)
			player->x = (double)((int)player->x + 1) - MINDISTANCE;
		swap(&(data->map[(int)player->y][(int)player->x + 1]));
	}
	if (i == 4)
	{
		if (player->x - (double)((int)player->x) < MINDISTANCE)
			player->x = (double)((int)player->x) + MINDISTANCE;
		swap(&(data->map[(int)player->y][(int)player->x - 1]));
	}
}

void	handle_door(t_data *data, t_ray *ray)
{
	double		d;
	t_player	*player;

	player = data->player;
	d = get_distance_to_point(data->player, \
	ray->closest_door_x, ray->closest_door_y);
	if (d <= 2.0)
	{
		swap(&(data->map[(int)ray->closest_door_y][(int)ray->closest_door_x]));
		if (player->x - (double)((int)player->x) < MINDISTANCE)
			player->x = (double)((int)player->x) + MINDISTANCE;
		if (player->y - (double)((int)player->y) < MINDISTANCE)
			player->y = (double)((int)player->y) + MINDISTANCE;
		if ((double)((int)player->y + 1) - player->y > 1.0 - MINDISTANCE)
			player->y = (double)((int)player->y + 1) - MINDISTANCE;
		if ((double)((int)player->x + 1) - player->x > 1.0 - MINDISTANCE)
			player->x = (double)((int)player->x + 1) - MINDISTANCE;
	}
}

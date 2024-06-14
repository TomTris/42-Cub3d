/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:39:01 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 14:45:59 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	g_case_1(t_data *data, double *x, double *y, int *t)
{
	if (data->map[(int)data->player->y + 1][(int)data->player->x] == 'd' || \
	data->map[(int)data->player->y][(int)data->player->x] == 'D')
	{
		if (get_distance_to_point(data->player, *x, *y) > \
		get_distance_to_point(data->player, (double)((int)data->player->x) \
		+ 0.5, (double)((int)data->player->y + 1) + 0.5))
		{
			*x = (double)((int)data->player->x) + 0.5;
			*y = (double)((int)data->player->y + 1) + 0.5;
			*t = 1;
		}
	}
	if (data->map[(int)data->player->y - 1][(int)data->player->x] == 'd' || \
	data->map[(int)data->player->y][(int)data->player->x] == 'D')
	{
		if (get_distance_to_point(data->player, *x, *y) > \
		get_distance_to_point(data->player, (double)((int)data->player->x) \
		+ 0.5, (double)((int)data->player->y - 1) + 0.5))
		{
			*x = (double)((int)data->player->x) + 0.5;
			*y = (double)((int)data->player->y - 1) + 0.5;
			*t = 2;
		}
	}
}

static void	g_case_2(t_data *data, double *x, double *y, int *t)
{
	if (data->map[(int)data->player->y][(int)data->player->x + 1] == 'd' || \
	data->map[(int)data->player->y][(int)data->player->x] == 'D')
	{
		if (get_distance_to_point(data->player, *x, *y) > \
		get_distance_to_point(data->player, (double)((int)data->player->x + 1) \
		+ 0.5, (double)((int)data->player->y) + 0.5))
		{
			*x = (double)((int)data->player->x + 1) + 0.5;
			*y = (double)((int)data->player->y) + 0.5;
			*t = 3;
		}
	}
	if (data->map[(int)data->player->y][(int)data->player->x - 1] == 'd' || \
	data->map[(int)data->player->y][(int)data->player->x] == 'D')
	{
		if (get_distance_to_point(data->player, *x, *y) > \
		get_distance_to_point(data->player, (double)((int)data->player->x - 1) \
		+ 0.5, (double)((int)data->player->y) + 0.5))
		{
			*x = (double)((int)data->player->x - 1) + 0.5;
			*y = (double)((int)data->player->y) + 0.5;
			*t = 4;
		}
	}
}

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

void	open_close_nearst_door(t_data *data)
{
	double	x;
	double	y;
	int		t;

	t = -1;
	x = (double)100000000.0;
	y = (double)100000000.0;
	g_case_1(data, &x, &y, &t);
	g_case_2(data, &x, &y, &t);
	if (t != -1)
	{
		push_back(data, data->player, t);
	}
}

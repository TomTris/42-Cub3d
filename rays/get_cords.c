/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:36:45 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/11 12:58:24 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	get_angle_0_180(t_data *data, double *x, double *y, int i)
{
	int	addition;
	int	player_x;

	player_x = (int)data->player->x;
	if (i == 0)
		addition = 1;
	else
		addition = -1;
	while (data->map[(int)data->player->y][player_x] != '1')
		player_x = player_x + addition;
	if (addition == -1)
		player_x += 1;
	*x = (double)player_x;
	*y = data->player->y;
}

void	get_angle_90_270(t_data *data, double *x, double *y, int i)
{
	int	addition;
	int	player_y;

	player_y = (int)data->player->y;
	if (i == 0)
		addition = -1;
	else
		addition = 1;
	while (data->map[player_y][(int)data->player->x] != '1')
		player_y = player_y + addition;
	if (addition == -1)
		player_y += 1;
	*x = data->player->x;
	*y = (double)player_y;
}

void	get_horizontal(t_data *data, double angle, double *x, double *y)
{
	double	m;
	double	factor_x;
	double	factor_y;
	double	t_x;
	double	t_y;

	m = fabs(tan(angle));
	if (angle < M_PI / 2 && angle > M_PI * 3 / 2)
		factor_x = -1.0;
	else
		factor_x = 1.0;
	m = 1 / m;
	if (angle < M_PI)
		factor_y = -1.0;
	else
		factor_y = 1.0;
	t_x = data->player->x;
	t_y = data->player->y;
	while (data->map[(int)t_y][(int)t_x])
	{
		t_x += (m * factor_x);
		t_y += (factor_y * 1.0);
	}
	if (factor_y == -1.0)
		t_y += 1.0;
	*x = t_x;
	*y = t_y;
}

void	get_normal(t_data *data, double angle, double *x, double *y)
{
	get_horizontal(data, angle, x, y);
}

void	get_cords(t_data *data, double angle, double *x, double	*y)
{
	if (angle == 0)
		get_angle_0_180(data, x, y, 0);
	else if (angle == M_PI)
		get_angle_0_180(data, x, y, 1);
	else if (angle == M_PI / 2)
		get_angle_90_270(data, x, y, 0);
	else if (angle == 3 * M_PI / 2)
		get_angle_90_270(data, x, y, 1);
	else
		get_normal(data, angle, x, y);
}
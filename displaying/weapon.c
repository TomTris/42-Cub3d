/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:14:59 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 20:23:13 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	delete_weapon_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		if (data->weapon_textures[i] != NULL)
		{
			mlx_delete_texture(data->weapon_textures[i]);
		}
		else
			return ;
		i++;
	}
}

int	init_textures_weapon(t_data *data)
{
	int		i;
	char	*t;
	char	*n;

	i = 0;
	while (i < 50)
	{
		n = to_string(i + 1);
		if (!n)
			return (0);
		t = str_join("textures/weapon/", n);
		free(n);
		if (!t)
			return (0);
		n = str_join(t, ".png");
		free(t);
		if (!n)
			return (0);
		data->weapon_textures[i] = mlx_load_png(n);
		free(n);
		if (!data->weapon_textures[i])
			return (0);
		i++;
	}
	return (1);
}

void	init_weapon(t_data *data)
{
	if (!init_textures_weapon(data))
	{
		return (free_data_pre_init(data), exit(1));
	}
}

void	displaying_frame(t_data *data, mlx_image_t *weapon, \
mlx_texture_t *texture)
{
	int	len;
	int	i;

	data += 0;
	if (texture->width != weapon->width || texture->height != weapon->height)
		return (mlx_close_window(data->mlx));
	len = weapon->height * weapon->width * sizeof(u_int32_t);
	i = 0;
	while (i < len)
	{
		weapon->pixels[i] = texture->pixels[i];
		i++;
	}
}

void	display_wapon(t_data *data)
{
	static int	counter = 0;
	int			index;

	index = counter / 3;
	if (index > 49)
		index = 99 - index;
	displaying_frame(data, data->weapon, data->weapon_textures[index]);
	counter++;
	counter %= 300;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:40:26 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 19:09:43 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	freeing_textures(t_data *data)
{
	if (data->so)
		mlx_delete_texture(data->so);
	if (data->we)
		mlx_delete_texture(data->we);
	if (data->ea)
		mlx_delete_texture(data->ea);
	if (data->no)
		mlx_delete_texture(data->no);
	if (data->cursor)
		mlx_delete_texture(data->cursor);
	if (data->door)
		mlx_delete_texture(data->door);
}

void	free_data_pre_init(t_data *data)
{
	freeing_textures(data);
	free_split(data->map);
	mlx_destroy_cursor(data->mlx_cur);
	delete_weapon_textures(data);
}

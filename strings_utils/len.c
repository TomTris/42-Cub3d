/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:55:08 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/11 19:10:51 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	len_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}

void	change_one_to_zero(t_data *data, char **array)
{
	int	i;
	int	e;

	i = 0;
	while (array[i])
	{
		e = 0;
		while (array[i][e])
		{
			if (array[i][e] == '1')
				array[i][e] = '0';
			else
				array[i][e] = '1';
			e++;
		}
		i++;
	}
	array[(int)data->player->y][(int)data->player->x] = '0';
}

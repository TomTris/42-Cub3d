/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:32:29 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/09 12:19:50 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_player
{
	double	x;
	double	y;
	double	angle_view;
	double	z;
	double	distance;
	double	angle_turn_horizontal;
	double	angle_turn_vertical;
	double	height;
	double	width;
}	t_player;

typedef struct s_data
{
	t_player	*player;
	mlx_t		*mlx;
	mlx_image_t	*image;
	uint32_t	ceiling;
	uint32_t	floor;
}	t_data;

# define WIDTH 512
# define HEIGHT 512

int		display(t_data *data);
void	move(void *param);

#endif
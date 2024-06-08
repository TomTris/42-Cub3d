/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:32:29 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/07 11:25:39 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

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

typedef	struct s_cube
{
	double	points[8][3];
	int	amount;
}	t_cube;



#endif
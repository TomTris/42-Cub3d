/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:32:29 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/13 21:12:46 by obrittne         ###   ########.fr       */
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
# include "parsing/parsing.h"

typedef struct s_ray
{
	double	x;
	double	y;
	int		map_cord_x;
	int		map_cord_y;
	int		start_pos_x;
	int		start_pos_y;
	int		pos_x;
	int		pos_y;
	double	t_y;
	double	t_x;
	double	t_yv;
	double	t_xv;
	double	ta;
	double	distance;
	double	x_factor;
	double	y_factor;
	double	x_factor_f;
	double	y_factor_f;
	int		texture;
}	t_ray;

typedef struct s_mini
{
	int	x;
	int	y;
	int	x_player;
	int	y_player;
	int	can_access;
	int	end;
}	t_mini;

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
	t_player		*player;
	mlx_t			*mlx;
	mlx_image_t		*image;
	uint32_t		ceiling;
	uint32_t		floor;
	char			**map;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	int				map_height;
	int				map_width;
	mlx_image_t		*minimap;
}	t_data;

# define WIDTH 1024
# define HEIGHT 1024

# define MINMOVE 0.03125
# define MINDISTANCE 0.125

# define AMOUNT_OF_RAYS 100

int		display(t_data *data, t_map *parsing);
void	move(void *param);
void	exiting(mlx_key_data_t keydata, void *param);
void	display_sphere(t_data *data);
double	add_angles(double angle1, double angle2);
void	draw_mini_map(t_data *data, t_ray *ray);
void	move_in_line(t_data *data, double angle);
void	draw_player(t_data *data);
void	get_cords(t_data *data, double angle, t_ray *ray);
void	DDA(t_data *data, t_ray *ray);
void	transform_cordinates(t_data *data, t_ray *ray);
void	draw_rays(t_data *data, t_ray *ray);
int		len_2d_array(char **array);
int		is_not_walkable(char c);
int		ft_str_len(char *str);
void	freeing_textures(t_data *data);
void	free_data_pre_init(t_data *data);
void	get_vertical(t_data *data, double angle, t_ray *ray);
void	get_horizontal(t_data *data, double angle, t_ray *ray);
void	calculate_distance(t_data *data, t_ray *ray, \
double *distance1, double *distance2);




void	render_height(mlx_image_t *image, mlx_texture_t *texture, int texture_hei, double rate, int wid_on_texture, int wid_on_screen);
unsigned int	get_pixel(mlx_texture_t *texture, int wid, int hei);
#endif
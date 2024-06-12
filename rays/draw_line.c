/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:00:29 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/12 18:47:51 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"


void	DDA(t_data *data, t_ray *ray)
{
	int X0, Y0, X1, Y1;
	X0 = ray->start_pos_x;
	X1 = ray->map_cord_x;
	Y0 = ray->start_pos_y;
	Y1 = ray->map_cord_y;

    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    double Xinc = dx / (double)steps; 
    double Yinc = dy / (double)steps; 
  
    // Put pixel for each step 
    double X = X0; 
    double Y = Y0; 
    for (int i = 0; i <= steps; i++) { 
        mlx_put_pixel(data->minimap, (uint32_t)lround(X) > 287 ? 287: (uint32_t)lround(X), (uint32_t)lround(Y) > 287 ? 287: (uint32_t)lround(Y), 255 << 16 | 255);
        X += Xinc; // increment in x at each step 
        Y += Yinc; // increment in y at each step 
                    // generation step by step 
    } 
}
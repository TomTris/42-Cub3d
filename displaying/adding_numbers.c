/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:35:22 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/14 20:23:13 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	add_angles(double angle1, double angle2)
{
	angle1 += angle2;
	if (angle1 >= 2.0 * M_PI)
		angle1 -= (2.0 * M_PI);
	if (angle1 < 0.0)
		angle1 += (2.0 * M_PI);
	return (angle1);
}

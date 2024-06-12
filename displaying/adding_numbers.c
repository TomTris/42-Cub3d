/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:35:22 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/11 20:13:46 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

double	add_angles(double angle1, double angle2)
{
	angle1 += angle2;
	if (angle1 >= 2.0 * M_PI)
		angle1 -= (2.0 * M_PI);
	if (angle1 < 0.0)
		angle1 += (2.0 * M_PI);
	return (angle1);
}
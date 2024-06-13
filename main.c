/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:58:53 by obrittne          #+#    #+#             */
/*   Updated: 2024/06/13 17:16:10 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_map		*parsing;
	t_player	player;

	data.player = &player;
	parsing = ft_map(ac, av);
	if (parsing == 0)
		return (1);
	display(&data, parsing);
	system("leaks cub3d");
	return (EXIT_SUCCESS);
}

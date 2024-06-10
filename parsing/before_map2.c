/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:32:33 by qdo               #+#    #+#             */
/*   Updated: 2024/06/10 13:23:43 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_find_nbr(char *line_rest, int *i, unsigned int *set)
{
	int		j;

	while (line_rest[*i] == ' ')
		*i += 1;
	if (line_rest[*i] == '+')
		*i += 1;
	while (line_rest[*i] == '0'
		&& line_rest[*i + 1] <= '9'
		&& line_rest[*i + 1] >= '0')
		*i += 1;
	j = *i;
	while (line_rest[j] <= '9' && line_rest[j] >= '0')
		j++;
	if (j - *i <= 0 || j - *i > 3)
		return (print_fd(2, "Error\nInvalid number1\n"), 0);
	*set = 0;
	while (*i < j)
	{
		*set = *set * 10 + (line_rest[*i] - '0');
		*i += 1;
	}
	return (1);
}

int	ft_skip_comma(char *line_rest, int *i)
{
	while (line_rest[*i] == ' ')
		*i += 1;
	if (line_rest[*i] != ',')
		return (print_fd(2, "Error\nInvalid number2\n"), 0);
	*i += 1;
	return (1);
}

int	ft_convert_to_color(char *line_rest, unsigned int *set)
{
	int				i;
	unsigned int	nbr1;
	unsigned int	nbr2;
	unsigned int	nbr3;

	i = 0;
	if (!ft_find_nbr(line_rest, &i, &nbr1) || !ft_skip_comma(line_rest, &i)
		|| !ft_find_nbr(line_rest, &i, &nbr2) || !ft_skip_comma(line_rest, &i)
		|| !ft_find_nbr(line_rest, &i, &nbr3))
		return (0);
	while (line_rest[i])
	{
		if (line_rest[i] != ' ')
		{
			print_fd(2, "Error\nInvalid infos\n");
			return (0);
		}
		i++;
	}
	*set = nbr1 << 24 | nbr2 << 16 | nbr3 << 8 | 255;
	return (1);
}

int	fill_i_3(t_map *ret, int nbr, char *line_rest, int *color_change)
{
	unsigned int	*set;
	int				i;

	if (*color_change == 3
		|| (nbr == 1 && *color_change == 1) || (nbr == 2 && *color_change == 2))
		return (print_fd(2, "Error\nSet Color too many times\n"), 0);
	i = 0;
	while (line_rest[i] == ' ')
		i++;
	color_change += nbr;
	if (nbr == 1)
		set = &(ret->floor);
	else
		set = &(ret->ceiling);
	if (ft_convert_to_color(line_rest + i, set) == 0)
		return (0);
	return (1);
}

// int	ft_convert_to_color_pre_check(char *line_rest)
// {
// 	int		i;
// 	char	a;

// 	i = -1;
// 	while (line_rest[++i])
// 	{
// 		a = line_rest[i];
// 		if (!(a == ',' || (a >= '0' && a <= '9') || a == ' '))
// 			return (print_fd(2,
// 					"Error\nInvalid character in field number of color\n"), 0);
// 	}
// 	return (1);
// }

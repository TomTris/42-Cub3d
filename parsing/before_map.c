/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:12:23 by qdo               #+#    #+#             */
/*   Updated: 2024/06/09 20:05:37 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//return 0 -> not the part of map
//return 1 -> part of the map
//only space or '1' or '0' or 'N' 'W' 'S' 'E' and at least 1 '0' or '1'
int	ft_is_part_of_map(char *line)
{
	int		i;
	char	temp;
	int		cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		temp = line[i];
		if (temp == ' ' || temp == '1' || temp == '0'
			|| temp == 'N' || temp == 'W' || temp == 'S' || temp == 'E')
		{
			if (temp == '0' || temp == '1')
				cnt++;
			i++;
		}
		else
			return (0);
	}
	if (cnt >= 1)
		return (1);
	return (0);
}

char	**before_map_good(char **file_content, int *i)
{
	int		cnt_line_not_map;
	char	**ret;

	cnt_line_not_map = 0;
	ret = smerge(0, 0);
	if (ret == 0)
		return (NULL);
	while (file_content[*i] && ft_is_part_of_map(file_content[*i]) == 0)
	{
		if (is_empty_line(file_content[*i]) != 0)
			cnt_line_not_map++;
		(*i)++;
		if (cnt_line_not_map > 6)
			break ;
	}
	if (cnt_line_not_map != 6)
		return (print_fd(2, "Error\n Too many infos"),
			free_split(ret), NULL);
	return (ret);
}

int	fill_i_2(char **to_set, char *line_rest)
{
	int	i;

	i = 0;
	while (line_rest[i] == ' ')
		i++;
	if (to_set != 0 || line_rest[i] == 0)
		return (print_fd(2, "Error\nInvalid infos"), NULL);
	to_set = ft_strdup(line_rest + i);
	if (to_set == 0)
		return (0);
	return (1);
}

int	ft_convert_to_color_pre_check(char *line_rest)
{
	int		i;
	char	a;

	i = -1;
	while (line_rest[++i])
	{
		a = line_rest[i];
		if (a == ',' || (a >= '0' && a <= '9') || a == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_find_nbr(char *line_rest, int *i, int *set)
{

}

int	ft_skip_comma(char *line_rest, int *i)
{
	while (line_rest[*i])
	{
		if (line_rest[*i] == ',')
	}
}

int	ft_convert_to_color(char *line_rest, int *set)
{
	int				i;
	unsigned int	nbr1;
	unsigned int	nbr2;
	unsigned int	nbr3;

	if (ft_convert_to_color_pre_check(line_rest) == 0)
		return (0);
	i = 0;
	if (!ft_find_nbr(line_rest, &i, &nbr1) || !ft_skip_comma(line_rest, &i)
		|| !ft_find_nbr(line_rest, &i, &nbr2) || !ft_skip_comma(line_rest, &i)
		|| !ft_find_nbr(line_rest, &i, &nbr3))
		return (0);
	while (line_rest[i])
	{
		if (line_rest[i] != ' ')
		{
			print_fd(2, "Error\nInvalid Color\n");
			return (0);
		}
	}
	*set = nbr1 << 24 | nbr2 << 16 | nbr3 << 8 | 225;
	return (1);
}

int	fill_i_3(t_map *ret, int nbr, char *line_rest, int *color_change)
{
	int	*set;
	int	i;

	if (color_change == 3
		|| (nbr == 1 && color_change == 1) || (nbr == 2 && color_change == 2))
		return (0);
	i = 0;
	while (line_rest[i] == ' ')
		i++;
	if (nbr == 1)
		set = &(ret->floor);
	else
		set = &(ret->ceiling);
	if (ft_convert_to_color(line_rest + i, set) == 0)
		return (0);
	return (1);
}

int	fill_i(t_map *ret, char *line, int *color_change)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (fill_i_2(&(ret->no), line + i + 3));
	if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (fill_i_2(&(ret->so), line + i + 3));
	if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		return (fill_i_2(&(ret->we), line + i + 3));
	if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		return (fill_i_2(&(ret->ea), line + i + 3));
	if (line[i] == 'F' && line[i + 1] == ' ')
		return (fill_i_3(ret, 1, line + i + 2, color_change));
	if (line[i] == 'C' && line[i + 1] == ' ')
		return (fill_i_3(ret, 2, line + i + 2, color_change));
	return (print_fd(2, "Error\nInvalid infors"), 0);
}

//color_change
//0 -> notyet
//1 -> floor changed
//2 -> ceiling changed
//3 -> floor && ceiling changed
////must free ret in this func
t_map	*ft_break_non_map(t_map *ret, char **non_map)
{
	int	i;
	int	color_change;

	i = 0;
	color_change = 0;
	while (i < 5)
	{
		if (non_map[i] == 0)
			return (print_fd(2, "Sth wrong in ft_break_non_map"), NULL);
		if (fill_i(ret, non_map[i], &color_change) == 0)
			return (free_t_map(ret), NULL);
		i++;
	}
	if (non_map[i] != NULL)
		return (free_t_map(ret), free_t_map(ret),
			print_fd(2, "Sth wrong in ft_break_non_map"), NULL);
	return (ret);
}

t_map	*break_non_map(char **file_content, int *i)
{
	char	**non_map;
	t_map	*ret;

	non_map = before_map_good(file_content, &i);
	if (non_map == NULL)
		return (NULL);
	ret = (t_map *)malloc(1 * sizeof(t_map));
	if (ret == NULL)
		return (perror("Malloc"), free(non_map), NULL);
	ret->no = 0;
	ret->so = 0;
	ret->ea = 0;
	ret->we = 0;
	ret->map = 0;
	ret = ft_break_non_map(ret, non_map);
	free_split(non_map);
	return (ret);
}

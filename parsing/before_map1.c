/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_map1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:12:23 by qdo               #+#    #+#             */
/*   Updated: 2024/06/10 10:37:37 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	if (to_set || !line_rest[i])
		return (print_fd(2, "Error\nInvalid infos"), NULL);
	to_set = ft_trim_whitespace(line_rest[i]);
	if (to_set == 0)
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
////must free ret in this func, not free non_map
t_map	*ft_break_non_map(t_map *ret, char **non_map)
{
	int	i;
	int	color_change;

	i = 0;
	color_change = 0;
	while (i < 5)
	{
		if (non_map[i] == 0)
			return (print_fd(2, "Sth wrong (in code) in ft_break_non_map"),
				NULL);
		if (fill_i(ret, non_map[i], &color_change) == 0)
			return (free_t_map(ret), NULL);
		i++;
	}
	if (non_map[i] != NULL)
		return (free_t_map(ret),
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

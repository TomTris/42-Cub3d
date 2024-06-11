/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_map1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:12:23 by qdo               #+#    #+#             */
/*   Updated: 2024/06/11 17:59:22 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	map_n_player(char **file_content, int i, char a, int j)
{
	int		player_cnt;

	player_cnt = 0;
	while (file_content[i])
	{
		if (is_empty_line(file_content[i]) == 1)
			return (print_fd(2, "Error\nEmpty line in map\n"), 0);
		j = 0;
		while (file_content[i][j])
		{
			a = file_content[i][j];
			if (a != 'N' && a != 'S' && a != 'W' && a != 'E'
				&& a != ' ' && a != '1' && a != '0')
				return (print_fd(2, "Error\nInvalid character in map\n"), 0);
			if (a == 'N' || a == 'S' || a == 'W' || a == 'E')
				player_cnt++;
			if (player_cnt > 1)
				return (print_fd(2, "Error\nToo many player\n"), 0);
			j++;
		}
		i++;
	}
	if (player_cnt == 0)
		return (print_fd(2, "Error\nNo starting view point\n"), 0);
	return (1);
}

char	**before_map_good(char **file_content, int *i, int cnt_line_not_map)
{
	char	**ret;

	ret = smerge(0, 0);
	if (ret == 0)
		return (NULL);
	while (file_content[*i] && ft_is_part_of_map(file_content[*i]) == 0)
	{
		if (is_empty_line(file_content[*i]) == 0)
		{
			ret = smerge(ret, file_content[*i]);
			if (ret == 0)
				return (NULL);
			cnt_line_not_map++;
		}
		if (cnt_line_not_map > 6)
			return (print_fd(2, "Error\nToo many/ Wrong infos\n"),
				free_split(ret), NULL);
		(*i)++;
	}
	if (!map_n_player(file_content, *i, 0, 0))
		return (free_split(ret), NULL);
	if (cnt_line_not_map < 6)
		return (print_fd(2, "Error\nToo little infos\n"),
			free_split(ret), NULL);
	return (ret);
}

int	fill_i(t_map *ret, char *line, int *color_change)
{
	int		i;

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
	return (print_fd(2, "Error\nInvalid infors1\n"), 0);
}

t_map	*ft_break_non_map(t_map *ret, char **non_map)
{
	int	i;
	int	color_change;

	color_change = 0;
	i = 0;
	while (i < 6)
	{
		if (non_map[i] == 0)
			return (print_fd(2, "Sth wrong (in code) in ft_break_non_map\n"),
				NULL);
		if (fill_i(ret, non_map[i], &color_change) == 0)
			return (free_t_map(ret), NULL);
		i++;
	}
	if (non_map[i] != NULL)
		return (free_t_map(ret),
			print_fd(2, "Sth wrong in ft_break_non_map\n"), NULL);
	return (ret);
}

t_map	*break_non_map(char **file_content, int *i)
{
	char	**non_map;
	t_map	*ret;

	non_map = before_map_good(file_content, i, 0);
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

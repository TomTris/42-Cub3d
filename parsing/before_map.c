/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:12:23 by qdo               #+#    #+#             */
/*   Updated: 2024/06/09 18:25:27 by qdo              ###   ########.fr       */
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

t_map	*ft_break_non_map(t_map *ret, char** non_map)
{
	
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
	ret->map = 0;
	ret = ft_break_non_map(ret, non_map);
	if (ret == 0)
		return (NULL);
	ret->map 
}

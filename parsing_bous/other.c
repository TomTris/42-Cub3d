/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:00:52 by qdo               #+#    #+#             */
/*   Updated: 2024/06/14 15:58:39 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**smerge(char **dest, char *src)
{
	char	**ret;
	int		i;

	if (dest == 0)
	{
		ret = (char **)malloc(1 * sizeof(char *));
		if (ret == 0)
			return (perror("Malloc faile1d\n"), NULL);
		ret[0] = NULL;
		return (ret);
	}
	i = 0;
	while (dest[i] != 0)
		i++;
	ret = (char **)malloc((i + 2) * sizeof(char *));
	if (ret == 0)
		return (perror("Malloc failed\n"), free_split(dest), NULL);
	ret[i + 1] = NULL;
	ret[i] = ft_strdup(src);
	if (ret[i] == 0)
		return (free_split(dest), free(ret), NULL);
	while (--i >= 0)
		ret[i] = dest[i];
	free(dest);
	return (ret);
}

int	free_split(char **to_free2)
{
	int	i;

	if (to_free2 != 0)
	{
		i = -1;
		while (to_free2[++i])
			free(to_free2[i]);
		free(to_free2);
	}
	return (0);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (ft_isempty(line[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

void	free_t_map(t_map *a)
{
	if (a)
	{
		free(a->no);
		free(a->so);
		free(a->ea);
		free(a->we);
		free_split(a->map);
	}
	free(a);
}

//return 0 -> not the part of map
//return 1 -> part of the map
//only space or '1' or '0' or 'N' 'W' 'S' 'E' and at least 1 '0' or '1'
int	ft_is_part_of_map(char *lne)
{
	int		i;
	int		cnt;
	int		player_cnt;

	cnt = 0;
	player_cnt = 0;
	i = -1;
	while (lne[++i])
	{
		if (lne[i] == ' ' || lne[i] == '1' || lne[i] == '0' || lne[i] == 'N'
			|| lne[i] == 'W' || lne[i] == 'S' || lne[i] == 'E' || lne[i] == 'd')
		{
			if (lne[i] == '0' || lne[i] == '1' || lne[i] == 'd')
				cnt++;
			else if (lne[i] != ' ')
				player_cnt++;
			if (player_cnt > 1)
				return (0);
		}
		else
			return (0);
	}
	if (cnt >= 1)
		return (1);
	return (0);
}

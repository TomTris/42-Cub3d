/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:00:52 by qdo               #+#    #+#             */
/*   Updated: 2024/06/10 10:35:54 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**smerge(char **dest, char *src)
{
	char	**ret;
	int		i;

	if (dest == 0)
	{
		dest = (char **)malloc(1 * sizeof(char *));
		if (dest == 0)
			return (perror("Malloc faile1d\n"), NULL);
		dest[0] = NULL;
		return (dest);
	}
	i = 0;
	while (dest[i] != 0)
		i++;
	ret = (char **)malloc((i + 2) * sizeof(char *));
	if (ret == 0)
		return (perror("Malloc faile2d\n"), free_split(dest), NULL);
	ret[i] = ft_strdup(src);
	if (ret[i] == 0)
		return (perror("ft_strdup"), free_split(dest), free(ret), NULL);
	ret[i + 1] = NULL;
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
	return (0);
}

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

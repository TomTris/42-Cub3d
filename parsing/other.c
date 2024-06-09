/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:00:52 by qdo               #+#    #+#             */
/*   Updated: 2024/06/09 18:50:45 by qdo              ###   ########.fr       */
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

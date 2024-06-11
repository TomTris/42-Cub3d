/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:02:47 by qdo               #+#    #+#             */
/*   Updated: 2024/06/11 19:33:16 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**ft_create_ret_map(int m, int len)
{
	int		n;
	int		o;
	char	**ret;

	ret = (char **)malloc((m + 1) * sizeof(char *));
	if (ret == 0)
		return (perror("Malloc"), NULL);
	n = 0;
	while (n < m)
	{
		ret[n] = (char *)malloc((len + 1) * sizeof(char));
		if (ret[n] == NULL)
			return (perror("Malloc"), free_split(ret), NULL);
		o = 0;
		while (o < len)
			ret[n][o++] = '2';
		ret[n][o] = 0;
		n++;
	}
	ret[n] = NULL;
	return (ret);
}

void	ft_fill_map(char **ret, int i, char **file_content)
{
	int	a;
	int	b;

	a = 1;
	while (ret[a] && file_content[i])
	{
		b = -1;
		while (file_content[i][++b])
		{
			if (file_content[i][b] == ' ' || file_content[i][b] == '0')
				ret[a][b + 1] = '0';
			else
				ret[a][b + 1] = file_content[i][b];
		}
		a++;
		i++;
	}
	if (ret[a + 1] != NULL || file_content[i] != NULL)
		print_fd(2, "Error\nft_fill_map\n");
}

//1 -> 1
//0 or ' ' -> 0
// nichts -> 2.
// 2 - should not touched.
char	**map_gen(char **file_content, int i, t_map *ret)
{
	int		i2;
	int		len_est;
	int		len_temp;
	char	**map;

	i2 = i;
	len_est = ft_strlen(file_content[i]);
	while (file_content[++i])
	{
		len_temp = ft_strlen(file_content[i]);
		if (len_est < len_temp)
			len_est = len_temp;
	}
	if (i - 2 <= i2)
		return (print_fd(2, "Error\nInvalid map2\n"), NULL);
	map = ft_create_ret_map(i - i2 + 2, len_est + 2);
	if (map == 0)
		return (NULL);
	ft_fill_map(map, i2, file_content);
	if (!is_surrounded(map, ret))
		return (free_split(map), NULL);
	return (map);
}

// assert(file_content);
// #include <assert.h>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_po.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:59:59 by qdo               #+#    #+#             */
/*   Updated: 2024/06/14 17:14:28 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_po	*new_t_po(void)
{
	t_po	*ret;

	ret = (t_po *)malloc(1 * sizeof(t_po));
	if (ret == 0)
		return (perror("Error\nMalloc Failed"), NULL);
	ret->next = 0;
	return (ret);
}

void	free_t_po_list(t_po **po)
{
	t_po	*temp;

	temp = po[0];
	while (temp != 0)
	{
		free(temp);
		po[0] = po[0]->next;
		temp = po[0];
	}
}

int	t_po_add(t_po **ret, int i, int j)
{
	t_po	*temp;

	if (*ret == 0)
	{
		ret[0] = new_t_po();
		if (ret[0] == 0)
			return (0);
		ret[0]->x = i;
		ret[0]->y = j;
		return (1);
	}
	temp = *ret;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new_t_po();
	if (temp->next == 0)
		return (0);
	temp->next->x = i;
	temp->next->y = j;
	return (1);
}

int	valid_door(char **map, int i, int j)
{
	if (map[i][j + 1] == '2' || map[i][j - 1] == '2'
		|| map[i + 1][j] == '2' || map[i - 1][j] == '2')
		return (0);
	if (map[i][j + 1] == '1' && map[i][j - 1] == '1'
		&& map[i + 1][j] == '1' && map[i - 1][j] == '1')
		return (0);
	if (map[i][j + 1] == '1' && map[i][j - 1] == '1')
		return (1);
	if (map[i + 1][j] == '1' && map[i - 1][j] == '1')
		return (1);
	return (0);
}

t_po	*ft_find_door(char **map, int *check)
{
	int		i;
	int		j;
	t_po	*ret;

	ret = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'd')
			{
				if (valid_door(map, i, j) == 0)
					return (write(2, "Error\nInvalid door in map\n", 26),
						free_t_po_list(&ret), NULL);
				if (t_po_add(&ret, i, j) == 0)
					return (free_t_po_list(&ret), NULL);
				map[i][j] = '0';
			}
		}
	}
	return (*check = 1, ret);
}

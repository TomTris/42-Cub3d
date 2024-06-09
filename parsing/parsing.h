/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:03:55 by qdo               #+#    #+#             */
/*   Updated: 2024/06/09 17:57:27 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"

typedef struct s_map
{
	char	**map;
	int		nor;
	int		sou;
	int		wes;
	int		ost;
	int		floor;
	int		ceiling
}	t_map;

char		**ft_file_create(int ac, char **av, char *file_name);
int			is_empty_line(char *line);
int			free_split(char **to_free2);
char		**smerge(char **dest, char *src);

#endif

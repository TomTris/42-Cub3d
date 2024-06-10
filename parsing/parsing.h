/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:03:55 by qdo               #+#    #+#             */
/*   Updated: 2024/06/10 11:52:01 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"

typedef struct s_map
{
	char				**map;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	unsigned int		floor;
	unsigned int		ceiling;
}	t_map;

//ft_file_create
char		**ft_file_create(int ac, char **av, char *file_name);
char		**ft_file_create2(char **ret, int fd);
char		**ft_file_create3(char **ret);
int			ft_check_args(int ac, char **av);

//before_map1.c
char		**before_map_good(char **file_content, int *i);
int			fill_i_2(char **to_set, char *line_rest);
int			fill_i(t_map *ret, char *line, int *color_change);
t_map		*ft_break_non_map(t_map *ret, char **non_map);
t_map		*break_non_map(char **file_content, int *i);

//before_map2.c
int			ft_convert_to_color_pre_check(char *line_rest);
int			ft_find_nbr(char *line_rest, int *i, unsigned int *set);
int			ft_skip_comma(char *line_rest, int *i);
int			ft_convert_to_color(char *line_rest, unsigned int *set);
int			fill_i_3(t_map *ret, int nbr, char *line_rest, int *color_change);

//other.c
int			is_empty_line(char *line);
int			free_split(char **to_free2);
char		**smerge(char **dest, char *src);
void		free_t_map(t_map *a);
int			ft_is_part_of_map(char *line);
#endif

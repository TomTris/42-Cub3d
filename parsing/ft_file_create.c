/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:00:08 by qdo               #+#    #+#             */
/*   Updated: 2024/06/11 13:02:33 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_check_args(int ac, char **av)
{
	int	len;

	if (ac != 2)
	{
		print_fd(2,
			"Error\nName of the file for map designing purpose needed!\n");
		return (0);
	}
	len = ft_strlen(av[1]);
	if (len < 4 || av[1][len - 1] != 'b' || av[1][len -2] != 'u'
		|| av[1][len - 3] != 'c' || av[1][len - 4] != '.')
	{
		print_fd(2, "Error\nWrong name\n");
		return (0);
	}
	return (1);
}

char	**ft_file_create3(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
		i++;
	// printf("files has %d or %d lines\n", i, i + 1);
	if (i < 9)
		return (print_fd(2, "Error\nToo little infos\n"),
			free_split(ret), NULL);
	return (ret);
}

char	**ft_file_create2(char **ret, int fd)
{
	int		j;
	char	*temp;

	temp = get_next_line(fd);
	while (temp != NULL)
	{
		j = 0;
		while (temp[j])
			j++;
		if (j != 0 && temp[j - 1] == '\n')
			temp[j - 1] = 0;
		ret = smerge(ret, temp);
		free(temp);
		if (ret == 0)
			return (NULL);
		temp = get_next_line(fd);
	}
	return (ft_file_create3(ret));
}

int	new_line_at_the_end(char *file_name)
{
	char	buf[1000];
	int		cnt;
	int		new_line;
	int		fd;

	new_line = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (perror("Error\nopen"), 1);
	while (1)
	{
		cnt = read(fd, buf, 998);
		if (cnt == -1)
			return (perror("Error\nread"), close(fd), 1);
		if (cnt == 0)
			break ;
		if (buf[cnt] == '\n')
			new_line = 1;
	}
	if (close(fd) == -1)
		return (perror("Error\nclose"), 1);
	return (new_line);
}

char	**ft_file_create(int ac, char **av)
{
	char			**ret;
	int				fd;

	if (ft_check_args(ac, av) == 0)
		return (NULL);
	if (new_line_at_the_end(av[1]) == 1)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error\nOpen"), NULL);
	ret = smerge(0, 0);
	if (ret == 0)
		return (NULL);
	ret = ft_file_create2(ret, fd);
	get_next_line(-1);
	if (close(fd) == -1)
		return (perror("Error\nclose"), free_split(ret), NULL);
// int i = 0;
// while (ret[i])
// 	printf("%s\n", ret[i++]);
	return (ret);
}

// void	ft_set_last_newline_to_0(char **ret)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	i = 0;
// 	while (ret[i])
// 		i++;
// 	while (ret[i][j])
// 		j++;
// 	if (j != 0)
// 		printf("This is last line of file");
// 	else if (ret[i][j - 1] != '\n')
// 			printf("This is last line of file");
// 	else
// 		ret[i][j - 1] = 0;
// }
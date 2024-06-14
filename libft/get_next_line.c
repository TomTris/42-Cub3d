/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:55:32 by qdo               #+#    #+#             */
/*   Updated: 2024/06/10 11:00:09 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char **str1, char **str2)
{
	if (str1 != 0)
	{
		free(*str1);
		*str1 = 0;
	}
	if (str2 != 0)
	{
		free(*str2);
		*str2 = 0;
	}
	return (0);
}

char	*sndup(char *str, int n)
{
	int		i;
	char	*ret;

	if (str == 0)
		return (0);
	ret = (char *)malloc(n + 1);
	if (ret == 0)
		return (perror("Malloc"), NULL);
	i = -1;
	while (++i < n)
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}

static char	*ft_read(char *lstr, int fd)
{
	char	*temp;
	char	*buf;
	int		bytes;

	buf = (char *)malloc((BUFFER_SIZE + 1));
	if (buf == 0)
		return (perror("Malloc"), ft_free(&lstr, 0));
	bytes = 1;
	while (ft_strchr(lstr, '\n') == NULL && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_free(&lstr, &buf));
		buf[bytes] = 0;
		temp = lstr;
		lstr = ft_strjoin(lstr, buf);
		if (lstr == 0)
			return (ft_free(&temp, &buf));
		free(temp);
	}
	free(buf);
	return (lstr);
}

static char	*ft_before_after_nl(char *lstr, int i, int check,
		int check_before_after)
{
	char	*temp;

	if (check_before_after == -1)
	{
		while (lstr[i])
		{
			if (lstr[i++] == '\n')
			{
				check = 1;
				break ;
			}
		}
		if (check == 0)
			return (ft_strdup(lstr));
		return (sndup(lstr, i));
	}
	while (lstr[i])
		if (lstr[i++] == '\n')
			break ;
	temp = ft_strdup(lstr + i);
	if (temp == 0)
		return (ft_free(&lstr, 0));
	free(lstr);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*lstr = 0;
	char		*ret;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (free(lstr), lstr = 0, NULL);
	if (lstr == 0)
	{
		lstr = (char *)malloc(1);
		if (lstr == 0)
			return (0);
		lstr[0] = 0;
	}
	lstr = ft_read(lstr, fd);
	if (lstr == 0 || lstr[0] == 0)
		return (ft_free(&lstr, 0));
	ret = ft_before_after_nl(lstr, 0, 0, -1);
	if (ret == 0)
		return (ft_free(&lstr, 0));
	lstr = ft_before_after_nl(lstr, 0, 0, 1);
	if (lstr == 0)
		return (ft_free(&ret, 0));
	if (*lstr == 0)
		ft_free(&lstr, 0);
	return (ret);
}

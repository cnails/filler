/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:40:53 by cnails            #+#    #+#             */
/*   Updated: 2019/10/11 13:39:29 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ret_word(char **str, int fd)
{
	int		a;
	char	*s;

	a = 0;
	while (str[fd][a] != '\n' && str[fd][a])
		a++;
	if (!(s = (char *)malloc(sizeof(*s) * (a + 1))))
		return (NULL);
	a = 0;
	while (str[fd][a] != '\n')
	{
		s[a] = str[fd][a];
		a++;
	}
	s[a] = '\0';
	return (s);
}

int		get_n_alpha(char **str, int fd)
{
	int i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i])
		i++;
	return (i);
}

int		get_line(char **str, char **line, int fd)
{
	char	*tmp;
	int		i;

	i = get_n_alpha(str, fd);
	if (str[fd][i] == '\n')
	{
		*line = ret_word(str, fd);
		tmp = ft_strdup(&str[fd][i + 1]);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			a;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	static char	*str[11000];

	if (fd < 0 || !line)
		return (-1);
	while ((a = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[a] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(0);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (a < 0)
		return (-1);
	if (a == 0 && (!str[fd] || str[fd][0] == '\0'))
		return (0);
	return (get_line(str, line, fd));
}

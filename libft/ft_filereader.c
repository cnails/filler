/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filereader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:19:02 by cnails            #+#    #+#             */
/*   Updated: 2019/09/20 13:20:41 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_filereader(char *a)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	fd = open(a, O_RDONLY | S_IRUSR);
	if (fd == -1)
	{
		ft_putstr("File name missing.\n");
		return ;
	}
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	ft_putstr(buf);
	if (close(fd) == -1)
	{
		ft_putstr("close error.\n");
		return ;
	}
}

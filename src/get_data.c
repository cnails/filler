/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:37:20 by cnails            #+#    #+#             */
/*   Updated: 2020/06/28 11:59:43 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			get_player(t_data *data)
{
	char *line;

	get_next_line(0, &line);
	data->enemy = (line[10] == '1') ? 'x' : 'o';
	free(line);
	return (data->enemy);
}

void		get_size_map(t_data *data, char *line)
{
	int i;

	i = 8;
	data->map_size_x = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	data->map_size_y = ft_atoi(line + i);
}

static void	dop_func(t_data *data, char **line)
{
	get_size_map(data, *line);
	free(*line);
	get_next_line(data->fd, line);
	ft_strdel(line);
	get_map(data);
}

int			get_info(t_data *data)
{
	char *line;

	while (get_next_line(data->fd, &line) > 0)
	{
		if (line && !ft_strncmp(line, "Plateau", 6))
		{
			dop_func(data, &line);
		}
		if (line && !ft_strncmp(line, "Piece", 5))
		{
			get_size_tetr(data, line);
			get_tetr(data);
			calc_map(data);
			if (!calc_step(data))
			{
				free(line);
				return (0);
			}
			free(line);
			break ;
		}
		free(line);
	}
	return (1);
}

int			free_data(t_data *data)
{
	int f_i;

	f_i = 0;
	while (f_i < (data->size_x))
	{
		free(data->tetr.points[f_i]);
		f_i++;
	}
	free(data->tetr.points);
	f_i = 0;
	while (f_i < (data->map_size_x))
	{
		free(data->map->info[f_i]);
		f_i++;
	}
	free(data->map->info);
	free(data->map);
	free(data);
	return (0);
}

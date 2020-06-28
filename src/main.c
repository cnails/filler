/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:05:30 by cnails            #+#    #+#             */
/*   Updated: 2020/06/28 10:47:50 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		get_tetr(t_data *data)
{
	char	*line;

	data->tetr.points = (int **)ft_memalloc(sizeof(int *) * (data->size_x + 1));
	data->vars.x = 0;
	while (data->vars.x < data->size_x)
	{
		data->tetr.points[data->vars.x] = (int *)ft_memalloc(sizeof(int) *
			(data->size_y + 1));
		data->vars.y = 0;
		get_next_line(data->fd, &line);
		while (data->vars.y < data->size_y)
		{
			data->tetr.points[data->vars.x][data->vars.y] =
								line[data->vars.y] == '*' ? 1 : 0;
			data->vars.y++;
		}
		ft_strdel(&line);
		data->vars.x++;
	}
}

void		get_size_tetr(t_data *data, char *line)
{
	int i;

	i = 6;
	data->size_x = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	data->size_y = ft_atoi(line + i);
}

void		get_map(t_data *data)
{
	char	*line;
	t_vars	var;
	int		x;

	var.x = 0;
	data->map->info = (int **)ft_memalloc(sizeof(int *) * (data->map_size_x));
	while (var.x < (data->map_size_x))
	{
		var.y = 4;
		data->map->info[var.x] = (int *)ft_memalloc(sizeof(int) *
											(data->map_size_y));
		get_next_line(data->fd, &line);
		while (line[var.y])
		{
			if (line[var.y] != '.')
				data->map->info[var.x][var.y - 4] = line[var.y] == data->enemy
					|| line[var.y] == data->enemy - 32 ? -2 : -1;
			var.y++;
		}
		ft_strdel(&line);
		var.x++;
	}
}

static void	init_struct(t_data *data)
{
	data->map_size_x = 0;
	data->map_size_y = 0;
	data->size_x = 0;
	data->size_y = 0;
	data->vars.x = 0;
	data->vars.y = 0;
	data->map = (t_map *)ft_memalloc(sizeof(t_map));
}

int			main(void)
{
	t_data	*data;
	int		enemy;

	enemy = 0;
	while (1)
	{
		data = (t_data *)ft_memalloc(sizeof(t_data));
		data->fd = 0;
		if (!enemy)
			enemy = get_player(data);
		else
			data->enemy = enemy;
		init_struct(data);
		if (!get_info(data))
		{
			free_data(data);
			exit(1);
		}
		free_data(data);
	}
	return (0);
}

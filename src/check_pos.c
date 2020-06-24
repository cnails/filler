/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 15:40:10 by cnails            #+#    #+#             */
/*   Updated: 2020/03/17 17:17:12 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		check_pos(t_data *data, int x, int y)
{
	t_vars	coord;
	int		i;

	coord.x = 0;
	i = 0;
	if ((x + data->size_x) >= data->map_size_x || (y + data->size_y)
												>= data->map_size_y)
		return (0);
	while (coord.x < data->size_x)
	{
		coord.y = 0;
		while (coord.y < data->size_y)
		{
			if (data->map->info[x + coord.x][y + coord.y] == -1
							&& data->tetr.points[coord.x][coord.y] == 1)
				i++;
			if (data->map->info[x + coord.x][y + coord.y] == -2 || i > 1)
				return (0);
			coord.y++;
		}
		coord.x++;
	}
	if (i == 1)
		return (1);
	return (0);
}

static int		calc_sum(t_data *data, int x, int y)
{
	t_vars	coord;
	int		sum;
	int		tmp_y;

	sum = 0;
	coord.x = 0;
	tmp_y = y;
	while (coord.x < data->size_x)
	{
		coord.y = 0;
		y = tmp_y;
		while (coord.y < data->size_y)
		{
			if (data->tetr.points[coord.x][coord.y] == 1)
				sum += data->map->info[x][y];
			coord.y++;
			y++;
		}
		coord.x++;
		x++;
	}
	return (sum);
}

void			print_res(int a, int b)
{
	ft_putnbr(a);
	ft_putchar(' ');
	ft_putnbr(b);
	ft_putchar('\n');
}

static int		calc_step_after_init(t_data *data, t_vars map,
											t_vars var, t_vars sum)
{
	while (map.x < (data->map_size_x))
	{
		map.y = 0;
		while (map.y < (data->map_size_y))
		{
			if (check_pos(data, map.x, map.y))
				sum.x = calc_sum(data, map.x, map.y);
			if (sum.x < sum.y)
			{
				var.x = map.x;
				var.y = map.y;
				sum.y = sum.x;
			}
			map.y++;
		}
		map.x++;
	}
	if (var.x == -1 && var.y == -1)
		return (0);
	print_res(var.x, var.y);
	return (1);
}

int				calc_step(t_data *data)
{
	t_vars	map;
	t_vars	var;
	t_vars	sum;

	map.x = 0;
	var.x = -1;
	var.y = -1;
	sum.x = 10000;
	sum.y = 9999;
	return (calc_step_after_init(data, map, var, sum));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 14:52:49 by cnails            #+#    #+#             */
/*   Updated: 2020/03/17 17:17:05 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		ft_abs(int a)
{
	return (a < 0 ? -a : a);
}

static int		ret_dist(t_data *data, int i, int j)
{
	int		x;
	int		y;
	int		dist;
	int		dist_r;

	x = 0;
	dist_r = 9999;
	while (x < data->map_size_x)
	{
		y = 0;
		while (y < data->map_size_y)
		{
			if (data->map->info[x][y] == -2)
			{
				dist = ft_abs(x - i) + ft_abs(y - j);
				if (dist < dist_r)
					dist_r = dist;
			}
			y++;
		}
		x++;
	}
	return (dist_r);
}

void			calc_map(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (x < (data->map_size_x))
	{
		y = 0;
		while (y < data->map_size_y)
		{
			if (data->map->info[x][y] == 0)
				data->map->info[x][y] = ret_dist(data, x, y);
			y++;
		}
		x++;
	}
}

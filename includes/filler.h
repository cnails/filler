/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:16:12 by cnails            #+#    #+#             */
/*   Updated: 2020/03/17 17:17:38 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"

typedef struct 	s_vars
{
	int			x;
	int			y;
}				t_vars;

typedef struct	s_map
{
	int			**info;
}				t_map;


typedef struct	s_tetr
{
	int			**points;
}				t_tetr;


typedef struct	s_data
{
	t_vars		vars;
	t_tetr		tetr;
	t_map		*map;
	int			fd;
	int			enemy;
	int			debug_fd;
	int			n_player;
	int			map_size_x;
	int			map_size_y;
	int			size_x;
	int			size_y;
}				t_data;

void			calc_map(t_data *data);
int				calc_step(t_data *data);
int				free_data(t_data *data);
int				get_info(t_data *data);
void			get_size_map(t_data *data, char *line);
void			get_size_tetr(t_data *data, char *line);
void			get_tetr(t_data *data);
void			get_map(t_data *data);
int				get_player(t_data *data);

#endif

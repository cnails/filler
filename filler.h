/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:16:12 by cnails            #+#    #+#             */
/*   Updated: 2020/03/10 20:08:15 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct 	s_vars
{
	int			x;
	int			y;
}				t_vars;

typedef struct	s_tetr
{
	char		**points;
}				t_tetr;


typedef struct	s_map
{
	t_vars		vars;
	t_tetr		tetr;
	int			debug_fd;
	int			n_player;
	int			map_size_x;
	int			map_size_y;
	int			size_x;
	int			size_y;
}				t_map;

#endif

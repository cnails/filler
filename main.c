/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:05:30 by cnails            #+#    #+#             */
/*   Updated: 2020/03/10 20:09:13 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_tetr(t_map *map)
{
	char *line;
	int		x = 0;
	int		y = 0;

	ft_printf("%n%d\n", map->debug_fd, map->size_x);
	ft_printf("%n%d\n", map->debug_fd, map->size_y);
	// ft_printf("%n%d\n", map->debug_fd, 1);
	map->tetr.points = (char **)malloc(sizeof(int *) * (map->size_x + 2));
	// ft_printf("%n%d\n", map->debug_fd, 2);
	// map->vars.y = 0;
	x = 0;
	while (x < (map->size_x))
	{
		// ft_printf("%n%d\n", map->debug_fd, 3);
		map->tetr.points[y] = (char *)malloc(sizeof(int) * (map->size_y + 1));
		// ft_printf("%n%d\n", map->debug_fd, 5);
		// map->vars.x = 0;
		y = 0;
		get_next_line(0, &line);
		ft_printf("%n%s\n", map->debug_fd, line);
		while (y < (map->size_y))
		{
			/* if (*/// > 0 && line)
			// {
				
				// map->tetr.points[map->vars.y][map->vars.x] = 0;
				ft_printf("%nvars.x = %d\n", map->debug_fd, x);
				// ft_printf("%nvars.x = %d\n", map->debug_fd, map->vars.x);
				ft_printf("%nvars.y = %d\n", map->debug_fd, y);
				// ft_printf("%n%s\n", map->debug_fd, line);
				// ft_printf("%n%d\n", map->debug_fd, 1);
				// line[y];
				map->tetr.points[x][y] = line[y] == '*' ? '1' : '0';
				// ft_printf("%nvars.y = %d\n", map->debug_fd, map->vars.y);
			// }
			y++;
		}
		free(line);
		// map->vars.y++;
		x++;
	}
}

static void	get_size_map(t_map *map, char *line)
{
	int i;

	i = 8;
	map->map_size_x = ft_atoi(line + i);
	// ft_printf("%nmap_size_x = %d\n", map->debug_fd, map->map_size_x);
	// while (line[i] != ' ')
		// i++;
	map->map_size_y = ft_atoi(line + i);
	// ft_printf("%nmap_size_y = %d\n", map->debug_fd, map->map_size_y);
}

static void	get_size_tetr(t_map *map, char *line)
{
	int i;

	i = 6;
	map->size_x = ft_atoi(line + i);
	// ft_printf("%nsize_x = %d\n", map->debug_fd, map->size_x);
	while (line[i] != ' ')
		i++;
	map->size_y = ft_atoi(line + i);
	// ft_printf("%nsize_y = %d\n", map->debug_fd, map->size_y);
}

static void	init_struct(t_map *map)
{
	map->n_player = 0;
	map->map_size_x = 0;
	map->map_size_y = 0;
	map->size_x = 0;
	map->size_y = 0;
}

int			main(void)
{
	// FILE 	*mf;
	t_map	*map;
	char	*line;
	int		fd;
	int		fd_1;

	map = (t_map *)malloc(sizeof(*map));
	init_struct(map);
	// fd = open("debug.log", O_WRONLY);
	// map->debug_fd = open("deb.log", O_WRONLY);
	// if (get_next_line(0, &line) > 0 && line && !ft_strncmp(line, "$$$ exec p", 9))
	// 	map->n_player = (line[10] == '1' ? 1 : 2);
	// // fprintf(mf, "%s\n", line);
	// ft_printf("%n%d\n", map->debug_fd, map->n_player);
	// ft_printf("%n%s\n", fd, line);
	// free(line);
	map->debug_fd = open("deb.log", O_WRONLY);
	while (1)
	{
	while (get_next_line(0, &line) > 0)
	{
		// fprintf(mf, "%s\n", line);
		// fprintf(mf, "\n");
		// if (!line)
		// 	continue;
		if (line && !ft_strncmp(line, "Plateau ", 8))
		{
			get_size_tetr(map, line);
			// free(line);
			
			// ft_printf("%n%d\n", fd, 5);
			// close(fd);
			// ft_printf("2 3\n");
			// get_next_line(0, &line);
			/*
			**	get_map() here
			*/
			while (get_next_line(0, &line) > 0 && ft_strncmp(line, "Piece ", 6))
				free(line);
			// ft_printf("%n%s\n", fd, line);
			// free(line);
			// exit(1);
		}
			// get_size_map(map, line);
			// continue;
		if (line && !ft_strncmp(line, "Piece ", 6))
		{
			// fd = open("deb.log", O_WRONLY);
			// ft_printf("%n%d\n", fd, 2);
			get_size_tetr(map, line);
			// int i = 2;
			// while (i--)
			// {
				// ft_putchar('2');
				// ft_putchar(' ');
				// ft_putchar('3');
				// ft_putchar('\n');
				get_tetr(map);
				// get_next_line(0, &line);
				// free(line);
				// get_next_line(0, &line);
				// free(line);
			// }
			// if (map->size_x == 2 && map->size_y == 1)
			// {
				// ft_printf("2 1\n");
				// exit(1);
			// }
			// else
			// {
				// ft_printf("%nhere\n", map->debug_fd);
				ft_printf("11 12\n");
				// close(fd);
				return (1);
				// close(map->debug_fd);
				// exit(1);
			// }
			// if (map->size_x == 24)
			// ft_printf("19 28\n");
			// else
				// ft_printf("2 0\n");
			// exit(1);
		}
		// ft_printf("%nhi\n", map->debug_fd);
		// ft_printf("%n%s\n", fd, line);
		// free(line);
		// return (0);
	}
	}
	// close(map->debug_fd);
	return (0);
}

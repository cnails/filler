/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:36:57 by cnails            #+#    #+#             */
/*   Updated: 2019/11/18 15:02:04 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	stat_for(int start, int sum, int end)
{
	static int	i;
	int			final;

	if (i == 0 && start > 0)
	{
		i = start;
		return (i);
	}
	if (i == end)
	{
		final = sum + i;
		i = 0;
		return (final);
	}
	if (i > end)
	{
		final = i;
		i = 0;
		return (final);
	}
	i += sum;
	return (i);
}

int			ft_for(int start, int sum, int end)
{
	int i;

	if (sum < 0)
		return (0);
	i = stat_for(start, sum, end);
	if (start == 0 && i <= end)
		return (i);
	if (i < end)
		return (i);
	return (0);
}

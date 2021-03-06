/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:38:51 by cnails            #+#    #+#             */
/*   Updated: 2019/09/06 21:49:43 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
				(c >= 'A' && c <= 'Z')))
		return (1);
	return (0);
}

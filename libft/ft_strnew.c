/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:05:00 by cnails            #+#    #+#             */
/*   Updated: 2019/09/13 14:43:56 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (size + 1)
	{
		if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		ft_memset(str, '\0', (size + 1));
		return (str);
	}
	return (NULL);
}

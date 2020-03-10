/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:50:48 by cnails            #+#    #+#             */
/*   Updated: 2019/09/16 13:04:22 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		a;
	char	*str;

	i = 0;
	a = 0;
	while (src[a])
		a++;
	if (!(str = (char *)malloc(sizeof(*str) * (a + 1))))
		return (NULL);
	while (i < a)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:06:29 by cnails            #+#    #+#             */
/*   Updated: 2019/09/16 12:30:19 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	k;
	int				i;

	i = 0;
	k = (unsigned char)c;
	a = (unsigned char *)s;
	while (n-- > 0)
	{
		if (a[i] == k)
			return (a + i);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:02:37 by cnails            #+#    #+#             */
/*   Updated: 2019/09/13 19:57:21 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (dest > src)
	{
		while (n-- > 0)
		{
			a[n] = b[n];
		}
	}
	if (dest < src)
	{
		while (n-- > 0)
			*a++ = *b++;
	}
	return (dest);
}

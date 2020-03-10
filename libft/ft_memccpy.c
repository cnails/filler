/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:50:19 by cnails            #+#    #+#             */
/*   Updated: 2019/09/05 18:46:34 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	l;

	l = (unsigned char)c;
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	while (n-- > 0)
	{
		*a = *b;
		a++;
		if (*b == l)
			return (a);
		b++;
	}
	return (NULL);
}

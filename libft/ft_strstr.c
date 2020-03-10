/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:53:33 by cnails            #+#    #+#             */
/*   Updated: 2019/09/10 21:58:40 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int a;

	i = 0;
	if (!(*str2))
		return ((char *)str1);
	while (str1[i])
	{
		a = 0;
		if (str2[a] == str1[i])
		{
			while (str2[a] == str1[i])
			{
				a++;
				if (!str2[a])
					return ((char *)&str1[i - a + 1]);
				i++;
			}
			i -= a;
		}
		i++;
	}
	return (NULL);
}

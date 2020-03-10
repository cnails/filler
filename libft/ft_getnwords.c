/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnwords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:57:02 by cnails            #+#    #+#             */
/*   Updated: 2019/09/10 22:27:25 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getnwords(char *str, int n)
{
	int		i;
	int		a;
	char	*s;

	i = 0;
	a = 0;
	if (!(s = (char *)malloc(sizeof(*s) * (ft_lennwords(str, n) + 1))))
		return (NULL);
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (n == 0)
		{
			while (str[i] != ' ' && str[i])
				s[a++] = str[i++];
		}
		n--;
		while (str[i] != ' ' && str[i])
			i++;
	}
	s[i] = '\0';
	return (s);
}

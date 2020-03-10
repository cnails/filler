/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:08:42 by cnails            #+#    #+#             */
/*   Updated: 2019/09/15 13:38:30 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(char *s)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			a = i;
		i++;
	}
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if ((a - i) < 0)
		return (0);
	return (a - i + 2);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i[4];

	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	if (s)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft_len((char *)s + 1)))))
			return (NULL);
		while (s[i[1]])
		{
			if (s[i[1]] != ' ' && s[i[1]] != '\t' && s[i[1]] != '\n')
				i[2] = i[1];
			i[1]++;
		}
		i[1] = 0;
		while (s[i[1]] == ' ' || s[i[1]] == '\t' || s[i[1]] == '\n')
			i[1]++;
		while (i[1] <= i[2])
			str[i[3]++] = s[i[1]++];
		str[i[3]] = '\0';
		return (str);
	}
	return (NULL);
}

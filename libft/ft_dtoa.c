/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:25:21 by dmetallo          #+#    #+#             */
/*   Updated: 2020/06/28 10:01:05 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(size_t n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

static char		*ft_qitoa(size_t n, int l)
{
	char	*str;
	int		flag;
	int		numb;

	flag = (n < 0) ? 1 : 0;
	numb = len(n) + flag + l - 1;
	if (!(str = (char *)ft_memalloc(sizeof(char) * (numb + 1))))
		return (NULL);
	if (flag)
	{
		str[0] = '-';
		n *= -1;
	}
	str[numb--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n % 10 > 4 && len(n) > l)
		n += 1;
	while (n || --l > 0)
	{
		str[numb--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static char		*post_dot(double f, char *str, int l)
{
	char *tmp;

	tmp = ft_qitoa((long int)f, l);
	str = ft_strjoin(str, tmp);
	free(tmp);
	return (str);
}

char			*ft_dtoa(double f, int n)
{
	char	*str;
	char	*tmp;
	int		l;

	l = n;
	n = (n < 0) ? 0 : n;
	str = ft_qitoa((size_t)f, 1);
	f -= (size_t)f;
	while (n-- > 0)
		f *= 10;
	if (n)
	{
		tmp = ft_strjoin(str, ".");
		free(str);
		str = post_dot(f, tmp, (f == 0) ? l : 1);
	}
	return (str);
}

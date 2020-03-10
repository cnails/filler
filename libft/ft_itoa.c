/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:04:45 by cnails            #+#    #+#             */
/*   Updated: 2020/01/29 15:22:17 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numlen(long long nb)
{
	if (nb < 0)
		return (1 + ft_numlen(nb * -1));
	if (nb >= 10)
		return (1 + ft_numlen(nb / 10));
	else
		return (1);
}

char			*ft_itoa(long long n)
{
	char	*str;
	int		i;

	i = ft_numlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (ft_numlen(n) + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == -2147483648)
	{
		str[1] = '2';
		n = -147483648;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

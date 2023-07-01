/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:10:23 by ntardy            #+#    #+#             */
/*   Updated: 2023/01/19 22:23:26 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static long int	ft_absoluteint(long n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

static void	ft_fillres(long long_n, char *res, int len_res)
{
	while (long_n >= 10)
	{
		res[len_res] = long_n % 10 + 48;
		long_n /= 10;
		len_res--;
	}
	res[len_res] = long_n + 48;
}

char	*ft_itoa(int n)
{
	long	long_n;
	char	*res;
	int		len_res;

	len_res = 0;
	long_n = ft_absoluteint((long)n);
	while (long_n >= 10)
	{
		len_res++;
		long_n /= 10;
	}
	len_res++;
	if (n < 0)
		len_res++;
	long_n = ft_absoluteint(n);
	res = malloc(sizeof(char) * len_res + 1);
	if (res == NULL)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	res[len_res] = '\0';
	ft_fillres(long_n, res, len_res - 1);
	return (res);
}

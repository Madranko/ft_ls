/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:07:36 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:08:18 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_c(size_t nb, int base)
{
	int		i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_uns(size_t nb, int base)
{
	char	*ret;
	int		size;
	char	tab[17];
	int		i;

	if (nb == 0)
	{
		ret = (char *)malloc(sizeof(char) * 2);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	ft_strcpy(tab, "0123456789abcdef");
	size = ft_count_c(nb, base);
	ret = malloc(size + 1);
	i = 1;
	while (nb != 0)
	{
		ret[size - i] = tab[nb % base];
		nb = nb / base;
		i++;
	}
	ret[size] = '\0';
	return (ret);
}

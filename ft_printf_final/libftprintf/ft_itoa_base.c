/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:06:37 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:07:28 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count_c(long long int nb, int base)
{
	int		i;

	i = 0;
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

static char		*ft_zero(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 2);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char			*ft_itoa_base(long long int nb, int base)
{
	char	*ret;
	int		size;
	char	tab[17];
	int		i;

	if (nb == 0)
		return (ft_zero());
	ft_strcpy(tab, "0123456789abcdef");
	size = ft_count_c(nb, base);
	ret = malloc(size + 1);
	i = 1;
	while (nb != 0)
	{
		if (nb < 0)
		{
			ret[0] = '-';
			ret[size - i] = tab[nb % base * (-1)];
		}
		else
			ret[size - i] = tab[nb % base];
		nb = nb / base;
		i++;
	}
	ret[size] = '\0';
	return (ret);
}

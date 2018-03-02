/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:08:30 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:41:26 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ft_bit_size(unsigned int b)
{
	int		i;

	i = 1;
	while ((b = b >> 1))
		i++;
	return (i);
}

static unsigned char	*ft_pf_res_mask1(unsigned int b)
{
	unsigned char	*res_char;
	unsigned int	mask1;

	mask1 = 0xC080;
	res_char = (unsigned char*)malloc(sizeof(unsigned char) * 3);
	res_char[0] = (b >> 6) | (mask1 >> 8);
	res_char[1] = ((b << 26) >> 26) | mask1;
	res_char[2] = '\0';
	return (res_char);
}

static unsigned char	*ft_pf_res_mask2(unsigned int b)
{
	unsigned char	*res_char;
	unsigned int	mask2;

	mask2 = 0xE08080;
	res_char = (unsigned char*)malloc(sizeof(unsigned char) * 4);
	res_char[0] = (b >> 12) | (mask2 >> 16);
	res_char[1] = (((b >> 6) << 26) >> 26) | ((mask2 << 16) >> 24);
	res_char[2] = ((b << 26) >> 26) | ((mask2 << 24) >> 24);
	res_char[3] = '\0';
	return (res_char);
}

static unsigned char	*ft_pf_res_mask3(unsigned int b)
{
	unsigned char	*res_char;
	unsigned int	mask3;

	mask3 = 0xF0808080;
	res_char = (unsigned char*)malloc(sizeof(unsigned char) * 5);
	res_char[0] = (b >> 18) | (mask3 >> 24);
	res_char[1] = (((b >> 12) << 26) >> 26) | ((mask3 << 8) >> 24);
	res_char[2] = (((b >> 6) << 26) >> 26) | ((mask3 << 16) >> 24);
	res_char[3] = ((b << 26) >> 26) | ((mask3 << 24) >> 24);
	res_char[4] = '\0';
	return (res_char);
}

unsigned char			*ft_make_unicode(unsigned int b)
{
	unsigned char	*res_char;
	int				len_bits;

	len_bits = ft_bit_size(b);
	if (len_bits <= 7 || MB_CUR_MAX < 2)
	{
		res_char = (unsigned char*)malloc(sizeof(unsigned char) * 2);
		res_char[0] = b;
		res_char[1] = '\0';
		return (res_char);
	}
	else if (len_bits <= 11 || MB_CUR_MAX < 3)
		return (ft_pf_res_mask1(b));
	else if (len_bits <= 16 || MB_CUR_MAX < 4)
		return (ft_pf_res_mask2(b));
	else
		return (ft_pf_res_mask3(b));
}

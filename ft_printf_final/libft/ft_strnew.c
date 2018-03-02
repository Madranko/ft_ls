/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:17:37 by mmotov            #+#    #+#             */
/*   Updated: 2017/11/09 12:33:43 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*tmp;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	tmp = str;
	while (size--)
		*tmp++ = 0;
	*tmp++ = 0;
	return (str);
}

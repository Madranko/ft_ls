/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:31:41 by mmotov            #+#    #+#             */
/*   Updated: 2017/11/16 15:08:46 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		lenght;

	i = 0;
	j = 0;
	lenght = ft_strlen(little);
	if (lenght == 0)
		return ((char *)big);
	while (i <= len - lenght && big[i] && len >= lenght)
	{
		while (big[i + j] == little[j])
		{
			if (j == lenght - 1)
				return ((char *)&big[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

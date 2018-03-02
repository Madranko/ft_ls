/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 09:48:48 by mmotov            #+#    #+#             */
/*   Updated: 2017/11/09 16:10:09 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = NULL;
	if (s)
	{
		i = 0;
		if (!(substr = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			substr[i] = s[start];
			i++;
			start++;
		}
		substr[i] = '\0';
	}
	return (substr);
}

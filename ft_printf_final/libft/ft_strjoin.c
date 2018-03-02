/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 10:26:35 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:55:37 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	int		i;
	size_t	j;

	newstring = NULL;
	if (s1 && s2)
	{
		i = -1;
		j = 0;
		if (!(newstring = (char *)malloc(sizeof(char) *
						(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1))))
			return (NULL);
		while (s1[++i] != '\0')
			newstring[i] = s1[i];
		while (s2[j] != '\0')
		{
			newstring[i] = s2[j];
			i++;
			j++;
		}
		newstring[i] = '\0';
	}
	return (newstring);
}

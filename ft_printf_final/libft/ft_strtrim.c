/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:06:03 by mmotov            #+#    #+#             */
/*   Updated: 2017/11/09 18:00:26 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;
	int		j;

	str = NULL;
	if (s)
	{
		i = 0;
		j = 0;
		len = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
			len--;
		if (len < i)
			len = i;
		if (!(str = (char *)malloc(sizeof(char) * (len - i + 2))))
			return (NULL);
		while (i <= len)
			str[j++] = s[i++];
		str[j] = '\0';
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:04:28 by mmotov            #+#    #+#             */
/*   Updated: 2017/11/14 14:58:45 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			counter++;
		while (s[i] != c && s[i])
			i++;
	}
	return (counter);
}

static int	count_char(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s != c && *s)
	{
		s++;
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;
	int		word;

	i = 0;
	if (s == NULL)
		return (NULL);
	word = count_word(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * count_word(s, c) + 1)))
		return (NULL);
	while (*s && i < word)
	{
		j = 0;
		while (*s == c && *s)
			s++;
		if (!(arr[i] = (char*)malloc(sizeof(char) * count_char(s, c) + 1)))
			return (NULL);
		while (*s != c && *s)
			arr[i][j++] = *s++;
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

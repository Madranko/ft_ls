/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:16:49 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:17:03 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_push_char(char *str, char symbol, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == symbol && i != 0 && str[0] == c)
		{
			str[0] = symbol;
			str[i] = c;
		}
		i++;
	}
	return (str);
}
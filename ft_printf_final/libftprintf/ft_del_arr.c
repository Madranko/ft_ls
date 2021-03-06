/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:01:17 by mmotov            #+#    #+#             */
/*   Updated: 2017/12/29 11:44:12 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_del_arr(unsigned char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		ft_memdel((void **)&(arr[i]));
		i++;
	}
	free(arr);
}

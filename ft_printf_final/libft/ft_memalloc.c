/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:36:26 by mmotov            #+#    #+#             */
/*   Updated: 2017/11/02 13:04:58 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if (!(tmp = (char *)malloc(sizeof(*tmp) * size)))
		return (NULL);
	ft_memset(tmp, 0, size);
	return (tmp);
}

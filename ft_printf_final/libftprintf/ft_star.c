/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 13:46:12 by mmotov            #+#    #+#             */
/*   Updated: 2018/03/02 13:46:29 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_star(t_form *form, va_list ap, int i)
{
	if (i == 1)
		form->width = va_arg(ap, unsigned int);
	if (i == 2)
		form->accur = va_arg(ap, int);
	return (i);
}

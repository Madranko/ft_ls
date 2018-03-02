/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:33:47 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 10:34:18 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_format	ft_init_format(void)
{
	t_format	format;

	format.link_len = 0;
	format.name_len = 0;
	format.size_len = 0;
	format.group_len = 0;
	return (format);
}

t_flags		ft_init_flags(void)
{
	t_flags	flags;

	flags.a = 0;
	flags.l = 0;
	flags.t = 0;
	flags.r = 0;
	flags.l_r = 0;
	flags.l_t = 0;
	flags.l_s = 0;
	flags.l_u = 0;
	flags.u = 0;
	flags.f = 0;
	flags.one = 0;
	flags.none = 0;
	flags.argc = 0;
	flags.count = 1;
	return (flags);
}

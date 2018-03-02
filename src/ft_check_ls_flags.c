/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:35:57 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 12:45:49 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_flag_error(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]", 2);
	ft_putstr_fd(" [file ...]\n", 2);
	exit(1);
}

void		ft_if_valid_flags(char c)
{
	if (c != 'A' && c != 'B' && c != 'C' && c != 'F' &&
			c != 'G' && c != 'H' && c != 'L' && c != 'O' &&
			c != 'P' && c != 'R' && c != 'S' && c != 'T' &&
			c != 'U' && c != 'W' && c != 'a' && c != 'b' &&
			c != 'c' && c != 'd' && c != 'e' && c != 'f' &&
			c != 'g' && c != 'h' && c != 'i' && c != 'k' &&
			c != 'l' && c != 'm' && c != 'n' && c != 'o' &&
			c != 'p' && c != 'q' && c != 'r' && c != 's' &&
			c != 'x' && c != 'w' && c != 'u' && c != 't' && c != '1')
		ft_flag_error(c);
}

int			ft_if_flags(t_flags flags)
{
	if (flags.l || flags.a || flags.r || flags.l_r || flags.t ||
			flags.one || flags.u || flags.l_u ||
			flags.l_t || flags.l_s || flags.f)
		return (1);
	return (0);
}

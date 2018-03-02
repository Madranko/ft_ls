/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 11:22:17 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 12:22:19 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_part1(t_flags *flags, char **argv, int i, int j)
{
	if (argv[j][i] == 'l')
	{
		(*flags).l = 1;
		(*flags).one = 0;
	}
	else if (argv[j][i] == '1')
	{
		(*flags).l = 0;
		(*flags).one = 1;
	}
	else if (argv[j][i] == 'f')
	{
		(*flags).f = 1;
		(*flags).a = 1;
	}
	else if (argv[j][i] == 'U')
	{
		(*flags).l_u = 1;
		(*flags).u = 0;
	}
	else if (argv[j][i] == 'u')
	{
		(*flags).l_u = 0;
		(*flags).u = 1;
	}
}

static void	ft_part2(t_flags *flags, char **argv, int i, int j)
{
	if (argv[j][i] == 'a')
		(*flags).a = 1;
	else if (argv[j][i] == 'r')
		(*flags).r = 1;
	else if (argv[j][i] == 'S')
		(*flags).l_s = 1;
	else if (argv[j][i] == 'R')
		(*flags).l_r = 1;
	else if (argv[j][i] == 't')
		(*flags).t = 1;
	else if (argv[j][i] == 'T')
		(*flags).l_t = 1;
}

static void	ft_parse_flags(t_flags *flags, char **argv, int i, int j)
{
	while (argv[j][i])
	{
		if (!ft_strcmp(argv[j], "--"))
		{
			(*flags).one = 1;
			break ;
		}
		ft_if_valid_flags(argv[j][i]);
		ft_part1(flags, argv, i, j);
		ft_part2(flags, argv, i, j);
		i++;
	}
	(*flags).count++;
}

t_flags		ft_ls_flags(char **argv, int argc)
{
	t_flags	flags;
	int		j;

	j = 1;
	flags = ft_init_flags();
	while (j < argc)
	{
		if (argv[j][0] == '-')
		{
			if (argv[j][1] == '\0')
				break ;
			ft_parse_flags(&flags, argv, 1, j);
			j++;
		}
		else
			break ;
	}
	if (!ft_if_flags(flags))
		flags.none = 1;
	if ((flags.none && argc > 2) || (!flags.none && argc > flags.count + 1))
		flags.argc = 1;
	return (flags);
}

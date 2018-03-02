/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:43:55 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 10:44:58 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_total_blocks(t_list *alst, t_flags flags)
{
	struct stat	buf;
	size_t		res;
	int			i;

	i = 0;
	res = 0;
	while (alst)
	{
		if (*(ft_strrchr(alst->content, '/') + 1) != '.' || flags.a)
		{
			lstat(alst->content, &buf);
			res = res + buf.st_blocks;
			i++;
		}
		alst = alst->next;
	}
	if (i)
		ft_printf("total %zu\n", res);
}

static void	ft_full_info(t_list *alst, t_flags flags)
{
	t_format	format;
	struct stat	buf;

	format = ft_format_file(alst, flags);
	ft_total_blocks(alst, flags);
	while (alst)
	{
		if (*(ft_strrchr(alst->content, '/') + 1) != '.' || flags.a)
		{
			if (lstat(alst->content, &buf))
				return (ft_error(alst->content));
			ft_print_info(alst, format, flags);
			ft_printf(" %.*s", ft_strlen(alst->content),
					ft_strrchr(alst->content, '/') + 1);
			if (ft_is_link(alst->content))
				ft_print_link(alst->content);
			ft_printf("\n");
		}
		alst = alst->next;
	}
}

void		ft_print_files(t_list *alst, t_flags flags)
{
	if (flags.l)
		ft_full_info(alst, flags);
	else
	{
		while (alst)
		{
			if (*(ft_strrchr(alst->content, '/') + 1) != '.' || flags.a)
			{
				ft_printf("%s", ft_strrchr(alst->content, '/') + 1);
				ft_printf("\n");
			}
			alst = alst->next;
		}
	}
}

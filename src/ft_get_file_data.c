/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:32:37 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 11:32:20 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	ft_full_info_file(t_list *alst, t_flags flags, t_format format)
{
	struct stat	buf;

	while (alst)
	{
		if (((char *)alst->content)[0] != '.' || flags.a)
		{
			if (lstat(alst->content, &buf))
				return (ft_error(alst->content));
			ft_print_info(alst, format, flags);
			ft_printf(" %.*s", ft_strlen(alst->content), alst->content);
			if (ft_is_link(alst->content))
				ft_print_link(alst->content);
			if (alst->next)
				ft_printf("\n");
		}
		alst = alst->next;
	}
}

static void	ft_full_info_path(t_list *alst, t_flags flags)
{
	t_format	format;
	struct stat	buf;

	format = ft_format_file(alst, flags);
	while (alst)
	{
		if (*(ft_strrchr(alst->content, '/') + 1) != '.' || flags.a)
		{
			if (lstat(alst->content, &buf))
				return (ft_error(alst->content));
			ft_print_info(alst, format, flags);
			ft_printf(" %.*s", ft_strlen(alst->content), alst->content);
			if (ft_is_link(alst->content))
				ft_print_link(alst->content);
			if (alst->next)
				ft_printf("\n");
		}
		alst = alst->next;
	}
}

static void	ft_print_file(t_list *alst, t_flags flags, t_format format)
{
	if (flags.l)
	{
		if (!ft_strchr(alst->content, '/'))
			ft_full_info_file(alst, flags, format);
		else
			ft_full_info_path(alst, flags);
	}
	else
	{
		while (alst)
		{
			if (ft_strrchr(alst->content, '/'))
			{
				if (*(ft_strrchr(alst->content, '/') + 1) != '.' || flags.a)
				{
					ft_printf("%s", ft_strrchr(alst->content, '/') + 1);
					ft_printf("\n");
				}
			}
			else if (((char *)alst->content)[0] != '.' || flags.a)
				ft_printf("%s", alst->content);
			alst = alst->next;
		}
	}
}

void		ft_get_file_data(char *argv, t_flags flags, t_format format)
{
	t_list	*alst;

	if (argv)
	{
		alst = ft_lstnew(argv, ft_strlen(argv) + 1);
		ft_add_time(&alst, flags);
		ft_print_file(alst, flags, format);
		ft_lstdelone(&alst, ft_lstdelfunc);
	}
}

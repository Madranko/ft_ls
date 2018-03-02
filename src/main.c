/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:47:46 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 12:27:44 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		ft_err(char **argv, int argc, int j, t_list *alst)
{
	if (!argv[j][0] && argc >= j)
	{
		if (alst)
			ft_lstdel(&alst, ft_lstdelfunc);
		ft_putstr_fd("ls: fts_open: No such file or directory\n", 2);
		exit(1);
	}
}

static t_list	*ft_arg_list(int argc, char **argv, int i)
{
	t_list	*alst;
	t_list	*newlst;
	int		j;

	alst = NULL;
	j = i;
	if (j < argc)
	{
		ft_err(argv, argc, j, alst);
		alst = ft_lstnew(argv[j], ft_strlen(argv[j]) + 1);
		((char *)alst->content)[ft_strlen(argv[j])] = '\0';
		j++;
		while (j < argc)
		{
			ft_err(argv, argc, j, alst);
			newlst = ft_lstnew(argv[j], ft_strlen(argv[j]) + 1);
			((char *)newlst->content)[ft_strlen(argv[j])] = '\0';
			ft_lstadd_end(&alst, newlst);
			j++;
		}
	}
	return (alst);
}

static int		ft_ls_args(char **argv, int ac, t_flags flags, t_format format)
{
	t_list	*lst_arg;
	int		i;

	i = flags.count;
	if (i < ac)
	{
		lst_arg = ft_arg_list(ac, argv, i);
		if (!flags.f)
		{
			ft_merge_sort_lex(&lst_arg, flags);
			ft_find_error(lst_arg);
			ft_add_time(&lst_arg, flags);
			ft_merge_sort_time(&lst_arg, flags);
			ft_add_size(&lst_arg);
			ft_merge_sort_size(&lst_arg, flags);
		}
		if (flags.r)
			ft_lstrev(&lst_arg);
		i = ft_find_files(lst_arg, flags, format);
		ft_find_dir(lst_arg, flags, format, i);
		if (lst_arg)
			ft_lstdel(&lst_arg, ft_lstdelfunc);
		return (1);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_flags		flags;
	t_format	format;

	format = ft_init_format();
	flags = ft_init_flags();
	if (argc > 1)
		flags = ft_ls_flags(argv, argc);
	if (ft_ls_args(argv, argc, flags, format))
		return (0);
	else
		ft_ls(".", flags, format);
	return (0);
}

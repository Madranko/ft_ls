/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:28:54 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 12:36:07 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf_final/libftprintf/ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
# include <errno.h>
# include <time.h>

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_format
{
	int			link_len;
	int			name_len;
	int			size_len;
	int			group_len;

}				t_format;

typedef struct	s_flags
{
	int			l_r;
	int			r;
	int			l;
	int			t;
	int			a;
	int			f;
	int			u;
	int			l_t;
	int			l_s;
	int			l_u;
	int			one;
	int			none;
	int			argc;
	int			count;
}				t_flags;

void			ft_if_valid_flags(char c);

int				ft_if_flags(t_flags flags);

void			ft_print_info(t_list *alst, t_format format, t_flags flags);

t_format		ft_make_format(t_format format, t_list *alst);

void			ft_add_size(t_list **alst);

void			ft_merge_sort_size(t_list **headref, t_flags flags);

t_list			*ft_sorted_size(t_list *a, t_list *b);

void			ft_find_dir(t_list *alst, t_flags flags, t_format format,
				int if_file);

int				ft_find_files(t_list *alst, t_flags flags, t_format format);

void			ft_find_error(t_list *alst);

void			ft_merge_sort_time(t_list **headref, t_flags flags);

void			ft_front_back_split(t_list *source, t_list **frontref,
				t_list **backref);

void			ft_sorted_time_lex(t_list **result, t_list *a, t_list *b);

void			ft_merge_sort_lex(t_list **headref, t_flags flags);

int				ft_ext_atribute(char *file);

t_format		ft_format_file(t_list *alst, t_flags flags);

void			ft_print_link(char *path);

void			ft_error(char *file);

void			ft_add_time(t_list **alst, t_flags flags);

int				ft_is_file(char *path);

void			ft_get_file_data(char *argv, t_flags flags, t_format format);

int				ft_is_link(char *path);

void			ft_print_type(mode_t mode);

void			ft_print_time(struct timespec file_time, t_flags flags);

t_format		ft_init_format(void);

int				ft_int_len(unsigned long long int nb);

void			ft_print_mode(struct stat buf);

void			ft_print_files(t_list *alst, t_flags flags);

void			ft_lstrev(t_list **alst);

void			ft_ls_recursive(t_list *alst, t_flags flags, t_format format);

t_flags			ft_init_flags(void);

int				ft_is_dir(char *path);

t_flags			ft_ls_flags(char **argv, int argc);

t_list			*ft_lst_files(DIR *dir, char **dir_name);

void			ft_ls(char *path, t_flags flags, t_format format);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:25:47 by mmotov            #+#    #+#             */
/*   Updated: 2018/01/01 13:26:51 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_form
{
	int				flag_minus;
	int				flag_plus;
	int				flag_space;
	int				flag_octorp;
	int				flag_zero;
	int				flag_apost;
	unsigned int	width;
	int				accur;
	char			*size;
	char			type;
}				t_form;

int				ft_star(t_form *form, va_list ap, int i);

char			*ft_check_apostrophe(char *str, t_form form);

char			*ft_type_search(char *str, t_form *form);

char			*ft_accuracy_search(char *str, t_form *form, va_list ap);

char			*ft_size_search(char *str, t_form *form);

char			*ft_width_search(char *str, t_form *form, va_list ap);

char			*ft_flags_search(char *str, t_form *form);

int				ft_end_form(char c);

size_t			ft_full_arr_strlen(unsigned char **arr);

void			ft_del_arr(unsigned char **arr);

char			*ft_check_width_unicode(t_form form, unsigned char **str);

void			ft_print_unicode(unsigned char *str);

char			*ft_add_accur(t_form form, char *str);

int				ft_print_null(t_form form);

char			*ft_check_width_str(t_form form, char *str);

char			*ft_check_flags_num(t_form form, char *str);

int				ft_str_invalid(t_form *form);

int				ft_str_long_integers(t_form *form, va_list ap);

char			*ft_check_accur_str(t_form form, char *str);

char			*ft_check_width_num(t_form form, char *str);

int				ft_str_string_unicode(t_form *form, va_list ap);

int				ft_str_char(t_form *form, va_list ap);

int				ft_str_unicode(t_form *form, va_list ap);

int				ft_str_string(t_form *form, va_list ap);

char			*ft_push_x(char *str, char c);

int				ft_str_ptr(t_form *form, va_list ap);

int				ft_str_percent(t_form *form);

unsigned char	*ft_make_unicode(unsigned int b);

int				ft_str_octal(t_form *form, va_list ap);

int				ft_str_hexal(t_form *form, va_list ap);

int				ft_str_unsigned(t_form *form, va_list ap);

char			*ft_check_accur(t_form form, char *str);

char			*ft_push_char(char *str, char symbol, char c);

char			*ft_find_change(char *str, char old, char new);

int				ft_printf(const char *restrict format, ...);

char			*ft_itoa_base(long long int nb, int base);

char			*ft_itoa_uns(size_t nb, int base);

int				ft_str_integers(t_form *form, va_list ap);

char			*ft_str_toupper(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:14:14 by mmotov            #+#    #+#             */
/*   Updated: 2018/01/01 13:25:43 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_part_1(va_list ap, t_form *form)
{
	int		result;

	if ((result = ft_str_integers(form, ap)))
		return (result);
	else if ((result = ft_str_unsigned(form, ap)))
		return (result);
	else if ((result = ft_str_octal(form, ap)))
		return (result);
	else if ((result = ft_str_hexal(form, ap)))
		return (result);
	else if ((result = ft_str_ptr(form, ap)))
		return (result);
	else if ((result = ft_str_percent(form)))
		return (result);
	else
		return (-1);
}

static int		ft_part_2(va_list ap, t_form *form)
{
	int		result;

	if ((result = ft_str_string(form, ap)))
		return (result);
	else if ((result = ft_str_char(form, ap)))
		return (result);
	else if ((result = ft_str_unicode(form, ap)))
		return (result);
	else if ((result = ft_str_string_unicode(form, ap)))
		return (result);
	else if ((result = ft_str_long_integers(form, ap)))
		return (result);
	else if (ft_end_form((*form).type))
		return (ft_str_invalid(form));
	else
		return (-1);
}

static int		ft_type(va_list ap, t_form *form)
{
	int		result;

	if ((result = ft_part_1(ap, form)) != -1)
		return (result);
	else if ((result = ft_part_2(ap, form)) != -1)
		return (result);
	else
		return (0);
}

static char		*ft_form(char *str, va_list ap, int *result)
{
	t_form	form;

	form.flag_zero = 0;
	form.flag_octorp = 0;
	form.flag_space = 0;
	form.flag_minus = 0;
	form.flag_plus = 0;
	form.flag_apost = 0;
	str = ft_flags_search(str, &form);
	str = ft_width_search(str, &form, ap);
	str = ft_accuracy_search(str, &form, ap);
	str = ft_size_search(str, &form);
	str = ft_type_search(str, &form);
	*result = *result + ft_type(ap, &form);
	if (form.size)
		ft_strdel(&(form.size));
	return (str);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		result;

	result = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		while (*format == '%')
		{
			format++;
			format = ft_form((char *)format, ap, &result);
		}
		if (*format)
		{
			ft_putchar(*format);
			result++;
			format++;
		}
	}
	return (result);
}

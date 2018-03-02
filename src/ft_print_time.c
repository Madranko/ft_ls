/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:47:07 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 11:34:02 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_print_time(struct timespec file_time, t_flags flags)
{
	long int	cur_time;
	char		*time_str;
	char		*minutes;
	char		*year;
	char		*new_time;

	time_str = ctime((time_t *)&file_time);
	new_time = ft_strdup(time_str);
	cur_time = time(NULL);
	minutes = ft_strdup(new_time + (ft_strlen(new_time) - 15));
	year = ft_strdup(new_time + (ft_strlen(new_time) - 5));
	ft_printf(" %.*s", ft_strlen(new_time) - 19, new_time + 4);
	if (flags.l_t)
		ft_printf("%.*s", ft_strlen(minutes) - 1, minutes);
	else if (cur_time - file_time.tv_sec > 15811200)
		ft_printf("  %.*s", ft_strlen(year) - 1, year);
	else
		ft_printf("%.*s", ft_strlen(new_time) - 19, minutes);
	ft_strdel(&minutes);
	ft_strdel(&year);
	ft_strdel(&new_time);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:26:55 by mmotov            #+#    #+#             */
/*   Updated: 2017/11/12 09:41:50 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	t_list	*last;
	int		lst_size;
	int		i;

	i = 0;
	last = lst;
	if (lst)
	{
		lst_size = ft_lstsize(lst);
		ft_putstr("List size = ");
		ft_putnbr(lst_size);
		ft_putstr("\n*******************\n");
		while (i < lst_size)
		{
			ft_putnbr(i);
			ft_putstr(" content = ");
			ft_putendl(last->content);
			ft_putstr("content_size = ");
			ft_putnbr(last->content_size);
			ft_putchar('\n');
			ft_putstr("-------------------\n");
			last = last->next;
			i++;
		}
	}
}

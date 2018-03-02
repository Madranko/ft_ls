/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:41:24 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 11:33:33 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_merge_sort_size(t_list **headref, t_flags flags)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	if (flags.l_s)
	{
		ft_front_back_split(head, &a, &b);
		ft_merge_sort_size(&a, flags);
		ft_merge_sort_size(&b, flags);
		*headref = ft_sorted_size(a, b);
	}
}

void	ft_merge_sort_time(t_list **headref, t_flags flags)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	if (flags.t)
	{
		ft_front_back_split(head, &a, &b);
		ft_merge_sort_time(&a, flags);
		ft_merge_sort_time(&b, flags);
		*headref = ft_sorted_size(a, b);
	}
}

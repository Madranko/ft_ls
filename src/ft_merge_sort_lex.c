/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_lex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:39:21 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 11:31:45 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static t_list	*ft_sorted_merge(t_list *a, t_list *b)
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp((char *)a->content, (char *)b->content) < 0)
	{
		result = a;
		result->next = ft_sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = ft_sorted_merge(a, b->next);
	}
	return (result);
}

void			ft_merge_sort_lex(t_list **headref, t_flags flags)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	ft_front_back_split(head, &a, &b);
	ft_merge_sort_lex(&a, flags);
	ft_merge_sort_lex(&b, flags);
	*headref = ft_sorted_merge(a, b);
}

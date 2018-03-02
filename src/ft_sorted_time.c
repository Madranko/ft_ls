/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmotov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 11:23:22 by mmotov            #+#    #+#             */
/*   Updated: 2018/02/26 11:34:37 by mmotov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ft_sorted_time_lex(t_list **result, t_list *a, t_list *b)
{
	if (ft_strcmp((char*)a->content, (char*)b->content) > 0)
	{
		*result = b;
		(*result)->next = ft_sorted_size(b->next, a);
	}
	else
	{
		*result = a;
		(*result)->next = ft_sorted_size(b, a->next);
	}
}

t_list	*ft_sorted_size(t_list *a, t_list *b)
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->content_size == b->content_size)
		ft_sorted_time_lex(&result, a, b);
	else if (a->content_size > b->content_size)
	{
		result = a;
		result->next = ft_sorted_size(a->next, b);
	}
	else
	{
		result = b;
		result->next = ft_sorted_size(a, b->next);
	}
	return (result);
}

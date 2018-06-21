/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_link_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:31:08 by nroman            #+#    #+#             */
/*   Updated: 2018/06/20 19:22:09 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_link_del(t_list **begin_list, void *content_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*prev;

	prev = *begin_list;
	current = *begin_list;
	while (current)
	{
		if (!cmp(content_ref, current->content))
		{
			ft_memdel(&(current->content));
			if (current == *begin_list)
			{
				*begin_list = current->next;
				free(current);
			}
			else
			{
				prev->next = current->next;
				free(current);
			}
		}
		prev = current;
		current = current->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:37:31 by nroman            #+#    #+#             */
/*   Updated: 2018/02/27 15:41:49 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;

	if (lst && f)
	{
		if (lst->next)
		{
			begin = ft_lstmap(lst->next, f);
			ft_lstadd(&begin, f(lst));
		}
		else
			begin = f(lst);
		return (begin);
	}
	return (NULL);
}

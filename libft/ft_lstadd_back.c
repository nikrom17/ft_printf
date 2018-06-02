/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:01:52 by nroman            #+#    #+#             */
/*   Updated: 2018/02/27 15:39:42 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current;
	t_list	*begin;

	if (alst)
	{
		current = *alst;
		begin = current;
		while (current->next)
			current = current->next;
		current->next = new;
		*alst = begin;
	}
}

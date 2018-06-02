/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 16:10:50 by nroman            #+#    #+#             */
/*   Updated: 2018/05/26 14:28:45 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc_str(char *str, size_t size)
{
	char	*new_str;
	char	*res;

	new_str = ft_memalloc(size);
	res = ft_strjoin(str, new_str);
	free(str);
	free(new_str);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:32:30 by nroman            #+#    #+#             */
/*   Updated: 2018/02/25 12:31:49 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int size;
	int i;
	int temp;

	i = 0;
	size = 0;
	if (str)
	{
		while (str[size] != '\0')
			size++;
		size--;
		while (i <= (size / 2))
		{
			temp = str[i];
			str[i] = str[size - i];
			str[size - i] = temp;
			i++;
		}
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:22:08 by nroman            #+#    #+#             */
/*   Updated: 2018/02/28 09:45:01 by nroman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_counter(char const *str, char c)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (str[i] == c)
		i++;
	if (i != 0)
		words--;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (str[i - 1] == c)
				words++;
		}
		i++;
	}
	words++;
	return (words);
}

static char		*word_build(char const *str, int *index, char c)
{
	char	*word;
	int		i;
	int		start;
	int		end;

	i = *index;
	while (str[i] == c && str[i])
		i++;
	start = i - 1;
	while (str[i] != c && str[i])
		i++;
	end = i;
	*index = i;
	word = (char*)malloc(sizeof(char) * (end - start) + 1);
	if (!word)
		return (NULL);
	if (ft_isempty(str))
		return (word = NULL);
	i = 0;
	while (++start < end)
		word[i++] = str[start];
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**array;
	int		i;
	int		k;
	int		words;

	if (!str)
		return (NULL);
	words = word_counter(str, c);
	array = (char**)malloc(sizeof(char*) * words + 1);
	if (!array)
		return (NULL);
	k = 0;
	i = 0;
	while (k < words)
	{
		array[k] = word_build(str, &i, c);
		k++;
	}
	array[k] = 0;
	return (array);
}

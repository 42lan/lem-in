/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:18:21 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/19 23:04:15 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Computes and returns the number of words in a given string s separated by c.
*/

int			ft_count_words(char const *s, char c)
{
	int		i;
	int		words;

	i = -1;
	words = 0;
	if (!s || !*s)
		return (0);
	while (s[++i])
		if (!ft_isseparator(s[i], c))
		{
			++words;
			while (s[i] && !ft_isseparator(s[i], c))
				++i;
			if (s[i] == '\0')
				break ;
		}
	return (words);
}

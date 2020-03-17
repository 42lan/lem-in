/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:01:09 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/12 12:00:39 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static	size_t	word_count(const char *s, char c)
{
	size_t		i;
	size_t		cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			cnt++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (cnt);
}

static	size_t	word_len(const char *s, char c)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		++len;
	return (len);
}

static	int		assign_words(char **res, size_t word_count,
		const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*word;

	i = 0;
	j = word_count;
	while (s[i] == c)
		++i;
	while (j > 0)
	{
		len = word_len(s + i, c);
		if ((word = (char*)ft_strnew(len)) == NULL)
			return (0);
		ft_strncpy(word, s + i, len);
		res[word_count - j] = word;
		i += len;
		while (s[i] == c)
			i++;
		--j;
	}
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		cnt;
	char		**res;

	if (s == NULL)
		return (NULL);
	cnt = word_count(s, c);
	res = (char**)ft_memalloc(sizeof(*res) * (cnt + 1));
	if (res == NULL)
		return (NULL);
	if (assign_words(res, cnt, s, c) == 0)
		return (0);
	return (res);
}

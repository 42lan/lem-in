/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:17:46 by abaisago          #+#    #+#             */
/*   Updated: 2019/11/03 00:34:55 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	size_t		tmp;
	const char	*start;
	const char	*anchor;
	char		*res;

	if (s == NULL)
		return (NULL);
	tmp = ft_strskip(s, &ft_iswhitespace);
	start = s + tmp;
	anchor = start;
	while (s[tmp] != '\0')
	{
		if (!ft_iswhitespace(s[tmp]) && s[tmp] != '\0')
			anchor = (char*)s + tmp + 1;
		++tmp;
	}
	tmp = anchor - start;
	if ((res = ft_strnew(tmp)) == NULL)
		return (NULL);
	ft_strncpy(res, start, tmp);
	return (res);
}

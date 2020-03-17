/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:46:37 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/09 18:57:54 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if ((res = (char*)ft_memalloc(size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = f(s[i]);
		i++;
	}
	return (res);
}

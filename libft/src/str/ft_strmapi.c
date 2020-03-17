/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:58:41 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/12 11:31:43 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}

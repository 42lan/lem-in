/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:30:01 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/12 18:00:46 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	size_t	i;

	res = NULL;
	i = ft_strlen(s);
	while (s[i] != (char)c && i != 0)
		--i;
	if (s[i] == (char)c)
		res = (char*)s + i;
	return (res);
}

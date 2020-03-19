/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:29:22 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/09 13:58:16 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	while (i < n && s2[i])
	{
		s1[i + s1_len] = s2[i];
		i++;
	}
	s1[i + s1_len] = '\0';
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:10:56 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/09 14:06:30 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strcat(char *s1, const char *s2)
{
	size_t		i;
	size_t		s1_len;
	size_t		s2_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	while (i < s2_len)
	{
		s1[i + s1_len] = s2[i];
		i++;
	}
	s1[i + s1_len] = '\0';
	return (s1);
}

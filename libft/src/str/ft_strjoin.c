/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:51:14 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/12 11:00:53 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2 || !(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	res = ft_strcpy(res, s1);
	res = ft_strcat(res, s2);
	return (res);
}

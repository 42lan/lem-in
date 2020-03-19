/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:22:18 by abaisago          #+#    #+#             */
/*   Updated: 2018/12/11 12:59:19 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, char c)
{
	char	*res;

	if ((res = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	if (c == 'b')
	{
		ft_strdel((char**)&s1);
		ft_strdel((char**)&s2);
	}
	else if (c == 'l')
		ft_strdel((char**)&s1);
	else if (c == 'r')
		ft_strdel((char**)&s2);
	return ((char*)res);
}

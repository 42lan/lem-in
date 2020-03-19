/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:00:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/12/22 06:12:21 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Split the string str into tokens separated by characters in sep.
*/

char				*ft_strtok(char *str, const char *sep)
{
	static char		*static_str;
	int				i;

	if (str == NULL && static_str != NULL)
		str = static_str;
	if (str)
	{
		i = ft_strcspn(str, sep);
		str = str + i;
		static_str = str + ft_strspn(str, sep);
		if (*static_str == '\0')
			static_str = NULL;
		*str = '\0';
		return (str - i);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:01:48 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/14 16:12:04 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strcapitalize(char *str)
{
	size_t	i;
	size_t	first_letter;

	i = 0;
	first_letter = 1;
	while (str[i] != '\0')
	{
		if (ft_isupper(str[i]))
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]))
			first_letter = 1;
		if (ft_isalpha(str[i]) || ft_isdigit(str[i]))
		{
			if (ft_islower(str[i]) && first_letter)
				str[i] -= 32;
			first_letter = 0;
		}
		i++;
	}
	return (str);
}

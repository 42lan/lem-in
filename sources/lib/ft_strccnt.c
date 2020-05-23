/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 16:46:28 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/22 16:48:04 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_strccnt(const char *str, char c)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	while (str[++i])
		if (str[i] == c)
			cnt += 1;
	return (cnt);
}

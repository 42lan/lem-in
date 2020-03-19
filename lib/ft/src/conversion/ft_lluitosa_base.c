/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluitosa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:39:51 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/12 17:58:15 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdint.h>

char	*ft_lluitosa_base(size_t value, int8_t base, char *tab)
{
	size_t		i;

	i = 0;
	ft_getnbr_base(value, base, tab, &i);
	tab[i] = '\0';
	return (tab);
}

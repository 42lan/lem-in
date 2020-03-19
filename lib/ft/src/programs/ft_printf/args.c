/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:59:08 by abaisago          #+#    #+#             */
/*   Updated: 2019/04/01 15:22:07 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "integers.h"
#include "percent.h"

#include <stdarg.h>
#include <string.h>
#include <stdint.h>

int		get_star(va_list ap, char **str)
{
	int		nbr;

	(*str)++;
	nbr = va_arg(ap, int);
	return (nbr);
}

int		switch_number_star(va_list ap, char **str)
{
	if (**str == '*')
		return (get_star(ap, str));
	else
		return (get_number(str));
}

void	get_arg(va_list og, va_list ap, char **str)
{
	char	*bak;
	int		n;

	bak = *str;
	n = get_number(str);
	if (**str == '$')
	{
		(*str)++;
		va_copy(ap, og);
		while (n-- > 1)
			va_arg(ap, void*);
	}
	else
		*str = bak;
}

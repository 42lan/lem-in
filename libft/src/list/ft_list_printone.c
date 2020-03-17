/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_printone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:58:45 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/01 09:01:58 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_printone() function applies the
** __print__ function to the __link__ proveded
** as an argument.
**
** Returns the integer output value of __print__.
*/

int		ft_list_printone(t_list_link *link, unsigned pos,
			int (*print)(void *, size_t, unsigned))
{
	return (print(link->content, link->content_size, pos));
}

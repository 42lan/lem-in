/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_behead.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:30:53 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 12:38:50 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

/*
** The ft_list_behead() function frees the t_list
** struct of a list without deleting any of its links.
**
** *__alist__ is set to NULL.
**
** Returns no value.
*/

void	ft_list_behead(t_list **alist)
{
	(*alist)->head = NULL;
	(*alist)->len = 0;
	(*alist)->size = 0;
	free(*alist);
	*alist = NULL;
}

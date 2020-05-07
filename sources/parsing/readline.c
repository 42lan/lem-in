/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 01:00:23 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/08 01:13:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "errors.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

int		readline(char **line)
{
	int	ret;

	if ((ret = get_next_line(0, line)) < 0)
		ft_printerr("lem-in(read): %s\n", strerror(errno));
	if (ret > 0)
		ft_printf("%s\n", *line);
	else
		ft_putchar('\n');
	return (ret);
}

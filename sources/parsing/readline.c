/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 01:00:23 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/08 02:16:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "errors.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

int		readline(char **line, int eof)
{
	int	ret;

	if ((ret = get_next_line(0, line)) < 0)
		ft_printerr("lem-in(read): %s\n", strerror(errno));
	if (ret == 0 && eof != 1)
		ft_printerr(ERROR);
	ft_printf("%s\n", *line);
	if (ret == 0 && eof == 1)
		ft_printf("\n");
	return (ret);
}

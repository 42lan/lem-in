/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curly.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:08:38 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/22 14:52:29 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "curly.h"
#include "libft.h"

#include "curly_utils.h"
#include "output.h"

#include <stdint.h>

static void			ctl_default(t_escseq *seq, char **str, t_buf *buf)
{
	seq->code = -1;
	write_curly(seq, 0, str, buf);
}

static t_ctltab	g_ctltab[] =
{
	{'f', &ctl_colors},
	{'b', &ctl_colors},
	{'m', &ctl_sgr_code},
	{'r', &ctl_reset},
	{'}', &ctl_reset},
	{0, &ctl_default}
};

static t_escfunc	get_escape_funciton(char c)
{
	int		i;

	i = 0;
	while (g_ctltab[i].type != c && g_ctltab[i].type != 0)
		++i;
	return (g_ctltab[i].func);
}

void				curly(char **str, t_buf *buf)
{
	t_escfunc	function;
	t_escseq	seq;

	++(*str);
	seq.code = 0;
	function = get_escape_funciton(**str);
	if (function != 0)
		function(&seq, str, buf);
}

void				write_curly(t_escseq *seq, t_str *res,
						char **str, t_buf *buf)
{
	if (**str != '}')
		seq->code = -1;
	if (seq->code == -1)
	{
		*str += skip_to_colsing_curly(str);
		write_str(buf, "\033[0m", 4);
		write_str(buf, "{ERROR}", 7);
	}
	else
	{
		write_char(buf, '\033', 1);
		write_str(buf, res->str, res->len);
	}
}

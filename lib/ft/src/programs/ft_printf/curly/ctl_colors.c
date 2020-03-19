/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suvitiel <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:28:27 by suvitiel          #+#    #+#             */
/*   Updated: 2019/04/01 17:39:39 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "curly.h"

#include <string.h>

static t_base_colors g_colors[] =
{
	{"black", 30},
	{"red", 31},
	{"green", 32},
	{"yellow", 33},
	{"blue", 34},
	{"magenta", 35},
	{"cyan", 36},
	{"white", 37},
	{0, -1}
};

/*
** - Match the string written by the user and one of the basic colors.
**   seq->code = -1 in case of an error;
** - Add ground (0 or 10) for (fore|back)ground.
** - Add 60 for bright version of the colors if
**   the user has specified a '!' charcter.
*/

static int8_t	get_color_str(t_escseq *seq, int8_t gd, char **str, char *tab)
{
	size_t	i;

	i = 0;
	while (g_colors[i].code != -1 && ft_strmatch(g_colors[i].str, *str) == 0)
		++i;
	seq->code = g_colors[i].code;
	if (seq->code == -1)
		return (0);
	*str += ft_strlen(g_colors[i].str);
	seq->code += gd;
	if (**str == '!')
	{
		++(*str);
		seq->code += 60;
	}
	ft_lluitosa_base(seq->code, 10, tab);
	return (ft_strlen(tab));
}

static int8_t	get_rgb(int8_t *cnt, char **str)
{
	int8_t	i;
	int8_t	j;

	i = 0;
	*cnt = 0;
	while (++(*cnt) < 4)
	{
		if ((*str)[i] < '0' || (*str)[i] > '9')
			*cnt = 10;
		j = 0;
		while ((*str)[i] >= '0' && (*str)[i] <= '9' && j < 3)
		{
			++i;
			++j;
		}
		if ((*str)[i] != ';')
			break ;
		else
			++i;
	}
	return (i);
}

/*
** - Get 1 SGR color number or 3 RGB number(s) input by
**   the user. seq->code = -1 if only 2 numbers are input.
*/

static int8_t	get_color_num(t_escseq *seq, int8_t gd, char **str, char *tab)
{
	int8_t	cnt;
	int8_t	i;

	i = get_rgb(&cnt, str);
	seq->code = 38 + gd;
	ft_lluitosa_base(seq->code, 10, tab);
	if (cnt == 1)
		ft_strncpy(tab + 2, ";5;", 3);
	else if (cnt == 3)
		ft_strncpy(tab + 2, ";2;", 3);
	else
	{
		seq->code = -1;
		return (0);
	}
	ft_strncpy(tab + 5, *str, i);
	(*str) += i;
	return (i + 5);
}

void			ctl_colors(t_escseq *seq, char **str, t_buf *buf)
{
	t_str		res;
	char		tab[18];
	int8_t		ground;
	size_t		i;

	tab[0] = '[';
	ground = (**str == 'b') ? 10 : 0;
	(*str)++;
	i = 1;
	if (ft_isalpha(**str))
		i += get_color_str(seq, ground, str, tab + i);
	else
		i += get_color_num(seq, ground, str, tab + 1);
	tab[i++] = 'm';
	res.str = tab;
	res.len = i;
	write_curly(seq, &res, str, buf);
}

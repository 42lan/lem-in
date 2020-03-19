/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curly.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:29:30 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/22 15:04:20 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURLY_H
# define CURLY_H
# include "libft.h"
# include "output.h"
# include <stdint.h>

typedef struct		s_escseq
{
	int16_t			code;
	uint8_t			arg;
}					t_escseq;

typedef void		(*t_escfunc)(t_escseq*, char**, t_buf*);

typedef struct		s_ctltab
{
	char			type;
	t_escfunc		func;
}					t_ctltab;

typedef struct		s_base_colors
{
	char			*str;
	int8_t			code;
}					t_base_colors;

void				ctl_colors(t_escseq *seq, char **str, t_buf *buf);
void				ctl_sgr_code(t_escseq *seq, char **str, t_buf *buf);
void				ctl_reset(t_escseq *seq, char **str, t_buf *buf);

void				curly(char **str, t_buf *buf);
void				write_curly(t_escseq *seq, t_str *res,
						char **str, t_buf *buf);

/*
** CURLY.H
*/
#endif

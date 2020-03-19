/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:17:52 by abosch            #+#    #+#             */
/*   Updated: 2020/01/22 14:50:35 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# define BUFF_SIZE	1024

typedef struct	s_str
{
	char		*str;
	int			len;
}				t_str;

int				ft_vdprintf(int fd, const char *fmt, va_list ap);
int				ft_dprintf(int fd, const char *fmt, ...);
int				ft_printf(const char *fmt, ...);

#endif

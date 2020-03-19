/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:23:28 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/19 17:57:52 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATS_H
# define FLOATS_H

# define FLOAT_SIGN         0x80000000
# define FLOAT_SIGN_LEN     1
# define FLOAT_EXP          0x7F800000
# define FLOAT_EXP_LEN      8
# define FLOAT_MANTISSA     0x007FFFFF
# define FLOAT_MANTISSA_LEN 23

char	*ftoa(long double nbr, unsigned int precision);

/*
** FLOATS_H
*/
#endif

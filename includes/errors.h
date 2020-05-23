/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 17:02:15 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/23 12:18:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERROR		"ERROR\n"
# define E_ANTS		"ERROR: 1st line must be a number between 1 and UINT_MAX\n"
# define E_NOANT	"ERROR: no ants are provided in the current map\n"
# define E_NONDIG	"ERROR: 1st line contains non-digit character(s)\n"
# define E_SE_DEF	"ERROR: START and/or END rooms aren't defined\n"
# define E_SE_LINK	"ERROR: START and/or END rooms haven't at least one link\n"
# define E_ROOMS	"ERROR: incorrect room definition\n"
# define E_LINKS	"ERROR: incorrect link definition\n"
# define E_WSPACE	"ERROR: link contains whitespace character(s)\n"
# define E_MAP		"ERROR: invalid map - no path between START and END\n"

/*
** ERRORS_H
*/
#endif

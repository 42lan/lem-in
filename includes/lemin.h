/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:54:34 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/14 22:21:56 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "colors.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "system_libraries.h"

// Error Management Flag - activable on make EMF="-D EMF=1"
# ifndef EMF
#  define EMF 0
# endif

# define SUCCESS 0
# define FAILURE 1

typedef struct		s_link
{

}					t_link;

typedef struct		s_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
}					t_room;

typedef struct		s_farm
{
	int				number_of_ants;
	t_room			*rooms;
	t_link			*links;
}					t_farm;

void		initialize_farm(t_farm *farm);
int			parse_hashtag(t_farm *farm, const char *line);
int			parse_input(t_farm *farm);
void		print_help(void);

/*
** PREDICATES
*/
int			is_number(const char *str);
int			is_command(const char *str);
int			is_comment(const char *str);

/*
** TOOLS
*/

void	print_farm(t_farm *farm);

/*
** LEMIN_H
*/
#endif

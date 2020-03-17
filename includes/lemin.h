/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:54:34 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/17 11:27:45 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "colors.h"
# include "ft_printf/ft_printf.h"
# include "system_libraries.h"

// Error Management Flag - activable on make EMF="-D EMF=1"
# ifndef EMF
#  define EMF 0
# endif

# define SUCCESS 0
# define FAILURE 1

typedef struct	s_data t_data;
typedef struct	s_farm t_farm;
typedef struct	s_room t_room;
typedef struct	s_link t_link;

struct			s_data
{
	t_list		*raw_input;
	t_list		*uncommented_input;
	t_farm		*farm;
};

struct			s_farm
{
	int			number_of_ants;
	t_room		*rooms;
	t_link		*links;
};

struct			s_room
{
	char		*name;
	int			coord_x;
	int			coord_y;
	t_room		*prev;
	t_room		*next;
};

struct		s_link
{
};


void	initialization(t_data *data);

/*
** PARSING
*/
int				parse_input(t_data *data);
t_list			*save_raw_input(void);
t_list			*uncomment_raw_input(t_list *raw_input);
int				parse_hashtag(t_farm *farm, const char *line);

/*
** PREDICATES
*/
int			is_invalid_line(const char *str);
int			is_number(const char *str);
int			is_command(const char *str);

/*
** TOOLS
*/

void	print_farm(t_farm *farm);
void	print_help(void);

int		get_next_line(const int fd, char **line);
/*
** LEMIN_H
*/
#endif

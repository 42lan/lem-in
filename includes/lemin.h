/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:54:34 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/19 23:52:21 by abaisago         ###   ########.fr       */
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
};

struct			s_farm
{
	unsigned	ants;
	t_list		*rooms;
};

struct			s_room
{
	char		*name;
	t_ivec2		coord;
	t_byte		flags;
};

struct			s_link
{
};


void			initialization(t_data *data);

/*
** LIB
*/
size_t			ft_arraysize(char **array);
int				ft_count_words(char const *s, char c);
size_t			ft_silen(intmax_t number, int base);
size_t			ft_uilen(uintmax_t number, int base);
int				ft_isseparator(char c, char separator);
char			*ft_strtok(char *str, const char *sep);
size_t			ft_strspn(const char *s, const char *charset);
size_t			ft_strcspn(const char *s, const char *charset);

/*
** PARSING
*/
int				parse_input(t_data *data);
t_list			*save_raw_input(void);
t_list			*uncomment_raw_input(t_list *raw_input);
unsigned int	save_ants(t_list *uncommented_input);
t_list			*save_rooms(t_list *uncommented_input, int size);
t_list			*save_links(t_list *uncommented_input, int size);
int				parse_hashtag(t_farm *farm, const char *line);
void			check_room_names(t_list *rooms);

/*
** PREDICATES
*/
int			is_invalid_line(const char *str);
int			is_number(const char *str);
int			is_command(const char *str);
int			is_room(char *line);
int			is_link(char *line);

/*
** TOOLS
*/

void	print_farm(t_farm *farm);
void	print_help(void);

/*
** LEMIN_H
*/
#endif

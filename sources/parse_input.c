/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 09:32:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/14 22:19:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			parse_input(t_farm *farm)
{
	ft_printf("_________START PARSING_________\n");
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (is_comment(line) == SUCCESS)
		{
			ft_printf("Skipping: [%s]\n", line);
			continue ;
		}
		if (farm->number_of_ants == -1)
		{
			if (is_number(line) == SUCCESS)
				farm->number_of_ants = ft_atoi(line);
		}
		ft_strdel(&line);
	}
	print_farm(farm);
	ft_printf("_________END PARSING_________\n");
	return (SUCCESS);
}

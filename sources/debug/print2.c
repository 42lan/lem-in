#include "lemin.h"

void	show_orien(t_room *room)
{
	unsigned	i;

	i = 0;
	ft_printf("~~~~~~~ Orientation de la piece %s ~~~~~~~\n", room->name);
	while (i < LINK_SIZE)
	{
		ft_printf("n-%d : %s - ", i, ROOMS[LINK_ARR[i]].name);
		if (LINK_DIR[i] == DUPLEX)
			ft_printf("DUPLEX\n");
		else if (LINK_DIR[i] == BLOCKED)
			ft_printf("BLOCKED\n");
		else if (LINK_DIR[i] == ALLOWED)
			ft_printf("ALLOWED\n");
		else
			ft_printf("NO ORIENTATION\n");
		i++;
	}
}

#include "lemin.h"

void	show_orien_name(const char *name)
{
	unsigned	i;
	unsigned	j;
	t_room		*room;

	i = 0;
	j = -1;
	ft_printf("~~~~~~~ Orientation de la piece par nom %s ~~~~~~~\n", name);
	while (++j < g_farm.size)
	{
		room = &g_farm.rooms[i];
		if (ft_strequ(room->name, name))
			while (i < LINK_SIZE)
			{
				ft_printf("%s - ", ROOMS[LINK_ARR[i]].name);
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
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void	show_orien(t_room *room)
{
	unsigned	i;

	i = 0;
	ft_printf("~~~~~~~ Orientation de la piece %s ~~~~~~~\n", room->name);
	while (i < LINK_SIZE)
	{
		ft_printf("%s - ", ROOMS[LINK_ARR[i]].name);
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
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void	print_map_cost(void)
{
	unsigned	i;

	i = 0;
	while (i < g_farm.size)
	{
		ft_printf("%-7s pre: %3u/%-10u | cost: %3u/%-10u\n", ROOMS[i].name, ROOMS[i].pre[CUR],  ROOMS[i].pre[OLD], ROOMS[i].cost[CUR], ROOMS[i].cost[OLD] );
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:25:22 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/25 13:09:12 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static t_gnl	*gnlnew(int fd, t_gnl *begin)
{
	t_gnl			*list;

	if (!(list = (t_gnl*)malloc(sizeof(*list))))
		return (NULL);
	if ((list->rest = ft_strnew(0)) == NULL)
		return (NULL);
	list->fd = fd;
	list->next = begin;
	return (list);
}

static t_gnl	*get_file(t_gnl **begin, int fd)
{
	t_gnl	*lst;

	lst = *begin;
	while (lst && lst->fd != fd)
		lst = lst->next;
	if (lst == NULL)
	{
		if (!(lst = gnlnew(fd, *begin)))
			return (NULL);
		*begin = lst;
	}
	return (lst);
}

static void		del_file(t_gnl **begin, t_gnl *lst)
{
	t_gnl	*prev;

	if (*begin == lst)
		*begin = lst->next;
	else
	{
		prev = *begin;
		while (prev->next != lst)
			prev = prev->next;
		prev->next = lst->next;
	}
	free(lst->rest);
	free(lst);
}

static int		get_line(t_gnl *lst, char **line)
{
	size_t			nl;

	nl = ft_strclen(lst->rest, '\n');
	if (!(*line = ft_strsub(lst->rest, 0, nl)))
		return (-1);
	if (lst->rest[nl] == '\n')
		ft_strcpy(lst->rest, lst->rest + nl + 1);
	else
		lst->rest[0] = '\0';
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_gnl	*files = NULL;
	t_gnl			*lst;
	int				ret;

	ret = 0;
	if (fd < 0 || !line || BUFF_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	if ((lst = get_file(&files, fd)) == NULL)
		return (-1);
	while (!ft_strchr(lst->rest, '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((lst->rest = ft_strjoin_free(lst->rest, buf, 'l')) == NULL)
			return (-1);
	}
	if (ret < 0 || (ret == 0 && lst->rest[0] == 0))
	{
		del_file(&files, lst);
		return (ret);
	}
	else
		return (get_line(lst, line));
}

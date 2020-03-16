#include "libft.h"

void		ft_list(t_lst **list, t_str **ptr, int fd, char **line)
{
	t_lst	*new_list;

	*line = NULL;
	*ptr = (t_str *)malloc(sizeof(t_str));
	(*ptr)->temp = NULL;
	if (!(*list))
	{
		*list = (t_lst *)malloc(sizeof(t_lst));
		(*list)->lfd = fd;
		(*list)->buf = NULL;
		(*list)->next = NULL;
	}
	(*ptr)->head = *list;
	while (*list && (*list)->next && (*list)->lfd != fd)
		*list = (*list)->next;
	if (*list && (*list)->lfd != fd)
	{
		new_list = (t_lst *)malloc(sizeof(t_lst));
		new_list->lfd = fd;
		new_list->buf = NULL;
		new_list->next = (*ptr)->head;
		(*ptr)->head = new_list;
		*list = (*ptr)->head;
		new_list = NULL;
	}
}

void		ft_bufsub(char **buf, int start)
{
	char	*temp;
	int		i;

	if (!(temp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return ;
	i = 0;
	start++;
	while (start < BUFF_SIZE)
		temp[i++] = (*buf)[start++];
	temp[i] = '\0';
	ft_strdel(buf);
	*buf = temp;
	temp = NULL;
}

void		ft_line(char **line, char **buf, int start)
{
	char	*temp1;
	char	*temp2;

	if (!(*line))
	{
		*line = ft_strnew(start);
		*line = ft_strncpy(*line, *buf, start);
	}
	else
	{
		temp1 = ft_strnew(start);
		temp1 = ft_strncpy(temp1, *buf, start);
		temp2 = ft_strjoin(*line, temp1);
		ft_strdel(line);
		*line = temp2;
		ft_strdel(&temp1);
		temp2 = NULL;
	}
}

int			ft_gnl(const int fd, char **line, char **buf)
{
	int		ret;
	int		start;

	start = 0;
	if (!*buf)
	{
		*buf = ft_strnew(BUFF_SIZE);
		if ((ret = read(fd, *buf, BUFF_SIZE)) < 1)
		{
			ft_strdel(buf);
			return (ret);
		}
	}
	while (start < BUFF_SIZE && (*buf)[start] != '\n' && (*buf)[start] != '\0')
		start++;
	ft_line(&(*line), &(*buf), start);
	if ((*buf)[start] == '\n')
		ft_bufsub(&(*buf), start);
	else
	{
		ft_strdel(&(*buf));
		return ((*line && *line[0] == '\0') ? 0 : 2);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	t_str			*ptr;
	static t_lst	*list;

	ret = 2;
	if (fd < 0 || !(line) || BUFF_SIZE < 1)
		return (-1);
	ft_list(&list, &ptr, fd, line);
	while (ret == 2)
		ret = ft_gnl((list->lfd), line, &(list->buf));
	ptr->head = (list == ptr->head && ret == 0) ? list->next : ptr->head;
	(ptr->head == list->next && ret == 0) ? free(list) : (list = ptr->head);
	if (list == ptr->head && ret == 0)
	{
		while (list->next && list->next->lfd != fd)
			list = list->next;
		ptr->temp = list->next->next;
		free(list->next);
		list->next = ptr->temp;
		ptr->temp = NULL;
	}
	list = ptr->head;
	free(ptr);
	return (ret);
}

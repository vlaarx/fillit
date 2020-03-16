#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

int					get_next_line(const int fd, char **line);

typedef struct		s_lst
{
	char			*buf;
	int				lfd;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_str
{
	t_lst			*head;
	t_lst			*temp;
}					t_str;
#endif

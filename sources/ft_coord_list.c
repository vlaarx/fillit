#include "fillit.h"

void		ft_del_last_lst(t_indx **tetra)
{
	t_indx	*tmp;

	tmp = *tetra;
	*tetra = (*tetra)->next;
	free(tmp);
}

void		ft_coord_list(t_indx **tetra, char letter)
{
	t_indx	*new_tetra;

	if (!*tetra)
	{
		(*tetra) = (t_indx *)malloc(sizeof(t_indx));
		(*tetra)->i = 0;
		(*tetra)->j = 0;
		(*tetra)->ch = 'A';
		(*tetra)->s = 1;
		(*tetra)->next = NULL;
	}
	else
	{
		new_tetra = (t_indx *)malloc(sizeof(t_indx));
		new_tetra->next = (*tetra);
		(*tetra) = new_tetra;
		(*tetra)->s = (*tetra)->next->s + 5;
		(*tetra)->ch = letter;
		(*tetra)->i = 0;
		(*tetra)->j = 0;
		new_tetra = NULL;
	}
}
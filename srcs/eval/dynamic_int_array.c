#include "libft/ft_libft.h"
#include "eval.h"

static int	*ft_int_tab_copy_index(int **dst, int *src, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		(*dst)[i] = src[i];
		i++;
	}
	return (*dst);
}

int    *add_to_dynamic_int_array(int **table, int nbr)
{
    int     limit;
    int     i;
    int    *temp_table;

	/*the table argument needs to be already allocated with a minimum size of 5*/
	i = 0;
    limit = 5;
    while ((*table)[i] != -1)
    {
		/* index and limit incrementation whhile we're still inside the already written part*/
        if (i == limit)
            limit = limit * 2;
        i++;
    }
    if (i == limit)
    {
		/* creation of the new bigger tab and copy of the contents of the previous tab */
		limit = limit * 2;
		if (!(temp_table = ft_int_tab_maker(limit + 1)))
			return ((void*)0);
		ft_int_tab_copy_index(&temp_table, *table, i);
		free(*table);
		*table = temp_table;
    }
	/* ajout du int supplémentaire */
	(*table)[i] = nbr;
	return (*table);
}
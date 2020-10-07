#include "libft/ft_libft.h"
#include "eval.h"

static void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

static char	**ft_tab_copy_index(char ***dst, char **src, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (!((*dst)[i] = ft_strdup(src[i])))
			return (NULL);
		i++;
	}
	return (*dst);
}

void	ft_freetab_index(char ***tab, int index)
{
	int i;

	i = index;
	while (--i >= 0)
		ft_strdel(&((*tab)[i]));
	free(*tab);
	tab = NULL;
}

char    **add_to_dynamic_table(char ***table, char *str)
{
    int     limit;
    int     i;
    char    **temp_table;

	/*the table argument needs to be already allocated with a minimum size of 5*/
	i = 0;
    limit = 5;
    while ((*table)[i])
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
		if (!(temp_table = ft_stabmaker(limit + 1)))
			return (NULL);
		ft_tab_copy_index(&temp_table, *table, i);
		ft_freetab_index(table, i);
		*table = temp_table;
    }
	/* ajout de la string supplémentaire */
	if (!((*table)[i] = ft_strdup(str)))
		return (NULL);
	return (*table);
}
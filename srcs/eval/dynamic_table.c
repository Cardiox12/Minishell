#include "libft/ft_libft.h"

static void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

static void	ft_printtab(char **tab)
{
	int i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			ft_printf("tab[%d] : %s\n", i, tab[i]);
			i++;
		}
	}
}

static char			**ft_stabmaker(size_t len)
{
	char			**stab;
	unsigned int	i;

	i = 0;
	if (!(stab = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		stab[i] = 0;
		i++;
	}
	stab[i] = 0;
	return (stab);
}

static char	**ft_tab_copy(char ***dst, char **src, int index)
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
		ft_tab_copy(&temp_table, *table, i);
		ft_freetab_index(table, i);
		*table = temp_table;
    }
	/* ajout de la string supplémentaire */
	if (!((*table)[i] = ft_strdup(str)))
		return (NULL);
}

int		main(int ac, char **av)
{
	int		i;
	char	**table;

	i = 1;
	if (!(table = ft_stabmaker(5 + 1)))
		return (-1);
	while (i < ac)
	{
		add_to_dynamic_table(&table, av[i]);
		i++;
	}
	ft_printtab(table);
	ft_freetab_index(&table, i);
	return (0);
}
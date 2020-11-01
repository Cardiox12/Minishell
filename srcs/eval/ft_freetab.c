#include "eval.h"

void	ft_freetab(char ***tab)
{
	int i;

	i = ft_tablen(*tab);
	while (--i >= 0)
		ft_strdel(&((*tab)[i]));
	free(*tab);
	tab = NULL;
}

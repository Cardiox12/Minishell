#include "libft/ft_libft.h"

void     ft_printtab(char **tab)
{
        int i;

		ft_printf("\n           -- tab: --        \n");
        i = 0;
        if (tab != NULL)
        {
                while (tab[i])
                {
                        ft_printf("tab[%d] : %s\n", i, tab[i]);
                        i++;
                }
        }
		ft_printf("              ----           \n");
}

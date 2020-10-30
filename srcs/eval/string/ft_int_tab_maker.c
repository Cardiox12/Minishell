#include "eval.h"

int                     *ft_int_tab_maker(size_t len)
{
        int                    *int_tab;
        unsigned int    i;

        i = 0;
        if (!(int_tab = (int*)malloc(sizeof(int) * (len + 1))))
                return (NULL);
        while (i < len)
        {
                int_tab[i] = -1;
                i++;
        }
        int_tab[i] = -1;
        return (int_tab);
}

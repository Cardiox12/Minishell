#include "eval.h"

char                     **ft_stabmaker(size_t len)
{
        char                    **stab;
        unsigned int    i;

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

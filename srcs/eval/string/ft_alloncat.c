#include "eval.h"

char	*ft_alloncat(char **s1, const char *s2, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*s1)[i] != '\0')
		i++;
	while (s2[j] && (j < len))
	{
		(*s1)[i] = s2[j];
		i++;
		j++;
	}
	(*s1)[i] = '\0';
	return (*s1);
}
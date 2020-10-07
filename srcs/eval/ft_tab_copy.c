#include "../../includes/eval.h"
#include "libft/ft_libft.h"

char	**ft_tab_copy(char ***dst, char **src)
{
	int		i;
	int		len;

	i = 0;
	len = ft_tablen(src);
	if (!(*dst = ft_stabmaker(len)))
		return (NULL);
	while (src[i])
	{
		if (!((*dst)[i] = ft_strdup(src[i])))
			return (NULL);
		i++;
	}
	return (*dst);
}
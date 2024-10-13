#include "cub3d.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char	*ft_strdup(char *str)
{
	char	*res;
	int		i;

	i = -1;
	while (str[++i])
		i++;
	res = my_malloc((i + 1) * sizeof (char), 0);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = 0;
	return (res);
}
#include "cub3d.h"

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

char	*gnl(int fd)
{
    char		line[70000];
    static char	buff[BUFFER_SIZE];
	static int	buff_pos;
	static int	buff_read;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	i = 0;
	while (1)
	{
		if (buff_pos >= buff_read)
		{
			buff_read = read(fd, buff, BUFFER_SIZE);
			buff_pos = 0;
			if (buff_read <= 0)
				return (NULL);
		}
		line[i++] = buff[buff_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = 0;
	return (ft_strdup(line));
}

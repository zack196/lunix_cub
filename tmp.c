#include "cub3d.h"


void	sizing_map(t_cub *cub)
{
    int		i;
    char	**map;

	map = cub->map;
	cub->width_map = 0;
    i = 0;
    while (map[i])
	{
		if (cub->width_map < (int)ft_strlen(map[i]))
			cub->width_map = ft_strlen(map[i]);
		i++;
	}
	cub->height_map = i;
}


char    **tmp_map()
{
    char    **map;

    map = my_malloc(sizeof (char *) * 13, 0);
    map[0] = ft_strdup("11111111111111111111111111111111111");
    map[1] = ft_strdup("11111100000000000001000000000000111");
    map[2] = ft_strdup("111111000000N0000001000000000000111");
    map[3] = ft_strdup("11111100000000000001000000000000111");
    map[4] = ft_strdup("11111100000000000001000000000000111");
    map[5] = ft_strdup("111111111111100111111111111001111111");
    map[6] = ft_strdup("11111100000000000001000000000000000111");
    map[7] = ft_strdup("11111100000000000001000000000000111");
    map[8] = ft_strdup("11111100000000000001000000000000111");
    map[9] = ft_strdup("11111000000000000000000000000000111");
    map[10] = ft_strdup("11111111111111111111111111111111111");
    map[11] = ft_strdup("11111111111111111111111111111111111");
    map[2] = NULL;
	// map[0] = ft_strdup("0110100000001111111111111100000000010");
	// map[1] = ft_strdup("1000000000111111111111110000000001001");
	// map[2] = ft_strdup("1001111111111111111000111111111111111");
	// map[3] = ft_strdup("1001111110100101100101100101010101001");
	// map[4] = ft_strdup("0100000111111000001011111111111111110");
	// map[5] = NULL;
    return (map);
}

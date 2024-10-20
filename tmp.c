#include "cub3d.h"

char    **tmp_map(t_cub *cub)
{
    char    **map;

    map = my_malloc(sizeof (char *) * 12, 0);
    map[0] = ft_strdup("11111100000000000000000000000000000000000");
    map[1] = ft_strdup("11111100000000000000000000000000000000000");
    map[2] = ft_strdup("11111100000000000000000000000000000000000");
    map[3] = ft_strdup("11111100000000000000000000000000000000000");
    map[4] = ft_strdup("11111100000000000000000000000000000000000");
    map[5] = ft_strdup("11111100000000000000000000000000000000000");
    map[6] = ft_strdup("11111100000000000000000000000000000000000");
    map[7] = ft_strdup("11111100000000000000000000000000000000000");
    map[8] = ft_strdup("11111100000000000000000000000000000000000");
    map[9] = ft_strdup("11111100000000000000000000000000000000000");
    map[10] =ft_strdup("11111100000000000000000000000000000000000");
    map[11] = NULL;
    cub->height_map = 10;
    cub->width_map = 0;
    int i = 0;
    while (map[i])
    {
        if ((int)ft_strlen(map[i]) > cub->width_map)
            cub->width_map = ft_strlen(map[i]);
        i++;
    }
    return (map);
}

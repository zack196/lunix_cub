/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:34 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/10/28 16:13:30 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	printf("width = %d and height = %d\n", cub->width_map, cub->height_map);
}


char	**tmp_map()
{
	char	**map;

	map = my_malloc(sizeof (char *) * 13, 0);
	map[0] = ft_strdup("111111111111111111111111111111111111");
	map[1] = ft_strdup("110000000000000000000000000000000111");
	map[2] = ft_strdup("110111000000000000000000000000001111");
	map[3] = ft_strdup("11011100000000N000001000000000001111");
	map[4] = ft_strdup("110011000000000000000000000000000111");
	map[5] = ft_strdup("110000011111101111111111111101111111");
	map[6] = ft_strdup("110011111111101111111111111101111111");
	map[7] = ft_strdup("110011000000000000010000000000000111");
	map[8] = ft_strdup("111011000000000000000000000000000111");
	map[9] = ft_strdup("111010000000000000010000000000000111");
	map[10] =ft_strdup("111000000000000000010000000000000111");
	map[11] =ft_strdup("111111111111111111111111111111111111");
	map[12] = NULL;

	return (map);
}

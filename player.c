/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:00:58 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/10/28 16:14:10 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player(t_cub *cub, int x, int y)
{
	if (cub->map[x][y] == 'N')
		return (1);
	else if (cub->map[x][y] == 'S')
		return (1);
	else if (cub->map[x][y] == 'E')
		return (1);
	else if (cub->map[x][y] == 'W')
		return (1);
	else
		return (0);
}



void	init_rot_player(t_cub *cub, int x_map, int y_map)
{
	if (cub->map[x_map][y_map] == 'N')
		cub->player->player_rot = 3 * M_PI / 2;
	else if (cub->map[x_map][y_map] == 'S')
		cub->player->player_rot = 1 * M_PI / 2;
	else if (cub->map[x_map][y_map] == 'W')
		cub->player->player_rot = 2 * M_PI / 2;
	else if (cub->map[x_map][y_map] == 'E')
		cub->player->player_rot = 0 * M_PI / 2;
}

void	init_player(t_cub *cub)
{
	int	x_map;
	int	y_map;

	x_map = -1;
	while (cub->map[++x_map])
	{
		y_map = -1;
		while (cub->map[x_map][++y_map])
			if (check_player(cub, x_map, y_map))
				break ;
		if (check_player(cub, x_map, y_map))
			break ;
	}
	cub->player = my_malloc(sizeof (t_player), 0);
	init_rot_player(cub, x_map, y_map);
	cub->player->x_player = x_map * cub->h_tile_size + cub->h_tile_size / 2;
	cub->player->y_player = y_map * cub->v_tile_size + cub->v_tile_size / 2;
	cub->player->x_map_player = x_map;
	cub->player->y_map_player = y_map;
}



void	render_player(t_cub *cub)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = - 1;
		while (++y < HEIGHT)
		{
			if ((x - cub->player->y_player) * (x - cub->player->y_player) +
				(y - cub->player->x_player) * (y - cub->player->x_player) < 36)
				my_mlx_pixel_put(&cub->image, x, y, 0X000000);
		}
	}
	// draw_rot_line(cub);
	cast_rays(cub);
	render_ray(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image.img, 0, 0);
}

void draw_rot_line(t_cub *cub)
{
    t_player *player = cub->player;

    // Calculate end coordinates using player rotation
    float x_end = player->x_player + 30 * cos(player->player_rot);
    float y_end = player->y_player + 30 * sin(player->player_rot);

    // Calculate step size for smooth line
	float x_step = x_end - player->x_player;
	float y_step = y_end - player->y_player;
	x_step /= 30;
	y_step /= 30;

	// Initialize starting point
	float x = player->x_player;
	float y = player->y_player;

	// Draw line segment
	for (int i = 0; i < 30; i++)
	{
		my_mlx_pixel_put(&cub->image, (int)y, (int)x, 0x000000);
		x += x_step;
		y += y_step;
	}
}

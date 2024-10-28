#include "cub3d.h"

int	check_map(t_cub *cub, int x, int y)
{
	if (x >= cub->height_map)
		return (0);
	if (y >= cub->width_map)
	{
		return (0);
	}
	if (y > (int)ft_strlen(cub->map[x]))
	{
		return (0); 
	}
	return (1);
}

void	render_map(t_cub *cub)
{
	int	i;
	int	j;
	int	x_map_cord;
	int	y_map_cord;

	cub->h_tile_size = HEIGHT / cub->height_map;
	cub->v_tile_size = WIDTH / cub->width_map;
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			x_map_cord = j / cub->h_tile_size;
			y_map_cord = i / cub->v_tile_size;
			if (check_map(cub, x_map_cord, y_map_cord)
				&& (cub->map[x_map_cord][y_map_cord] == '0'
				|| check_player(cub, x_map_cord, y_map_cord)))
				my_mlx_pixel_put(&cub->image, i, j, 0XFFFFFF);
			else
				my_mlx_pixel_put(&cub->image, i, j, 0XAAEEAA);
		}
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image.img, 0, 0);
}

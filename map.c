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

int	is_wall(t_cub *cub, int x, int y)
{
	int	x_map_cord;
	int	y_map_cord;

	x_map_cord = y / cub->h_tile_size;
	y_map_cord = x / cub->v_tile_size;
	if (!check_map(cub, x_map_cord, y_map_cord))
		return (1);
	if (cub->map[x_map_cord][y_map_cord] == '1')
		return (1);
	return (0);
}

void	render_map(t_cub *cub)
{
	int	x;
	int	y;
	
	x = -1;
	cub->h_tile_size = HEIGHT / cub->height_map;
	cub->v_tile_size = WIDTH / cub->width_map;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (x % cub->v_tile_size == 0 || y % cub->h_tile_size == 0)
				my_mlx_pixel_put(&cub->image, x, y, 0XA1B2C3);
			else if (is_wall(cub, x, y))
				my_mlx_pixel_put(&cub->image, x, y, 0XAAE3AA);
			else
				my_mlx_pixel_put(&cub->image, x, y, 0XFFFFFF);
		}
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image.img, 0, 0);
}

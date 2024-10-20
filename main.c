#include "cub3d.h"

int	clean_all(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->image.img);
	mlx_destroy_window(cub->mlx, cub->mlx_win);
	mlx_destroy_display(cub->mlx);
	my_free();
	exit(0);
	return (0);
}

int	handel_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (1);
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub");// x = width and y = height
	if (!cub->mlx_win)
		return (mlx_destroy_display(cub->mlx), 1);
	cub->image.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	// check if the mlx_new_image
	cub->image.addr = mlx_get_data_addr(cub->image.img
		, &cub->image.bits_per_pixel, &cub->image.line_length
		, &cub->image.endian);
	mlx_hook(cub->mlx_win, 17, 0L, clean_all, cub);

	// mlx_loop_hook(cub->mlx, );
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	check_map(t_cub *cub, int x, int y)
{
	if (x >= cub->height_map)
	{
		return (1);
	}
	if ((int)ft_strlen(cub->map[x]) < y)
	{
		return (1);
	}
	return (0);
}

void	render_cub(t_cub *cub)
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
			x_map_cord = i / cub->v_tile_size;
			y_map_cord = j / cub->h_tile_size;
			if (check_map(cub, x_map_cord, y_map_cord))
				my_mlx_pixel_put(&cub->image, j, i , 0X23F12A);
			else if (cub->map[x_map_cord][y_map_cord] == '0')
				my_mlx_pixel_put(&cub->image, j, i , 0X98A321);
			else if (cub->map[x_map_cord][y_map_cord] == '1')
				my_mlx_pixel_put(&cub->image, j, i , 0X23F12A);
			else 
				my_mlx_pixel_put(&cub->image, j, i , 0X23F12A);
		}
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image.img, 0, 0);
}
int	main()
{
    t_cub	cub;

    cub.map = tmp_map(&cub);
	if (handel_mlx(&cub))
		return (my_free(), 1);
	render_cub(&cub);
	mlx_loop(cub.mlx);
	my_free();
}
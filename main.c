#include "cub3d.h"

int	clean_all(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->image.img);
	mlx_destroy_window(cub->mlx, cub->mlx_win);
	// mlx_destroy_display(cub->mlx);
	mlx_loop_end(cub->mlx);
	my_free();
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

	if (x > cub->height_map || y >cub->width_map)
		return (0);
	if (y > (int)ft_strlen(cub->map[x]))
		return (0); 
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
			// printf("y_map = %d x_map = %d\n", y_map_cord, x_map_cord);
			if (check_map(cub, x_map_cord, y_map_cord)
				&& cub->map[x_map_cord][y_map_cord] == '0')
			{
				// printf("in\n");
				my_mlx_pixel_put(&cub->image, i, j, 0XFFFFFF);
			}
			// else
			// 	my_mlx_pixel_put(&cub->image, i, j, 0XFEA091);
		}
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image.img, 0, 0);
}

int	check_player(t_cub *cub, int x, int y)
{
	if (cub->map[x][y] == 'N')
		return (1);
	if (cub->map[x][y] == 'S')
		return (1);
	if (cub->map[x][y] == 'E')
		return (1);
	if (cub->map[x][y] == 'W')
		return (1);
	return (0);
}

void	render_player(t_cub *cub)
{
	int	x_map;
	int	y_map;
	int	i;
	int	j;

	x_map = -1;
	y_map = -1;
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
	cub->player->x_player = x_map * cub->h_tile_size + cub->h_tile_size / 2;
	cub->player->y_player = y_map * cub->v_tile_size + cub->v_tile_size / 2;
	i = y_map * cub->v_tile_size - 1;
	while (++i < (y_map + 1) * cub->v_tile_size)
	{
		j = x_map * cub->h_tile_size - 1;
		while (++j < (x_map + 1) * cub->h_tile_size)
		{
			if ((i - cub->player->y_player) * (i - cub->player->y_player) + 
				(j - cub->player->x_player) * (j - cub->player->x_player) < 100)
				my_mlx_pixel_put(&cub->image, i, j, 0XAF4184);
			else
				my_mlx_pixel_put(&cub->image, i, j, 0XFFFFFF);
		}
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image.img
	, 0, 0);
}

int	main()
{
    t_cub	cub;

    cub.map = tmp_map(&cub);
	sizing_map(&cub);
	if (handel_mlx(&cub))
		return (my_free(), 1);	
	render_map(&cub);
	render_player(&cub);
	mlx_loop(cub.mlx);
	my_free();
}
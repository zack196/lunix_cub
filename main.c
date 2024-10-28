/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:29 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/10/28 16:27:50 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clean_all(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->image.img);
	mlx_destroy_window(cub->mlx, cub->mlx_win);
	// mlx_destroy_display(cub->mlx);
	my_free();
	
	exit(0);
	return (0);
}

int	handel_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (1);
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub");
	if (!cub->mlx_win)
		return (/*mlx_destroy_display(cub->mlx), */1);
	cub->image.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	// check if the mlx_new_image
	cub->image.addr = mlx_get_data_addr(cub->image.img
		, &cub->image.bits_per_pixel, &cub->image.line_length
		, &cub->image.endian);
	mlx_hook(cub->mlx_win, 17, 0L, clean_all, cub);
	mlx_hook(cub->mlx_win, 02, (1L<<0), key_press, cub);
	mlx_hook(cub->mlx_win, 03, (1L<<1), key_release, cub);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main()
{
	t_cub	cub;

	cub.map = tmp_map(&cub);
	sizing_map(&cub);
	if (handel_mlx(&cub))
		return (my_free(), 1);
	render_map(&cub);
	init_player(&cub);
	cast_rays(&cub);
	render_player(&cub);
	mlx_loop(cub.mlx);
	my_free();
}

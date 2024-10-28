#include "cub3d.h"

void	cast_rays(t_cub *cub)
{
	int		i;
	float	angle;

    cub->player->rays = my_malloc(NBR_RAYS * sizeof (t_ray), 0);
	i = -1;
	angle = -(FOV_ANGLE / 2 - cub->player->player_rot);
	while (++i < NBR_RAYS)
	{
		cub->player->rays[i].angle = angle;
		angle += FOV_ANGLE / NBR_RAYS;
	}	
}

void	draw_line(t_cub *cub, float rotation, float distance)
{
	float	x_end;
	float	y_end;
    float	x;
    float	y;
    int		i;

	x_end = cub->player->y_player + cos(rotation) * distance;
	y_end = cub->player->x_player + sin(rotation) * distance;
	x = cub->player->y_player;
	y = cub->player->x_player;
	i = -1;
	while (++i < (int)distance)
	{
		my_mlx_pixel_put(&cub->image, (int)x, (int)y, 0X000000);
		x += cos(rotation) * distance / distance;
		y += sin(rotation) * distance / distance;
	}
}


// void	draw_line(t_cub *cub, float rotation, float distance)
// {
// 	int x1 = (int)cub->player->y_player;
// 	int y1 = (int)cub->player->x_player;
// 	int x2 = (int)(cub->player->y_player + cos(rotation) * distance);
// 	int y2 = (int)(cub->player->x_player + sin(rotation) * distance);
// 	int dx = abs(x2 - x1);
// 	int dy = abs(y2 - y1);
// 	int sx = (x1 < x2) ? 1 : -1;
// 	int sy = (y1 < y2) ? 1 : -1;
// 	int err = dx - dy;
// 	while (1)
// 	{
// 		my_mlx_pixel_put(&cub->image, x1, y1, 0X000000);
// 		if (x1 == x2 && y1 == y2)
// 			break;
// 		int e2 = 2 * err;
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			x1 += sx;
// 		}
// 		if (e2 < dx)
// 		{
// 			err += dx;
// 			y1 += sy;
// 		}
// 	}
// }

void	render_ray(t_cub *cub)
{
	int		i;

	i = -1;
	while (++i < NBR_RAYS)
        draw_line(cub, cub->player->rays[i].angle, 30);
}

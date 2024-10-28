#include "cub3d.h"

void	cast_rays(t_cub *cub)
{
	int		i;
	float	angle;

    cub->player->rays = my_malloc(NBR_RAYS * sizeof (t_ray), 0);
	i = 0;
	angle = -(FOV_ANGLE / 2 - cub->player->player_rot);
	while (++i < NBR_RAYS)
	{
		cub->player->rays[i].angle = angle;
		cub->player->x_player = cub->player->x_player;
		cub->player->y_player = cub->player->y_player;
		angle += FOV_ANGLE / NBR_RAYS;
	}	
}

void    draw_line(t_cub *cub, float rotation, float distance)
{
	float	x_end;
	float	y_end;
    float   x;
    float   y;
    int     i;

    x_end = cub->player->x_player + cos(rotation) * distance;
	y_end = cub->player->y_player + sin(rotation) * distance;
    x = cub->player->x_player;
    y = cub->player->y_player;
    i = -1;
    while (++i < (int)distance)
    {
        my_mlx_pixel_put(&cub->image, (int)x, (int)y, 0X000000);
        x += cos(rotation) * distance / 30;
        y += sin(rotation) * distance / 30;
    }
}

void	render_ray(t_cub *cub)
{
	int		i;

	i = -1;
	while (++i < NBR_RAYS)
        draw_line(cub, cub->player->rays[i].angle, 30);
}

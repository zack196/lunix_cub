/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:57:39 by zel-oirg           #+#    #+#             */
/*   Updated: 2024/10/29 20:57:40 by zel-oirg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


float	normalise_tan(float angle)
{
	while (angle > M_PI /2)
		angle -= M_PI / 2;
	return (angle);
}

void	found_horizontal_wall_hit(t_ray *ray, t_cub *cub)
{
	float	x_intersection;
	float	y_intersection;
	float	x_step;
	float	y_step;

	x_intersection = (cub->player->x_player / cub->h_tile_size + ray->is_facing_down) * cub->h_tile_size;
	y_intersection = cub->player->y_player
		+ (cub->player->x_player - x_intersection) / tan(ray->angle); 
	
	x_step = cub->h_tile_size;
	if (ray->is_facing_up)
		x_step = -x_step;
	
	y_step = x_step / tan(ray->angle);
	if (ray->is_facing_left)
		y_step *= -1;
	
	// while (1)
	// {
	// 	if (is_wall(cub, x_intersection - ray->is_facing_down + ray->is_facing_up, y_intersection))
	// 	{
	// 		break ;
	// 	}
		x_intersection += x_step;
		y_intersection += y_step;
	// }
	
			// printf("(%f, %f)\n", x_intersection / cub->h_tile_size, y_intersection / cub->v_tile_size);
	ray->x_horizontal_wall_hit = x_intersection;
	ray->y_horizontal_wall_hit = y_intersection;
	
	(void)ray;
	(void)cub;
}

void	found_vertical_wall_hit(t_ray *ray, t_cub *cub)
{
	(void)ray;
	(void)cub;
}

void	ray_is_facing(t_ray *ray)
{
	ray->is_facing_right = 0;
	if ((0 < ray->angle && ray->angle < M_PI / 2)
		|| (3 *M_PI / 2 < ray->angle && ray->angle < 2 * M_PI))
		ray->is_facing_right = 1;
	ray->is_facing_left = !ray->is_facing_right;
	ray->is_facing_down = 0;
	if (0 < ray->angle && ray->angle < M_PI)
		ray->is_facing_down = 1;	
}

void	cast_rays(t_cub *cub)
{
	int		i;
	float	angle;

	i = -1;
	angle = cub->player->player_rot - FOV_ANGLE / 2;
	while (++i < 1)//NBR_RAYS)
	{
		cub->player->rays[i].angle = normalize_angle(angle);
		ray_is_facing(&cub->player->rays[i]);
		found_horizontal_wall_hit(&cub->player->rays[i], cub);
		found_vertical_wall_hit(&cub->player->rays[i], cub);
		angle += FOV_ANGLE / NBR_RAYS;
	}	
}

// void	draw_line(t_cub *cub, int x_end, int y_end)
// {
// 	int x1 = (int)cub->player->y_player;
// 	int y1 = (int)cub->player->x_player;
// 	int x2 = x_end;
// 	int y2 = y_end;
// 	if (x2 < 0 || x2 > WIDTH || y2 < 0 || y2 > HEIGHT)
// 		return ;
// 	// printf("x_end = %d and y_end = %d\n", x2, y2);
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

void	draw_line(t_cub *cub, int x_end, int y_end, int color)
{
	int x1 = (int)cub->player->y_player;
	int y1 = (int)cub->player->x_player;
	int x2 = x_end;
	int y2 = y_end;

	// Ensure the endpoints are within bounds
	if ((x1 < 0 || x1 >= WIDTH || y1 < 0 || y1 >= HEIGHT) || 
	    (x2 < 0 || x2 >= WIDTH || y2 < 0 || y2 >= HEIGHT))
		return ;

	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		// Plot the current pixel if within bounds
		if (x1 >= 0 && x1 < WIDTH && y1 >= 0 && y1 < HEIGHT)
			my_mlx_pixel_put(&cub->image, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}



void	render_ray(t_cub *cub)
{
	int		i;

	i = -1;
	while (++i < 1)//NBR_RAYS)
	{	
		// if (cub->player->rays[i].angle != M_PI / 2 
		// 	&& cub->player->rays[i].angle != 3 * M_PI / 2)
	        draw_line(cub, (int)cub->player->rays[i].x_horizontal_wall_hit
			, (int)cub->player->rays[i].y_horizontal_wall_hit, 0);
	}
}

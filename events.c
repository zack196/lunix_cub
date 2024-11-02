#include "cub3d.h"

// void	update_player(t_cub *cub, int up_down, int right_left, int turn)
// {
// 	int		y_map_player;
// 	int		x_map_player;
// 	float	x_player;
// 	float	y_player;
// 	float	x_step;
// 	float	y_step;

// 	x_step = 10 * right_left;
// 	y_step = -10 * up_down;
// 	x_player = cub->player->x_player + (y_step) * cos(cub->player->player_rot);
// 	y_player = cub->player->y_player + (y_step) * sin(cub->player->player_rot);
// 	x_player = x_player + y_step * sin(cub->player->player_rot + M_PI / 2);
// 	y_player = y_player + x_step * cos(cub->player->player_rot + M_PI / 2);
// 	cub->player->player_rot += turn * (6 * M_PI / 180);
// 	x_map_player = (int)x_player / cub->h_tile_size;
// 	y_map_player = (int)y_player / cub->v_tile_size;
// 	if (cub->map[x_map_player][y_map_player] != '1')
// 	{
// 		cub->player->x_player = (int)x_player;
// 		cub->player->y_player = (int)y_player;
// 	}
// }

void	update_player(t_cub *cub, int up_down, int right_left, int turn)
{
	float	x_new_pos;
	float	y_new_pos;

	x_new_pos = 0;
	y_new_pos = 0;
	if (up_down)
	{
		x_new_pos =
			cub->player->x_player + up_down * sin(cub->player->player_rot) * 5;
		y_new_pos =
			cub->player->y_player + up_down * cos(cub->player->player_rot) * 5;
	}
	else if (right_left)
	{
		x_new_pos = cub->player->x_player + right_left * cos(cub->player->player_rot) * 5;
		y_new_pos = cub->player->y_player - right_left * sin(cub->player->player_rot) * 5;
	}
	else if (turn)
		cub->player->player_rot = normalize_angle(turn * (3 * M_PI / 180) + cub->player->player_rot);
	if ((up_down || right_left) && !is_wall(cub, y_new_pos, x_new_pos))
	{
		cub->player->x_player = (int)x_new_pos;
		cub->player->y_player = (int)y_new_pos;
	}
}

int	key_press(int keycode, t_cub *cub)
{
	int	up_down;
	int	right_left;
	int turn;

	up_down = 0;
	right_left = 0;
	turn = 0;
	if (keycode == 97)//0)//a
		right_left = -1;
	else if (keycode == 115)//1)//s
		up_down = -1;
	else if (keycode == 100)//2)//d
		right_left = 1;
	else if (keycode == 119)//13)//w
		up_down = 1;
	else if (keycode == 65361)//123)
		turn -= 1;
	else if (keycode == 65363)//124)
		turn -= -1;
	update_player(cub, up_down, right_left, turn);
	render_map(cub);
	render_player(cub);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	(void)keycode;
	render_map(cub);
	render_player(cub);
	return (0);
}

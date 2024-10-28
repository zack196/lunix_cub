#include "cub3d.h"

void	update_player(t_cub *cub, int up_down, int right_left, int turn)
{
	int		y_map_player;
	int		x_map_player;
	float	x_player;
	float	y_player;
	float	x_step;
	float	y_step;

	x_step = 10 * right_left;
	y_step = -10 * up_down;
	x_player = cub->player->x_player + (x_step) * cos(cub->player->player_rot);
	y_player = cub->player->y_player + (x_step) * sin(cub->player->player_rot);
	x_player = x_player + (y_step) * cos(cub->player->player_rot + M_PI / 2);
	y_player = y_player + (y_step) * sin(cub->player->player_rot + M_PI / 2);
	cub->player->player_rot += turn * (6 * M_PI / 180);
	x_map_player = (int)x_player / cub->h_tile_size;
	y_map_player = (int)y_player / cub->v_tile_size;
	if (cub->map[x_map_player][y_map_player] != '1')
	{
		cub->player->x_player = (int)x_player;
		cub->player->y_player = (int)y_player;
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
	if (keycode == 0)//a
		right_left = -1;
	else if (keycode == 1)//s
		up_down = -1;
	else if (keycode == 2)//d
		right_left = 1;
	else if (keycode == 13)//w
		up_down = 1;
	else if (keycode == 123)
		turn += 3;
	else if (keycode == 124)
		turn += -3;
	update_player(cub, right_left, up_down, turn);
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

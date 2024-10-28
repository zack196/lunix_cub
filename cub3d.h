/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <zel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:35:48 by zel-oirg          #+#    #+#             */
/*   Updated: 2024/10/27 18:01:58 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include <stdlib.h>

# define HEIGHT 1000
# define WIDTH 1900
# define WALL_STRIP_WIDTH 1
# define FOV_ANGLE 60 * (M_PI / 180)
# define NBR_RAYS  WIDTH / WALL_STRIP_WIDTH

typedef struct s_gdata
{
    void			*data;
    struct s_gdata	*next;
}   t_gdata;

void	*my_malloc(size_t size, int free_mode);
void	my_free(void);

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_ray
{
	float	angle;
	int		x_player;
	int		y_player;
}	t_ray;

typedef struct s_player
{
	int		x_player;
	int		y_player;
	int		x_map_player;
	int		y_map_player;
	float	player_rot;
	t_ray	*rays;
}	t_player;

typedef struct s_cub
{
	char		**map;
	void		*mlx;
	void		*mlx_win;
	t_data		image;
	int			width_map;
	int			height_map;
	int			h_tile_size;
	int			v_tile_size;
	t_player	*player;
}	t_cub;

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	sizing_map(t_cub *cub);
void	render_player(t_cub *cub);
void	render_map(t_cub *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_player(t_cub *cub);
void	draw_rot_line(t_cub *cub);
void	update_player(t_cub *cub, int up_down, int right_left, int turn);
int		key_hook(int keycode, t_cub *cub);
int		check_player(t_cub *cub, int x, int y);
int		key_release(int keycode, t_cub *cub);
int		key_press(int keycode, t_cub *cub);
int		clean_all(t_cub *cub);
void	cast_rays(t_cub *cub);


/*tmp function*/
char	**tmp_map();

#endif
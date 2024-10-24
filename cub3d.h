/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:08:29 by zel-oirg           #+#    #+#             */
/*   Updated: 2024/10/19 12:08:30 by zel-oirg          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include <unistd.h>
# include <stdio.h>
# include "mlx.h"
# include <stdlib.h>

#define HEIGHT 600
#define WIDTH 1600

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

typedef struct s_player
{
	int		x_player;
	int		y_player;
	float	player_rot;

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




char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		clean_all(t_cub *cub);
void	sizing_map(t_cub *cub);


/*tmp function*/
char    **tmp_map();
#endif
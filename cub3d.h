#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 99
#endif

typedef struct s_gdata
{
    void			*data;
    struct s_gdata	*next;
}	t_gdata;

typedef struct s_cub
{
    char    *texture_no;
    char    *texture_so;
    char    *texture_we;
    char    *texture_ea;
    int     F_COLOR;
    int     C_COLOR;
    char    **maps;
}   t_cub;

void    *my_malloc(size_t size, int free_mode);
char	*gnl(int fd);
#endif
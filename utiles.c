#include "cub3d.h"

float	normalize_angle(float angle)
{
	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	while (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

float	distance_2ptn(float A_x, float A_y, float B_x, float B_y)
{
	return (sqrt((A_x - B_x) * (A_x - B_x) + (B_y - A_y) * (B_y - A_y)));
}
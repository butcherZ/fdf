#include "mlx.h"
#include "fdf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	scale(t_iso *iso, int factor)
{
	iso->x = iso->x * factor;
	iso->y = iso->y * factor;
}
void	rotation_x(t_mlx *map, t_iso *iso)
{
		MATRIX m;

		m[0][0] = 1.0;   m[0][1] = 0.0;  m[0][2] = 0.0; m[0][3] = 0.0;
		m[1][0] = 0.0;   m[1][1] = cos(degToRad(map->fac.rotation_x));  m[1][2] = -sin(degToRad(map->fac.rotation_x)); m[1][3] = 0;
		m[2][0] = 0.0;	 m[2][1] = sin(degToRad(map->fac.rotation_x));  m[2][2] = cos(degToRad(map->fac.rotation_x));	m[2][3] = 1.0;
		m[3][0] = 0.0;	 m[3][1] = 0.0;  m[3][2] = 0.0; m[3][3] = 1.0;

		int transformedX, transformedY, transformedZ;

		transformedX = (int) (iso->x * m[0][0] + iso->y * m[0][1] + iso->z * m[0][2] + m[0][3]);
		transformedY = (int) (iso->x * m[1][0] + iso->y * m[1][1] + iso->z * m[1][2] + m[1][3]);
		transformedZ = (int) (iso->x * m[2][0] + iso->y * m[2][2] + iso->z * m[2][2] + m[2][3]);

		iso->x = transformedX;
		iso->y = transformedY;
		iso->z = transformedZ;

}

void	rotation_y(t_mlx *map, t_iso *iso)
{
		MATRIX m;

		m[0][0] = cos(degToRad(map->fac.rotation_y));   m[0][1] = 0.0;  m[0][2] = sin(degToRad(map->fac.rotation_y)); m[0][3] = 0.0;
		m[1][0] = 0.0;   m[1][1] = 1.0;  m[1][2] = 0.0; m[1][3] = 0.0;
		m[2][0] = -sin(degToRad(map->fac.rotation_y));	 m[2][1] = 0.0;  m[2][2] = cos(degToRad(map->fac.rotation_y));	m[2][3] = 1.0;
		m[3][0] = 0.0;	 m[3][1] = 0.0;  m[3][2] = 0.0; m[3][3] = 1.0;

		int transformedX, transformedY, transformedZ;

		transformedX = (int) (iso->x * m[0][0] + iso->y * m[0][1] + iso->z * m[0][2] + m[0][3]);
		transformedY = (int) (iso->x * m[1][0] + iso->y * m[1][1] + iso->z * m[1][2] + m[1][3]);
		transformedZ = (int) (iso->x * m[2][0] + iso->y * m[2][2] + iso->z * m[2][2] + m[2][3]);

		iso->x = transformedX;
		iso->y = transformedY;
		iso->z = transformedZ;

}
void	rotation_z(t_mlx *map, t_iso *iso)
{
		MATRIX m;
		m[0][0] = cos(degToRad(map->fac.rotation_z));   m[0][1] = -sin(degToRad(map->fac.rotation_z));  m[0][2] = 0.0; m[0][3] = 0.0;
		m[1][0] = sin(degToRad(map->fac.rotation_z));  m[1][1] = cos(degToRad(map->fac.rotation_z));;  m[1][2] = 0.0; m[1][3] = 0.0;
		m[2][0] = 0.0;	 m[2][1] = 0.0;  m[2][2] = 0.0; m[2][3] = 1.0;
		m[3][0] = 0.0;	 m[3][1] = 0.0;  m[3][2] = 0.0; m[3][3] = 1.0;

		int transformedX, transformedY, transformedZ;

		transformedX = (int) (iso->x * m[0][0] + iso->y * m[0][1] + iso->z * m[0][2] + m[0][3]);
		transformedY = (int) (iso->x * m[1][0] + iso->y * m[1][1] + iso->z * m[1][2] + m[1][3]);
		transformedZ = (int) (iso->x * m[2][0] + iso->y * m[2][2] + iso->z * m[2][2] + m[2][3]);

		iso->x = transformedX;
		iso->y = transformedY;
		iso->z = transformedZ;

}

void	translation(t_mlx *map, t_iso *iso)
{
		MATRIX m;
		m[0][0] = 1.0;   m[0][1] = 0.0;  m[0][2] = 0.0; m[0][3] = map->fac.translation_x;
		m[1][0] = 0.0;   m[1][1] = 1.0;  m[1][2] = 0.0; m[1][3] = map->fac.translation_y;
		m[2][0] = 0.0;	 m[2][1] = 0.0;  m[2][2] = 1.0;	m[2][3] = map->fac.translation_z;
		m[3][0] = 0.0;	 m[3][1] = 0.0;  m[3][2] = 0.0; m[3][3] = 1;

		int transformedX, transformedY, transformedZ;

		transformedX = (int) (iso->x * m[0][0] + iso->y * m[0][1] + iso->z * m[0][2] + m[0][3]);
		transformedY = (int) (iso->x * m[1][0] + iso->y * m[1][1] + iso->z * m[1][2] + m[1][3]);
		transformedZ = (int) (iso->x * m[2][0] + iso->y * m[2][2] + iso->z * m[2][2] + m[2][3]);

		iso->x = transformedX;
		iso->y = transformedY;
		iso->z = transformedZ;

}

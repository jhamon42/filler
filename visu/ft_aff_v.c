/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:26:06 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/14 14:39:18 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_filler.h"

static void print_tab(FILE *fd, t_visu *p)
{
	int i;
	int j;

	i = -1;
	while (++i < p->y_map)
	{
		j = -1;
		while (++j < p->x_map)
			fprintf(fd, "%c", p->tb_map[i][j]);
		fprintf(fd, "\n");
	}
}
static void ds_moi_mout(t_visu *p, int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < p->var_y)
	{
		j = -1;
		while (++j < p->var_x)
		{
			mlx_put_pixi(p, (x + j), (y + i), color);
		}
	}
}

void			mlx_put_pixi(t_visu *p, int x, int y, int color)
{
	int		color1;
	int		color2;
	int		color3;
	int		bit_pix;
	float	img_size;

	img_size = p->defwin_x * p->defwin_y * p->bpp / 8;
	if (x < 0 || y < 0 || y * p->sline + x * p->bpp / 8 > img_size
		|| x >= p->sline / (p->bpp / 8) || y >= img_size / p->sline)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = p->bpp / 8;
	p->data[y * p->sline + x * bit_pix] = color1;
	p->data[y * p->sline + x * bit_pix + 1] = color2;
	p->data[y * p->sline + x * bit_pix + 2] = color3;
}

int				my_keys_events(int key, t_visu *p)
{
	ft_printf("%d\n", key);
	if (p)
		;
	if (key == 53)
	{
		fclose(p->fd);
		exit(0);
	}
	return (0);
}

void ft_aff_v(t_visu *p)
{
	int i;
	int j;

	i = -1;
	//usleep(5000);
	while (++i < p->y_map)
	{
		j = -1;
		while (++j < p->x_map)
		{
			if (p->tb_map[i][j] == 'O')
				ds_moi_mout(p, (2 + p->var_x) * j + 2, (2 + p->var_y) * i + 2, 0xFF00FF);
			else if (p->tb_map[i][j] == 'X')
				ds_moi_mout(p, (2 + p->var_x) * j + 2, (2 + p->var_y) * i + 2, 0x00ffff);
			else if (p->tb_map[i][j] == 'o')
				ds_moi_mout(p, (2 + p->var_x) * j + 2, (2 + p->var_y) * i + 2, 0x500050);
			else if (p->tb_map[i][j] == 'x')
				ds_moi_mout(p, (2 + p->var_x) * j + 2, (2 + p->var_y) * i + 2, 0x005050);
		}
	}
	print_tab(p->fd, p);
	fprintf(p->fd, "x_map ; %d, y_map : %d, var_x : %d, var_y : %d\n", p->x_map, p->y_map, p->var_x, p->var_y);
	//ds_moi_mout(p, 10, 10, 0xFFFFFF);
}

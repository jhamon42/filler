/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:26:06 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/15 20:58:57 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_filler.h"

static void	ds_moi_mout(t_visu *p, int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < p->var_y)
	{
		j = -1;
		while (++j < p->var_x)
			mlx_put_pixi(p, (x + j), (y + i), color);
	}
}

void		mlx_put_pixi(t_visu *p, int x, int y, int color)
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

int			my_keys_events(int key, t_visu *p)
{
	if (key == 53)
		exit(0);
	if (key == 49)
	{
		if (p->pause == 0)
			p->pause = 1;
		else if (p->pause == 1)
			p->pause = 0;
	}
	return (0);
}

void		ft_aff_v(t_visu *p)
{
	int i;
	int j;

	i = -1;
	usleep(5000);
	while (++i < p->y_map)
	{
		j = -1;
		while (++j < p->x_map)
		{
			if (p->tb_map[i][j] == 'O')
				ds_moi_mout(p, (2 + p->var_x) * j + 2,
				(2 + p->var_y) * i + 2, 0x5FD813);
			else if (p->tb_map[i][j] == 'X')
				ds_moi_mout(p, (2 + p->var_x) * j + 2,
				(2 + p->var_y) * i + 2, 0x8C13D8);
			else if (p->tb_map[i][j] == 'o')
				ds_moi_mout(p, (2 + p->var_x) * j + 2,
				(2 + p->var_y) * i + 2, 0xB7FF8A);
			else if (p->tb_map[i][j] == 'x')
				ds_moi_mout(p, (2 + p->var_x) * j + 2,
				(2 + p->var_y) * i + 2, 0xD28AFF);
		}
	}
}

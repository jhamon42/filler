/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:04:30 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/13 20:06:18 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_filler.h"

static void		s_visu_init(t_visu *p)
{
	p->rec = 1;
	p->ok = 0;
	p->y_map = 0;
	p->x_map = 0;
	p->tb_map = NULL;
	p->fd = fopen("recup.txt", "w");
}

static void		ft_init_xy(t_visu *p)
{
	p->var_y = 50;
	p->var_x = 50;
	if ((p->defwin_x = (p->x_map * 52) + 2) > 1900)
	{
		printf("ok\n");
		p->var_x = (1900 - (p->x_map * 2 + 2)) / p->x_map;
		p->defwin_x = ((p->x_map * (p->var_x + 2)) + 2);
	}
	if ((p->defwin_y = (p->y_map * 52) + 2) > 1050)
	{
		printf("ok\n");
		p->var_y = (1050 - (p->y_map * 2 + 2)) / p->y_map;
		p->defwin_y = ((p->y_map * (p->var_y + 2)) + 2);
	}
}

static void		ft_init_img(t_visu *p)
{
	p->mlx = mlx_init();
	ft_init_xy(p);
	p->win = mlx_new_window(p->mlx, p->defwin_x, p->defwin_y, "fdf");
	p->img = mlx_new_image(p->mlx, p->defwin_x, p->defwin_y);
	p->data = (unsigned char *)mlx_get_data_addr(p->img, &p->bpp, \
											&p->sline, &p->endian);
}


int			loophere(t_visu *p)
{
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, p->defwin_x, p->defwin_y);
	p->data = (unsigned char *)mlx_get_data_addr(p->img, \
		&p->bpp, &p->sline, &p->endian);
	ft_rec_v(p);
	ft_aff_v(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}

int main(void)
{
	t_visu	visu;
	t_visu	*p;

	p = &visu;
	s_visu_init(p);
	val_tab(p);
	ft_init_img(p);
	ft_rec_v(p);
	ft_aff_v(p);
	mlx_key_hook(p->win, my_keys_events, p);
	mlx_loop_hook(p->mlx, loophere, p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_loop(p->mlx);
	return (0);
}
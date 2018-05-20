/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsv_flr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:39:04 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/19 22:15:45 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				fin_fin(t_filler *p, int a)
{
	p->tour = 0;
	p->ink_i = 0;
	if (a++ == 2)
	{
		p->tour = 0;
		p->ink_i = 0;
		p->y_ink = p->y_ini_me;
		p->x_ink = p->x_ini_me;
	}
	else
	{
		ft_printf("0 0\n");
		a = 0;
	}
	return (a);
}

void			ft_rsv_flr(t_filler *p)
{
	int a;

	a = 1;
	ft_hercul(p);
	(p->y_map > 20 && p->x_map > 20) ? ft_chr_ink(p) : ft_chr_oink(p);
	while (a != 0)
	{
		if (p->y_ply <= -(p->y_map * 2) && p->x_ply <= -(p->x_map * 2))
		{
			a = fin_fin(p, a);
		}
		if (ft_vrf_plac(p))
		{
			a = 0;
			ft_printf("%d %d\n", p->y_ply, p->x_ply);
		}
		else
			ft_iter_ink(p);
	}
	p->tour = 0;
}

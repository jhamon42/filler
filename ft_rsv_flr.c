/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsv_flr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:39:04 by jhamon            #+#    #+#             */
/*   Updated: 2018/05/09 14:08:31 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_rsv_flr(t_filler *p)
{
	int a;

	a = 1;
	ft_hercul(p);
	(p->y_map > 20 && p->x_map > 20) ? ft_chr_ink(p) : ft_chr_oink(p);
	p->tour = 0;
	p->ink_i = 0;
	while (a != 0)
	{
		if (p->y_ply <= -(p->y_map) && p->x_ply <= -(p->x_map))
		{
			ft_printf("%d %d\n", p->y_ply, p->x_ply);
			a = 0;
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

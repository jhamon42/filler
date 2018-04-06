/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsv_flr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamon <jhamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:39:04 by jhamon            #+#    #+#             */
/*   Updated: 2018/04/06 06:27:23 by jhamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_rsv_flr(t_filler *p)
{
	ft_hercul(p);
	fprintf(p->fd_trace, "phase : %d ink_x: %d ink_y: %d\n", p->phase, p->x_ink, p->y_ink);
	ft_chr_ink(p);
	int a;
	a = 1;
	fprintf(p->fd_trace, "\n");
	p->tour = 0;
	p->ink_i = 0;
	while (a != 0)
	{
		if (ft_vrf_plc(p))
		{
			a = 0;
			ft_printf("%d %d\n", p->y_ply, p->x_ply);
		}
		else
			ft_iter_ink(p);
		if (p->y_ply <= -(p->y_map) && p->x_ply <= -(p->x_map))
		{
			ft_printf("%d %d\n", p->y_ply, p->x_ply);
			a = 0;
		}
	}
	p->tour = 0;
}
